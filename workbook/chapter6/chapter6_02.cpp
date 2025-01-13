#include <iostream>
using namespace std;

/*
* 問題文：
* 3つのint型引数a,b,cの最小値を求める関数minを作成せよ
*/

int min(int a, int b, int c);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 3つのint型変数を宣言する
	int a, b, c;

	// 3つのint型の値を変数に代入する
	cout << "整数を3つ入力してください\n";
	cin >> a >> b >> c;

	// 最小値を求める関数minを使用する
	// 結果を出力する
	cout << "最小値は" << min(a, b, c) << "です。\n";

}

/*============================================================
* 3つの整数を受け取り、最小値を返却する関数
* 引数　：int a			判定に用いる変数1
* 引数　：int b			判定に用いる変数2
* 引数　：int c			判定に用いる変数3
* 戻り値：int			最小値
============================================================*/
int min(int a, int b, int c) {

	// 最小値を格納する変数用意する。初期値はaにする。
	int min = a;

	// 今の最小値よりも値が小さいときは、変数の値を更新する
	if (min > b) {
		min = b;
	}

	if (min > c) {
		min = c;
	}

	//最小値を返却する
	return min;
}
