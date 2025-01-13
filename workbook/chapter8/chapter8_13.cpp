#include <iostream>
using namespace std;

/*
* 問題文：
* 標準ライブラリstrcmp関数と同等な関数を作成せよ。
*
* strcmpはs1が指す文字列とs2が指す文字列の大小関係
* （先頭から1文字ずつ比較していき、異なる文字が出現したときに文字コードを比較する）
* 等しければ0、s1がs2より大きければ正の整数値、s1がs2よりも小さければ負の整数値を返す。
*/

int strcmp(const char s1[], const char s2[]);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 文字列s1,s2の初期化
	char s1[] = "abcdefg";
	char s2[] = "abcdEFG";

	// s1が指す文字列とs2が指す文字列の大小関係を比較する関数の使用
	// 結果の出力
	cout << "strcmp(s1, s2)を評価した結果は" << strcmp(s1, s2) << "です。\n";
}

/*============================================================
* s1が指す文字列とs2が指す文字列の大小関係を比較する関数
* 引数　：const char s1[]		大小関係を比較する文字列
* 引数　：const char s2[]		大小関係を比較する文字列
* 戻り値：int					異なる文字が出現したときの文字コードの差
============================================================*/
int strcmp(const char s1[], const char s2[]) {

	int num = 0;		// 異なる文字が出現したときの文字コードの差

	// for文で先頭からNULL文字の1つ前まで走査する
	// s1とs2の各要素を先頭から1つずつ比較し、同じなら何もしない。異なる場合は文字コードを比較する。
	for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
		if (s1[i] != s2[i]) {
			num = static_cast<int>(s1[i]) - static_cast<int>(s2[i]);
		}
	}

	// 異なる文字が出現したときの文字コードの差を返却する
	return num;
}