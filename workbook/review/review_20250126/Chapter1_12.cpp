/*
* 問題文：
*　キーボードから読み込んだ整数値の最下位桁を表示するプログラムを作成せよ
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
	int num;		// 読み込んだ数値
	int lastDigit;	// 最下位桁

	// キーボードから整数値を読み込む
	cout << "整数を入力してください\n";
	cin >> num;

	// 最下位桁を求める
	lastDigit = num % 10;

	// 最下位桁を表示する
	cout << "最下位桁は" << lastDigit << "です。\n";
}