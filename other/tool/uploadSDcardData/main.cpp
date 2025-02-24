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
using namespace std;
namespace fs = std::filesystem;

/*=============================================================================
* アップロード先の場所の取得
* 引数　：
* 戻り値：string		// アップロード先の場所のパス
=============================================================================*/
string getUploadPath() {
	// アップロード先の場所が書いてあるファイルを開く
	ifstream file("uploadPath.txt");

	if (!file) {
		cout << "アップロード先が書かれているファイルが開けませんでした。";
	}

	// アップロード先の場所を取得する
	string path;
	getline(file, path);
	path += "\\";

	return path;
}

/*=============================================================================
* SDカードのドライブを検出
* 引数　：
* 戻り値：string		// SDカードドライブのパス
=============================================================================*/
string detectSDCardDrive() {
	// 全ての論理ドライブを検出、論理ドライブがあれば１のビットマスクを返す
	DWORD drives = GetLogicalDrives();

	//cout << bitset<32>(drives);

	// 各論理ドライブの種類を特定する
	//cout << GetDriveTypeA("H:/");
	for (char i = 'A'; i <= 'Z'; i++) {

		if (drives & (1 << (i - 'A'))) {		// 調べているドライブのビットマスクが1であれば

			// ドライブパスの生成
			string drivePath = string(1, i) + ":\\";

			// ドライブの種類を調べる
			UINT driveType = GetDriveTypeA(drivePath.c_str());

			// ドライブの種類がリムーバブルメディアか調べる
			if (driveType == DRIVE_REMOVABLE) {

				// リムーバブルメディア(SDカード, USB)のドライブのパスを返却する
				return drivePath;
			}
		}
	}
}

/*=============================================================================
* SDカードのrawファイルのあるフォルダを検出
* 引数　：
* 戻り値：
=============================================================================*/
vector<string> detectRawFolders() {
	vector<string> rawFolders;
	unordered_set<string> checkedFolders;

	// 再帰的(フォルダの中のフォルダも全て)に全てのファイルを走査する
	for (const fs::directory_entry& x : fs::recursive_directory_iterator("H:\\")) {

		// 拡張子がRAWまたはCR2であった場合、親フォルダのパスを取得する
		if ((x.path().extension() == ".RAW") || (x.path().extension() == ".CR2")) {
			string parentPath = x.path().parent_path().string();

			// 親フォルダが既にリストに追加されていないかを調べる
			if (checkedFolders.contains(parentPath) == false) {
				// まだリストになければ追加する
				checkedFolders.insert(parentPath);
				rawFolders.push_back(parentPath);
			}
		}
	}
	return rawFolders;
}


/*=============================================================================
* アップロード先の場所に今日の日付のフォルダを作成する
* 引数　：
* 戻り値：
=============================================================================*/
string createDateFolder(string uploadPath) {
	auto now = chrono::system_clock::now();
	string today = format("{:%Y%m%d}", now);

	string folderPath = uploadPath + today;
	fs::create_directory(folderPath);

	return folderPath;
}

/*=============================================================================
* 日付フォルダの中に、raw, rc, tiff, modelフォルダを作成する
* 引数　：
* 戻り値：
=============================================================================*/
void createFolders(string folderPath) {
	fs::create_directory(folderPath + "\\raw");
	fs::create_directory(folderPath + "\\rc");
	fs::create_directory(folderPath + "\\tiff");
	fs::create_directory(folderPath + "\\model");
}


/*=============================================================================
* rawフォルダのファイルをアップロード先の場所にアップロードする
* 引数　：
* 戻り値：
=============================================================================*/

int main() {

	// アップロード先の場所の取得
	string uploadPath = getUploadPath();

	// SDカードを検出する
	string drivePath = detectSDCardDrive();

	// アップロード先に日付フォルダの作成
	string dateFolderPath = createDateFolder(uploadPath);

	// 日付フォルダの中にraw,rc,tiff,modelフォルダの作成
	createFolders(dateFolderPath);

	// SDカードのrawファイルのあるフォルダを検出
	vector<string> rawFolders = detectRawFolders();

	// 要素2個目以降はフォルダ名を変えるようにしないといけない（後で）
	//for (string rawFolder : rawFolders) {}
	string rawFolder = rawFolders[0];




	

}
