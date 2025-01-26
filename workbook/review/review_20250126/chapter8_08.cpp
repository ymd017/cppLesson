/*
* 問題文：
* 文字列strに含まれる文字chの個数を返す関数strch_cntを作成せよ。
*/

#include <iostream>
using namespace std;

int strch_cnt(const char* str, char ch);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	char str[20];
	char ch;
	int num;

	// 文字列の入力
	cout << "文字列を入力してください\n";
	cin >> str;

	// 検索する文字の入力
	cout << "検索する文字を入力してください\n";
	cin >> ch;

	// 文字列strに含まれる文字chの個数を返す関数の使用
	num = strch_cnt(str, ch);

	// 個数の出力
	cout << ch << "は" << num << "個含まれていました\n";
}

int strch_cnt(const char* str, char ch) {

	// 変数宣言部
	int num = 0;		// 検索対象文字が文字列に含まれている個数
	const char* i;			// ループインデックス

	// 検索対象の文字がいくつ文字列に含まれているかを数える
	// for文で走査し、一文字ずつif文で調べる
	// 検索対象文字であれば、numを1増やす
	for (i = str; *str != '\0'; str++) {
		if (*str == ch) {
			num++;
		}
	}

	// 個数を返却する
	return num;
}