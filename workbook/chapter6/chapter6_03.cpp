#include <iostream>
using namespace std;

/*
* 問題文：
* 3つのint型引数a,b,cの中央値を求める関数medを作成せよ
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

	// 中央値を求める関数minを使用する
	// 結果を出力する
	cout << "中央値は" << min(a, b, c) << "です。\n";

}

/*============================================================
* 3つの整数を受け取り、中央値を返却する関数
* 引数　：int a			判定に用いる変数1
* 引数　：int b			判定に用いる変数2
* 引数　：int c			判定に用いる変数3
* 戻り値：int			中央値
============================================================*/
int min(int a, int b, int c) {

	// 最小値を格納する変数の宣言
	int med;

	// aとbの大小関係が確定している状態で、cがどこに入るかで場合分けをする
	if (a < b) {
		if (c < a) {
			return a;
		}
		else if (b < c) {
			return b;
		}
		else {
			return c;
		}
	}
	else {	// b < a
		if (c < b) {
			return b;
		}
		else if (a < c){
			return a;
		}
		else {
			return c;
		}
	}

	// 中央値を返却する
	return med;
}
