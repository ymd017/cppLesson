/*
* 問題文：
* 身長と体重の対応表を表示するプログラムを作成せよ。
* 表示する身長の範囲（開始値、終了値、増分）は、整数値として読み込むこと。
* 5個表示するごとに改行すること。
* ※標準体重は（身長-100) × 0.9
*/

#include <iostream>
#include <iomanip>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	int height;
	double weight;
	int height_start;	// 身長表示の開始値
	int height_last;	// 身長表示の終了値
	int height_step;	// 身長表示の増分
	int outCount = 0;	// 出力した個数

	// 身長開始値と終了値、増分を入力する
	cout << "表示する身長の開始値:";
	cin >> height_start;

	cout << "表示する身長の終了値:";
	cin >> height_last;

	cout << "表示する身長の増分:";
	cin >> height_step;

	// 表を出力する
	// for分で身長開始値から、終了値まで、入力増分だけ増やして走査する
	// ↑各for文の回で、身長を表示する。また、標準体重を求めて出力する。
	// ↑各for文の回で、出力した個数をカウントし、5の倍数になった時、改行を入れる。
	for (height = height_start; height < height_last; height += height_step) {

		weight = (height - 100) * 0.9;

		cout << setw(4) << height << setw(8) << weight << "\n";
		
		outCount++;
		if ((outCount % 5) == 0) {
			cout << "\n";
		}

	}
}