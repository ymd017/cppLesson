/*
* 問題文：
* 月を1~12の整数値として読み込んで、それに対応する季節を表示するプログラムを作成せよ。
*/

#include <iostream>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	int month;
	string season;

	// 月を入力する
	cout << "月を入力してください。\n";
	cin >> month;

	// 出力する季節をseasonに格納する
	switch (month) {
	case 3: case 4: case 5:
		season = "春";
		break;
	case 6: case 7: case 8:
		season = "夏";
		break;
	case 9: case 10: case 11:
		season = "秋";
		break;
	case 12: case 1: case 2:
		season = "冬";
		break;
	}

	// 出力する
	cout << month << "月は" << season << "です。\n";
}