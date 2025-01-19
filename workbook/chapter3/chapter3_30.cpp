/*
* 問題文：
* 0~9の数字文字を循環的に、1行に1文字ずつ表示するプログラムを作成せよ。
* 行が進むたびに表示位置を1文字分ずつ右にずらした表示を行うこと。
*/

#include <iostream>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	/*
	* 0から指定回数に到達するまで、for文で反復処理をする。
	* iを%10で割ることで0~9の数字にする。
	* スペースの表示数はiと同値。
	*/

	// 変数宣言部
	int n;		// 表示回数
	int i;		// ループインデック
	int j;		// ループインデック

	// 表示回数を入力する
	cout << "表示回数を入力してください\n";
	cin >> n;

	// for文でiを0から指定回数-1まで走査する。
	// iの各回において、スペースを出力する。表示数はiと同値。
	// iの各回において、iを%10で割ることで0~9の数字にし、出力する。
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			cout << ' ';
		}
		cout << i % 10 << "\n";

	}
}