#include <iostream>
using namespace std;

/*
* 問題文：
* 文字cをn個連続して表示する関数 put_ncharと、
* 記号'*'をn個連続して表示する関数put_starsを作成せよ。
* put_stars内でput_ncharを呼び出すこと。
*/

void put_nchar(int n, char c);
void put_stars(int n);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 文字の個数の変数を宣言
	int n;

	// 文字の個数を入力する
	cout << "* を表示する個数を入力してください\n";
	cin >> n;

	// 記号'*'をn個連続して表示するput_stars関数を使用する
	put_stars(n);
}

/*============================================================
*  文字cをn個連続して表示する関数
* 引数　：int n			文字を表示する個数
* 引数　：char c		表示する文字
* 戻り値：なし
============================================================*/
void put_nchar(int n, char c) {

	// 1からn個までfor文で文字を表示する
	for (int i = 1; i <= n; i++) {
		cout << c;
	}
}

void put_stars(int n) {
	
	// put_nchar関数を使用して、'*'をn個表示させる
	put_nchar(n, '*');
}
