/*
* 問題文：
* キーボードから読み込んだ3つの整数値の中央値を求めて表示するプログラムを作成せよ
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
	int num3;

	// 数値の入力
	cout << "整数を3つ入力してください。\n";
	cin >> num1 >> num2 >> num3;

	// 中央値を求める
	// 場合分けをし、大小の順番があと１つきまれば、並び順が確定する状況にする。
	// 残りをどこに入れるかで場合分けする。
	if (num 1 < num2) {
		if (num3 < num1) {
			med = num1;
		}
		else if (num2 < num3) {
			med = num2;
		}
		else {
			med = num3;
		}
	}
	else {					// num2 <= num1
		if (num3 < num2) {
			med = num2;
		}
		else if (num1 < num3) {
			med = num1;
		}
		else {
			med = num3;
		}
	}

	// 中央値の出力
	cout << "中央値は" << med << "です。\n";

}