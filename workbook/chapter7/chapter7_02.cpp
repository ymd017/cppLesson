#include <iostream>
#include <typeinfo>
using namespace std;

/*
* 問題文：
* 前問のプログラムの n, &n, ptr, *ptr, &ptrの型情報を表示するプログラムを作成せよ。
*
* (前問)
* int*型のポインタptrを、int型オブジェクトnを指すように初期化するとともに、
* n, &n, ptr, *ptr, &ptrの値を表示するプログラムを作成せよ。
*/


/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// nの初期化
	int n = 5;

	// ポインタの初期化
	int* ptr = &n;

	// 各値を出力する
	cout << "n: " << typeid(n).name() << "\n";
	cout << "&n: " << typeid(&n).name() << "\n";
	cout << "ptr: " << typeid(ptr).name() << "\n";
	cout << "*ptr: " << typeid(*ptr).name() << "\n";
	cout << "&ptr: " << typeid(&ptr).name() << "\n";
}
