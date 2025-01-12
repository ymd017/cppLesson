
#include <iostream>
#include <iomanip>
using namespace std;

/*
* 問題文：
* 要素数nの配列から要素a[idx]を先頭とするkこの要素を削除する関数aryrmvを作成せよ。
* 削除はa[idx]より後方の全要素をk個前方にずらすことによって行う。
* 末端の移動できない要素の値は変更しなくていい。
*/

void aryrmv(int a[], int n, int idx, int k);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	int idx;		// 要素の削除を開始するインデックス
	int k;			// 要素を削除する個数

	// 配列を初期化する
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };

	// 配列を出力する
	for (int i = 0; i < 10; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << "\n";

	// 要素の削除を開始するインデックスを入力する
	cout << "要素の削除を開始するインデックスを入力してください。\n";
	cin >> idx;

	// 何個要素を削除するか入力する。
	cout << "何個要素を削除するか入力してください。\n";
	cin >> k;

	// 要素数nの配列から要素a[idx]を削除する関数の使用
	aryrmv(a, 10, idx, k);

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
* 引数　：int idx		削除する要素のインデックス
* 戻り値：なし
============================================================*/
void aryrmv(int a[], int n, int idx, int k) {

	// a[idx]を削除し、a[idx]より後方の全要素の値をk個前方にずらす。
	
	// forでa[idx]から最後まで走査する。
	// a[idx]から後方の要素が、それぞれk個後方に要素があるかを調べる
	// 要素がある場合は、要素の値をk個後ろの要素のものにする。
	for (int i = idx; i < n; i++) {
		if (i + k < n) {
			a[i] = a[i + k];
		}
	}
}
