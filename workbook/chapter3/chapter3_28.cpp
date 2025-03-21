/*
* 問題文：
* キーボードから次々と整数値を読み込んで、合計と平均を求めるプログラムを作成せよ。
* なお、合計1000を超えない範囲で読み込みと加算を行うようにすること。
* 0以上の値のみを加算するようにし、読み込んだ負の個数は平均を求める際には除外すること。
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
	double avg;		// 平均
	int sum;		// 合計
	int num;		// 合計と平均を求めるのに使用する入力された整数値
	int count;		// 加算した整数の個数
	int i;			// ループインデック

	// do while文内で、整数値の入力をし、合計に加えていく。
	// ↑この時、入力の整数値が負である場合は加算しない。countも増やさない。
	// 合計が1000を超えたら、反復処理を終了する。
	sum = 0;
	count = 0;

	do {
		cout << "加算する整数を入力してください。\n";
		cin >> num;

		if (num >= 0) {
			sum += num;
			count++;
		}
		else {
			cout << num << "は負の数なので加算しません。\n";
		}

	} while (sum < 1000);

	// 平均を求める
	avg = static_cast<double>(sum) / static_cast<double>(count);

	// 結果を出力する
	cout << "合計： " << sum << "\n";
	cout << "平均： " << avg << "\n";
}