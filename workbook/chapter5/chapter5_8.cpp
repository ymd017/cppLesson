#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

/*
* 問題文：
* int型の15つの要素数を持つ配列の全要素に0~10の乱数を代入する
* 縦方向の棒グラフで値を表示する。棒グラフは'*'を並べて表示する。
* 最下段に添字を10で割った剰余を表示する。
*/

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 配列の要素数を定義する
	const int n = 15;

	// 要素数がint型で、要素数15個の配列のメモリを確保する
	int a[n];

	srand(time(NULL));

	// for文で先頭から最後まで走査する
	// 0~10の乱数を代入する
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 11;
	}

	// '*'を用いて、縦方向の棒グラフで値を表示する。
	// 行列を使用するので、forのネストを用いる。
	// 列のforのカウンターは各要素の値で、10~1まで走査する。値が0の時は出力しないので1まで。
	// 行のforのカウンターは各要素のインデックスで、0~15まで走査する
	for (int i = 10; i >= 1; i--) {		// 下から'*'を積み上げていくので、値の大きいほうから出力していく。

		for (int j = 0; j < n; j++) {

			// 配列要素の値が行列の成分が示す値以上であれば'*'を表示し、そうでなければ' 'を表示する。
			// 出力の際は成形のためにsetw(2)を用いる
			if (a[j] >= i) {
				cout << setw(2) << '*';
			}
			else {
				cout << setw(2) << ' ';
			}
		}

		// 列が終端までいったら、改行する
		cout << "\n";
	}

	// 区切りのラインを表示する
	for (int i = 0; i < n * 2; i++) {
		cout << '-';
	}
	cout << "\n";

	
	// インデックスを10で割った剰余を表示する
	for (int i = 0; i < n; i++) {
		cout << setw(2) << i % 10;
	}
	cout << "\n\n";

	//各要素の値確認のための出力
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
}
