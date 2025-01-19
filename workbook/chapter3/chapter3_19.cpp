/*
* 問題文：
* 月を1~12の整数値として読み込んで、それに対応する季節を表示するプログラムを作成せよ。
* 月の読み込みにおいて、1~12以外の数値が入力された場合は再入力させること。
* また、好きなだけ何度でも入力・表示できるようにすること。
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
	int inputFlg;
	int retryFlg;
	string season;

	do {
		// 月の入力
		do {
			// 入力のさせ直しフラグの初期化
			inputFlg = 0;

			cout << "月を入力してください\n";
			cin >> month;

			if (month < 1 || month > 12) {
				cout << "1から12までの整数値を入力してください。\n";
				inputFlg = 1;
			}
		} while (inputFlg == 1);

		// 月に対応する季節を表示する
		switch (month) {
		case 3: case 4: case 5:
			cout << month << "は春です。";
			break;
		case 6: case 7: case 8:
			cout << month << "は夏です。";
			break;
		case 9: case 10: case 11:
			cout << month << "は秋です。";
			break;
		case 12: case 1: case 2:
			cout << month << "は冬です。";
			break;
		}

		// もう一度やるか判定し、フラグに格納する
		cout << "もう一度やりますか？(1で続行、0で終了)\n";
		cin >> retryFlg;

	} while (retryFlg == 1);

}