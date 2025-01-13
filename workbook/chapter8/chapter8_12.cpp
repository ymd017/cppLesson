#include <iostream>
using namespace std;

/*
* 問題文：
* 標準ライブラリstrcat関数と同等な関数を作成せよ。
* 
* strcatはs2が指す文字列を、s1が指す文字列の末尾に連結する
*/

char* strcat(char s1[], const char s2[]);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	char s1[20] = "abcdefg";	// 連結先となる文字列
	char s2[] = "HIJKLMN";		// s1の末尾に連結する文字列

	// s2が指す文字列を、s1が指す配列にコピーする関数の使用
	strcat(s1, s2);

	// s2が連結されたs1の出力
	cout << s1;
}

/*============================================================
* strcatはs2が指す文字列を、s1が指す文字列の末尾に連結する関数
* 引数　：char s1[]			連結先となる文字列
* 引数　：const char s2[]		s1の末尾に連結する文字列
* 戻り値：char*				s1の先頭を指すポインタ
============================================================*/
char* strcat(char s1[], const char s2[]) {

	// インデックスの初期化
	int i = 0;

	// while文でs1を先頭からNULL文字の1つ前まで走査し
	// インデックスをNULL文字のところまで進める
	while (s1[i] != '\0') {
		i++;
	}

	// for文で先頭からNULL文字の1つ前までs2を走査する
	// s1のNULL文字のところから、s2の文字を代入していく。
	for (int j = 0; s2[j] != '\0'; j++) {
		s1[i + j] = s2[j];
	}
	
	return s1;
}
