/*
* 問題文：
* 読み込んだ値の個数だけ記号文字を表示するプログラムを作成せよ。
* 表示は+と-を交互に行うこと。最後に改行文字を出力すること。
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
	int num;		// 入力された個数
	int sign;		// 表示する符号（記号）。0が+で、1が-
	int i;			// ループインデックス

	// 個数の入力
	cout << "表示する個数を入力してください\n";
	cin >> num;

	// signの初期化
	sign = 0;

	// for文で入力個数分、記号を表示する
	// signが0なら＋、1ならーを表示する
	// 一度表示するたびに今とは逆の0、１を代入する
	for (i = 0; i < num; i++) {

		if (sign == 0) {
			cout << '+';
			sign = 1;
		}
		else { // sign == 1
			cout << '-';
			sign = 0;
		}
	}

}
