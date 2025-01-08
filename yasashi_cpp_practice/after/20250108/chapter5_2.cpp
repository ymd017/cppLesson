#include <iostream>
using namespace std;

void resultOutput(int smaller, int bigger);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	int n1, n2;

	//大小を比較する2つの整数を入力する
	cout << "整数を2つ入力してください。\n";
	cin >> n1 >> n2;

	//大小を比較する
	//大小比較の結果を出力する関数resultOutputを用いる
	if (n1 > n2) {
		resultOutput(n2, n1);
	}
	else if (n2 > n1) {
		resultOutput(n1, n2);
	}
	else {
		cout << "2つの数は同じ値です。\n";
	}
}

/*============================================================
* 大小比較の結果を出力する関数
* 引数　：int smaller	小さいほうの値
* 引数　：int bigger	大きいほうの値
* 戻り値：なし
============================================================*/
void resultOutput(int smaller, int bigger) {
	cout << smaller << "より" << bigger << "のほうが大きい値です。\n";
}
