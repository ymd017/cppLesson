/*
* 問題文：
* 1からnまでの整数値の2乗値を表示するプログラムを作成せよ。
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
	int n;		// 1からnまでの整数値の2乗値を表示するのに使用
	int i;		// ループインデックス

	// 1からnまでの整数値の2乗値を表示するのに使用するnの入力
	cout << "1からいくつまでの整数値の2乗値を表示しますか：";
	cin >> n;
	cout << "\n";

	// for文で1からnまで走査する
	// 整数値の2乗を表示する
	for (i = 1; i <= n; i++) {
		cout << i << "の2乗：　" << i * i << "\n";
	}
}