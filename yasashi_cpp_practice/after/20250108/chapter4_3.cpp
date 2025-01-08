#include <iostream>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	int sub;
	int sum = 0;
	double avg;
	
	//教科数を入力する
	cout << "教科数を入力してください。\n";
	cin >> sub;

	//テストの点数を格納する配列を宣言する
	//動的な配列を用いる
	int* test = new int[sub];

	//繰り返し処理で、配列に全教科のテストの点数を格納していく
	for (int i = 0; i < sub; i++) {
		cout << "科目" << i + 1 << "の点数を入力してください。\n";
		cin >> test[i];
	}

	//合計点を求める
	for (int i = 0; i < sub; i++) {
		sum += test[i];
	}

	//平均点を求める
	avg = static_cast<double>(sum) / static_cast<double>(sub);

	//結果の出力
	//合計点と平均点を文字列結合して出力する
	cout << sub << "科目の合計点は" << sum << "点です。\n";
	cout << sub << "科目の平均点は" << avg << "点です。\n";
}
