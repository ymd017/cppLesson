/*
*SDカードのrawファイルを指定サーバーの場所にフォルダを作ってアップロードする
*/

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <fileapi.h>
#include <filesystem>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <format>
#include <stdexcept>
// #define TEST_MODE
using namespace std;
namespace fs = std::filesystem;

/*=============================================================================
* アップロード先の場所の取得する
* 引数　：string& uploadPath	// アップロード先の場所のパス
* 戻り値：void					// 有効なパスを取得したときはtrue、それ以外はfalse
=============================================================================*/
void getUploadPath(string& uploadPath) {

	// 変数宣言部
	string path;		// アップロード先の場所（一時保存用）
	string drive;		// ドライブのパス
	size_t delimiterPos;	// 区切り文字の位置

	// アップロード先の場所が書いてあるファイルを開く
	ifstream file("uploadPath.txt");

	if (!file) {
		throw runtime_error("アップロード先が書かれているファイルが開けませんでした。");
	}

	// アップロード先の場所を取得する
	getline(file, path);
	path += "\\";

	// アップロード先のドライブが存在するのか調べる
	delimiterPos = path.find(":");

	if (delimiterPos == string::npos) {		// 論理ドライブの:がない場合はエラーを出力して処理を終わらせる
		throw runtime_error("アップロード先のパスが無効です。論理ドライブの「:」がありません");
	}

	drive = path.substr(0, delimiterPos + 1);
	if (!fs::exists(drive)) {
		throw runtime_error("アップロード先に指定されているドライブは存在しません");
	}

	// アップロード先の場所が存在するのか調べる
	// 存在しない場合はドライブにフォルダを作成する
	if (!fs::exists(path)) {
		fs::create_directories(path);
	}

	// 引数をアップロード先の場所に書き換える
	uploadPath = path;
}

/*=============================================================================
* SDカードのドライブを検出
* 引数　：string		// SDカードドライブのパス
* 戻り値：void
=============================================================================*/
void detectSDCardDrive(string& drivePath) {
	// 全ての論理ドライブを検出、論理ドライブがあれば１のビットマスクを返す
	DWORD drives = GetLogicalDrives();

	// 各論理ドライブの種類を特定する
	for (char i = 'A'; i <= 'Z'; i++) {

		if (drives & (1 << (i - 'A'))) {		// 調べているドライブのビットマスクが1であれば

			// ドライブパスの生成
			string path = string(1, i) + ":\\";

			// ドライブの種類を調べる
			UINT driveType = GetDriveTypeA(path.c_str());

			// ドライブの種類がリムーバブルメディアか調べる
			// リムーバブルメディアであった場合は、
			// 引数をリムーバブルメディア(SDカード, USB)のドライブのパスで書き換える。
			if (driveType == DRIVE_REMOVABLE) {
				drivePath = path;
				return;
			}
		}
	}

	// 1つもリムーバブルメディアがなかった場合はエラーにする
	throw runtime_error("リムーバブルメディア(SDカード, USB)がありません。");
}

/*=============================================================================
* SDカードのrawファイルのあるフォルダを検出
* 引数　：string& drivePath				// SDカードドライブのパス
* 引数　：vector<string>& rawFolders	// SDカード内のrawファイルのあるフォルダのパス
* 戻り値：void
=============================================================================*/
void detectRawFolders(const string& drivePath, vector<string>& rawFolders) {
	unordered_set<string> checkedFolders;

	// 再帰的(フォルダの中のフォルダも全て)に全てのファイルを走査する
	for (const fs::directory_entry& x : fs::recursive_directory_iterator(drivePath)) {

		// 拡張子がRAWまたはCR2であった場合、親フォルダのパスを取得する
		string ext = x.path().extension().string();

		string extLower;
		transform(ext.begin(), ext.end(), back_inserter(extLower), ::tolower);

		if (extLower == ".raw" || extLower == ".cr2") {
			string parentPath = x.path().parent_path().string();

			// 親フォルダが既にリストに追加されていないかを調べる
			if (!checkedFolders.contains(parentPath)) {
				// まだリストになければ追加する
				checkedFolders.insert(parentPath);
				rawFolders.push_back(parentPath);
			}
		}
	}

	if (rawFolders.empty()) {
		throw runtime_error("リムーバブルメディアにrawファイルが見つかりませんでした。");
	}
}


/*=============================================================================
* アップロード先の場所に今日の日付のフォルダを作成する
* 引数　：const string& uploadPath		// アップロード先のパス
* 引数　：string& dateFolderPath		// アップロード先に作成する今日の日付フォルダ
* 戻り値：void
=============================================================================*/
void createDateFolder(const string& uploadPath, string& dateFolderPath) {

	// 変数宣言部
	string today;
	string temp;		// 処理過程で使用するdateFolderPath
	string temp2;		// 処理過程で使用するdateFolderPath

	// 今日の日付のフォルダのパスを作る
	auto now = chrono::system_clock::now();
	today = format("{:%Y%m%d}", now);
	temp = uploadPath + today;

	// 既に今日の日付のフォルダがないか確認する
	// 存在していない場合は今日の日付のフォルダを作る&フォルダパスを返却する
	// 存在している場合は連番を付ける
	if (!fs::exists(temp)) {
		dateFolderPath = temp;
		fs::create_directory(dateFolderPath);
	}
	else {
		size_t i = 1;
		while (true) {
			// 連番付きのパスの作成
			temp2 = format("{}_{}", temp, i);

			// 連番付きパスがすでに存在していないかを調べる
			// 存在していないなら、そのパスをフォルダーパスとしフォルダを作る&フォルダパスを返却する
			// 存在している場合はi++して、whileループを続ける
			if (!fs::exists(temp2)) {
				dateFolderPath = temp2;
				fs::create_directory(dateFolderPath);
				return;
			}
			else {
				i++;
			}
		}
	}

}

/*=============================================================================
* SDカードのraw画像をアップロード先のrawフォルダにコピーする
* 引数　：const vector<string>& rawFolders		// SDカード内のrawのあるフォルダのパス
* 引数　：const string dateFolderPath			// アップロード先に作成する今日の日付フォルダ
* 戻り値：void
=============================================================================*/
void uploadRaw(const vector<string>& rawFolders, const string dateFolderPath) {

	// 変数宣言部
	string uploadRawPath;		// アップロード先のrawフォルダのパス

	// SDカードのraw画像をアップロード先のrawフォルダにコピーする
	for (size_t i = 0; i < rawFolders.size(); i++) {
		uploadRawPath = format("{}\\raw{}", dateFolderPath, (i == 0 ? "" : format("{}", i)));

		// rawフォルダのファイルをアップロード先の場所にアップロードする
		try {
			fs::copy(rawFolders[i], uploadRawPath, fs::copy_options::recursive);
		}
		catch (fs::filesystem_error& err) {
			throw runtime_error("ファイルコピーエラー：" + string(err.what()));
		}
	}
}

/*=============================================================================
* 日付フォルダの中に、rc, tiff, modelフォルダを作成する
* 引数　：const string& dateFolderPath	// アップロード先の今日の日付フォルダ
* 戻り値：void
=============================================================================*/
void createFolders(const string& dateFolderPath) {

	vector<string> folderNames = { "rc", "tiff", "model" };

	for (string folderName : folderNames) {
		fs::create_directory(dateFolderPath + "\\" + folderName);
	}
}

/*=============================================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
=============================================================================*/
int main() {

#ifdef TEST_MODE

#else
	// 変数宣言部
	string uploadPath;			// アップロード先のパス
	string drivePath;			// SDカードのドライブのパス
	string dateFolderPath;		// 日付フォルダのパス
	vector<string> rawFolders;	// rawファイルがあるフォルダのパス

	try {
		// アップロード先の場所の取得
		getUploadPath(uploadPath);

		// SDカードを検出する
		detectSDCardDrive(drivePath);

		// SDカードのrawファイルのあるフォルダを検出
		detectRawFolders(drivePath, rawFolders);

		// アップロード先に日付フォルダの作成
		createDateFolder(uploadPath, dateFolderPath);

		// SDカードのraw画像をアップロード先のrawフォルダにコピーする
		uploadRaw(rawFolders, dateFolderPath);

		// 日付フォルダの中に、rc, tiff, modelフォルダを作成する
		createFolders(dateFolderPath);

		cout << "SDカード内のデータのアップロードが終了しました。\n";
		cin.get();
	}
	catch (const exception& err) {
		cout << "[ERROR] " << err.what() << "\n";
		cin.get();
	}

	return 0;
#endif
}
