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
	int rangeMin;
	int rangeMax;
	int rangeStep;
	int height;
	int weight;

	// 表示する身長の範囲（開始値、終了値、増分）の入力
	cout << "表示する身長の開始値：";
	cin >> rangeMin;
	cout << "表示する身長の終了値：";
	cin >> rangeMax;
	cout << "表示する身長の増分：";
	cin >> rangeStep;

	cout << "-------------------------------------\n";

	// 身長と標準体重を表示する
	// 表の項目名を出力する
	// for文で身長heightを入力した開始値から終了値まで、ステップの数だけ増やしながら走査する。
	// 各回でその回の身長の値に対応した標準体重を求める
	// 身長と標準体重を表の形で出力する。

	cout << setw(10) << "身長" << setw(10) << "標準体重" << "\n";

	for (height = rangeMin; height <= rangeMax; height += rangeStep) {

		weight = (height - 100) * 0.9;

		cout << setw(10) << height << setw(10) << weight << "\n";
	}


}