/*
* 問題文：
* 読み込んだ整数値の符号を返すプログラムを作成せよ。
* 何度でも入力と表示がされること。
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
	int num;		// 読み込んだ整数値
	char retryChar;		// 反復するかどうかの入力
	char retryFlg;		// 反復処理のフラグ

	do {
		// 反復処理フラグのリセット
		retryFlg = 0;

		// 整数値の入力
		cout << "整数値を入力してください\n";
		cin >> num;

		// 符号を判定して、出力する
		if (num > 0) {
			cout << "その値は正です。\n";
		}
		else if (num < 0) {
			cout << "その値は負です。\n";
		}
		else {
			cout << "その値は0です。\n";
		}

		// 繰り返すかどうかを入力させる
		// 反復処理するかの判定をする
		do {
			cout << "もう一度やりますか(y：やる　/　n：やらない)\n";
			cin >> retryChar;

			if (retryChar == 'y' || retryChar == 'Y') {
				retryFlg = 1;
			}

		} while (retryChar != 'y' && retryChar != 'Y'
			&& retryChar != 'n' && retryChar != 'N');		// 入力がy, Y, n, N以外なら入力させ直す

	} while (retryFlg == 1);			// フラグが'y'か'Y'なら繰り返す
}