/*
* 問題文：
* 3つのint型引数a,b,cの中央値を求める関数medを作成せよ
*/

#include <iostream>
using namespace std;

int med(int a, int b, int c);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	int medNum;
	int a;
	int b;
	int c;

	// 3つの整数値の入力
	cout << "3つの整数を入力してください\n";
	cin >> a >> b >> c;

	// 3つのint型引数a,b,cの中央値を求める関数の使用
	medNum = med(a, b, c);

	// 中央値の出力
	cout << "中央値:" << medNum << "\n";

}

/*============================================================
* メイン関数
* 引数　：int a		中央値を求めるのに使用する整数値
* 引数　：int b		中央値を求めるのに使用する整数値
* 引数　：int c		中央値を求めるのに使用する整数値
* 戻り値：int		中央値
============================================================*/
int med(int a, int b, int c) {

	// 変数宣言部
	int medNum;

	// あと一つ位置が決まれば、大小関係の位置が確定する状況にする
	// 各状況での中央値をmedに格納する
	if (a < b) {
		if (c < a) {
			medNum = a;
		}
		else if (b < c) {
			medNum = b;
		}
		else {
			medNum = c;
		}
	}
	else {	// b < a;
		if (c < b) {
			medNum = b;
		}
		else if (a < c) {
			medNum = a;
		}
		else {
			medNum = c;
		}
	}

	// 中央値を返却する
	return medNum;
}