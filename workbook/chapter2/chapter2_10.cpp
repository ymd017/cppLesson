/*
* 問題文：
* 2つの整数値を読み込んで、それらの値の差を表示するプログラムを作成せよ
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
	int diff;
	int num1;
	int num2;

	// 数値の入力
	cout << "整数を2つ入力してください。\n";
	cin >> num1 >> num2;

	// 差を求める
	diff = num1 - num2;

	// 差がマイナスだったら、プラスにする
	if (diff < 0) {
		diff *= -1;
	}

	// 差の大きさを見て、結果を出力する
	if (diff <= 10) {
		cout << "それらの差は10以下です。\n";
	}
	else {
		cout << "それらの差は11以上です。\n";
	}

}