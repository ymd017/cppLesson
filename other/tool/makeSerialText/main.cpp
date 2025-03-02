/*
* 連番文字列を作成する
* $の後に続く数字を連番にする
*/

#include <iostream>
#include <string>
#include <exception>
#include <cctype>
// #define TEST_MODE;
using namespace std;

/*=============================================================================
* 連番付き文字列のフォーマットを入力させる
* 引数　：string& formatStr		// 連番を含む文字列生成のためのフォーマット
* 戻り値：size_t idx			// $のある位置のインデックス
=============================================================================*/
size_t inputFormat(string& formatStr) {

	cout << "フォーマットを入力してください。\n";
	cout << "※ 連番を入れたい箇所に $ を入れてください。\n";
	cout << "※ 例：exsempleStage_floor$_Alb.png → exsempleStage_floor1_Alb.png\n\n";
	cin >> formatStr;
	cout << "\n";

	// $があるか調べる
	// ない場合はエラーを出力する
	size_t idx = formatStr.find('$');

	if (idx == formatStr.npos) {
		throw runtime_error("$がないので、連番付きの文字列を生成できませんでした。\n");
	}

	return idx;
}

/*=============================================================================
* 引数の文字列が数字かどうか調べて、問題なければ数字を返却する関数。
* 引数　：const string str		// 数字かどうか調べる文字列
* 戻り値：size_t startNum		// 連番の始まりの数字
=============================================================================*/
size_t checkInput(const string str) {

	// 変数宣言部
	size_t number;

	// 入力があるかどうか調べる
	// から文字列の場合はエラーにする
	if (str.empty()) {
		throw runtime_error("入力がなかったので、連番付きの文字列を生成できませんでした。\n");
	}

	// 整数以外が入力されていないか調べる
	// 整数以外の入力があった場合はエラーにする
	for (char c : str) {
		if (!isdigit(c)) {
			throw runtime_error("数値以外の文字が入力されたので、連番付きの文字列を生成できませんでした。\n");
		}
	}

	// 文字列を整数に変換する
	number = stoi(str);

	// 連番の始まりの数字を返却する
	return number;
}


/*=============================================================================
* 連番の始まりの数字を入力させる
* 引数　：なし
* 戻り値：size_t startNum		// 連番の始まりの数字
=============================================================================*/
size_t inputStartNum() {

	// 変数宣言部
	string input;
	size_t startNum;

	// 連番の始まりの数字の入力
	cout << "連番の始まりの数字を入力してください。\n";
	cin >> input;
	cout << "\n";

	startNum = checkInput(input);

	// 連番の始まりの数字を返却する
	return startNum;
}


/*=============================================================================
* 連番の終わりの数字を入力させる
* 引数　：size_t startNum			// 連番の始まりの数字
* 戻り値：size_t finNum				// 連番の終わりの数字
=============================================================================*/
size_t inputFinNum(size_t startNum) {

	// 変数宣言部
	string input;
	size_t finNum;

	// 連番の終わりの数字の入力
	cout << "連番の終わりの数字を入力してください。\n";
	cin >> input;
	cout << "\n";

	finNum = checkInput(input);

	// 始まりの数字よりも、終わりの数字が大きいか調べる
	if (finNum <= startNum) {
		throw runtime_error("連番の数字の範囲が不正です。\n");
	}

	// 連番の始まりの数字を返却する
	return finNum;
}


/*=============================================================================
* 連番の終わりの数字を入力させる
* 引数　：size_t startNum		// 連番の始まりの数字
* 引数　：size_t finNum			// 連番の終わりの数字
* 戻り値：なし
=============================================================================*/
void outputSerealNum(size_t startNum, size_t finNum, size_t idx, const string& formatStr) {

	cout << "\n----------------------------------------------\n";
	
	// forでカウントしながら、$の文字をカウントに書き換える
	for (size_t i = startNum; i <= finNum; ++i) {
		cout << formatStr.substr(0, idx) << i << formatStr.substr(idx + 1) << "\n";
	}
}


/*=============================================================================
* $の位置に数字を入れて、出力する
* 引数　：なし
* 戻り値：なし
=============================================================================*/
int main() {

#ifdef TEST_MODE

#else
	try {
		// 変数宣言部
		size_t idx;
		size_t startNum;
		size_t finNum;
		string formatStr;

		cout << "連番を含む文字列を出力します。\n\n";

		// 連番付き文字列のフォーマットを入力させる
		idx = inputFormat(formatStr);

		// 連番の始まりの数字を入力させる
		startNum = inputStartNum();

		// 連番の終わりの数字を入力させる
		finNum = inputFinNum(startNum);

		// $の位置に数字を入れて、出力する
		outputSerealNum(startNum, finNum, idx, formatStr);
		cin.get();
	}
	
	catch (const exception& err) {
		cout << "[ERROR] : " << err.what() << "\n";
		cin.get();
	}

#endif
}
