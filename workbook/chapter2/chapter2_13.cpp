/*
* 問題文：
* 2つの整数値を読み込んで、小さいほうの値と大きいほうの値の両方を表示するプログラムを作成せよ。
* ただし、2つの整数値が同じ場合は「2つの整数値は同じです。」と表示すること。
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
	int med;
	int num1;
	int num2;

	// 数値の入力
	cout << "整数を2つ入力してください。\n";
	cin >> num1 >> num2;

	// 大小の比較をして出力する
	if (num1 > num2) {
		cout << "大きいほうの値は " << num1 << " です\n";
		cout << "小さいほうの値は " << num2 << " です\n";
	}
	else if (num2 > num1) {
		cout << "大きいほうの値は " << num2 << " です\n";
		cout << "小さいほうの値は " << num1 << " です\n";
	}
	else {
		cout << "2つの整数値は同じです。\n";
	}
}