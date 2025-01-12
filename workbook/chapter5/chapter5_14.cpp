#include <iostream>
#include <typeinfo>
using namespace std;

/* 
* 問題文：
* 3次元配列の要素数を求める式を示せ
*/

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	//3次元配列を用意する
	int a[2][3][4];

	//sizeof()で要素数を求めて、結果を出力する
	cout << "a[2][3][4]の要素数： " << sizeof(a) / sizeof(a[0]) << "\n";
	cout << "a[3][4]の要素数： " << sizeof(a[0]) / sizeof(a[0][0]) << "\n";
	cout << "a[4]の要素数： " << sizeof(a[0][0]) / sizeof(a[0][0][0]) << "\n";
	cout << "配列aの構成要素： " << sizeof(a) / sizeof(a[0][0][0]);
}