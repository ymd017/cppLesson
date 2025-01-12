#include <iostream>
using namespace std;

/*
* 問題文：
* 受け取ったint型引数の値nが負であれば-1を返却し、0であれば0を返却し、
* 正であれば1を返却する関数sign_ofを作成せよ。
*/

int sign_of(int n);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	int ans;		//判定結果を格納する変数

	//判定に用いる値を格納する変数の宣言
	int n;

	//判定に用いる値の代入
	cout << "整数を入力してください\n";
	cin >> n;

	//値が正であれば1, 負であれば0, 0であれば0を返却する関数の使用
	ans = sign_of(n);

	//結果を出力する
	cout << "sign_of(" << n << ")を判定した結果： " << ans;
}

/*============================================================
* 値が正であれば1, 負であれば0, 0であれば0を返却する関数
* 引数　：int n			判定に用いる変数
* 戻り値：int			判定結果
============================================================*/
int sign_of(int n) {

	//値が正であれば1, 負であれば0, 0であれば0を返却する
	if (n > 0) {
		return 1;
	}
	else if (n < 0) {
		return -1;
	}
	else {
		return 0;
	}
}