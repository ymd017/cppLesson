#include <iostream>
using namespace std;

/*
* 問題文：
* int x = 1, int y = 2 とする。
* 参照変数aをxで初期化しcoutで出力せよ。
* その後にaにyを代入してから、再びcoutで出力せよ。
*/

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	int x = 1;
	int y = 2;

	// xとyの出力
	cout << "x = " << x << "\n";
	cout << "y = " << y << "\n";

	// aの初期化
	int& a = x;

	cout << "xで初期化した後のa：" << a << "\n";

	// aの代入
	a = y;

	cout << "yを代入した後のa：" << a << "\n";

}