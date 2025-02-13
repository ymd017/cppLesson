/*
* 問題文：
* int型配列の要素の並びを反転する関数を作成せよ
*/

#include <iostream>
using namespace std;

void reverse(int a[], int n);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	const int n = 10;
	int a[n];
	int i;		// ループインデックス

	// 配列に要素を代入する
	for (i = 0; i < n; i++) {
		a[i] = i;
	}

	// 並びを反転させる前の配列を出力する
	for (i = 0; i < n; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}

	// 配列の並びを反転させる関数の使用
	reverse(a, n);
	cout << "\n配列の並びを反転させました。\n";

	// 並びを反転させた後の配列を出力する
	for (i = 0; i < n; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
}

/*============================================================
* int型配列の要素の並びを反転する関数
* 引数　：int a[]		要素の並びを反転させる配列
* 引数　：int n			配列の要素数
* 戻り値：なし
============================================================*/
void reverse(int a[], int n) {

	// 変数宣言部
	int i;		// ループインデックス
	int temp;	// 値を一時的に避難するのに使用する変数

	// 配列の並びを反転させる
	// for文でiを使って、0から要素数の半分まで配列を走査する。
	// 配列の要素を両端から順にペアにし、要素の値を入れ替える
	for (i = 0; i <= n / 2; i++) {
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
}
