
#include <iostream>
#include <iomanip>
using namespace std;

/*
* 問題文：
* 要素数nの配列の要素a[idx]にxを挿入する関数aryinsを作成せよ。
*/

void aryins(int a[], int n, int idx, int x);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	int idx;		// 要素の挿入をするインデックス
	int x;			// 挿入する値

	// 配列を初期化する
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };

	// 配列を出力する
	for (int i = 0; i < 10; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << "\n";

	// 要素の削除を開始するインデックスを入力する
	cout << "値を挿入するインデックスを入力してください。\n";
	cin >> idx;

	// 何個要素を削除するか入力する。
	cout << "挿入する値を入力してください。\n";
	cin >> x;

	// 要素数nの配列から要素a[idx]を削除する関数の使用
	aryins(a, 10, idx, x);

	// 要素削除後の配列を出力する。
	for (int i = 0; i < 10; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << "\n";

}

/*============================================================
* 要素数nの配列から要素a[idx]を削除する関数
* 引数　：int a[]		要素の合計を求める対象の配列
* 引数　：int n			配列の要素数
* 引数　：int idx		要素の挿入をするインデックス
* 引数　：int x			挿入する値
* 戻り値：なし
============================================================*/
void aryins(int a[], int n, int idx, int x) {

	// a[idx]の値をxにする。
	// forでa[idx]から後方の要素を最後まで走査し、
	// a[idx]より後方の要素を1つ前方の要素の値に変更する。
	// 前方の要素の値が変更されるのに、前方の要素の値を代入するとまずいので、後方から代入していく。
	for (int i = n - 1; i > idx; i--) {
		a[i] = a[i - 1];
	}

	a[idx] = x;
}
