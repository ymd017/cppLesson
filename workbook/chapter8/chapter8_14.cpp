#include <iostream>
using namespace std;

/*
* 問題文：
* 文字列sに含まれる最も先頭に位置する文字cの添字を返す関数strchr_idxを作成せよ。
* 文字cが文字列sに含まれない場合は-1を返却すること
*/

int strchr_idx(const char s[], char c);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	char c;		// 検索する文字
	int idx;	// 検索文字が初めて現れたインデックス

	// 文字列sの初期化
	char s[] = "hello";

	// 文字列の出力
	cout << "文字列は " << s << " です。\n";

	// 検索する文字の入力
	cout << "検索する文字を入力してください。\n";
	cin >> c;

	// 文字列sに含まれる最も先頭に位置する文字cの添字を返す関数の使用
	idx = strchr_idx(s, c);

	// 結果の出力
	if (idx > 0) {
		cout << "文字列 " << s << " に" << c << "が初めて出現するインデックスは" << idx << "です。\n";
	}
	else {
		cout << "文字" << c << "は文字列にありませんでした。\n";
	}

}

/*============================================================
* 文字列sに含まれる最も先頭に位置する文字cの添字を返す関数
* 引数　：const char s[]		s1の末尾に連結する文字列
* 引数　：char c				検索する文字
* 戻り値：int					文字列sに含まれる最も先頭に位置する文字cのインデックス
============================================================*/
int strchr_idx(const char s[], char c) {

	// for文で先頭からNULL文字の1つ前まで走査する
	// 文字cが初めて現れたところのインデックスを返却する
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == c) {
			return i;
		}
	}

	// 文字cが現れなかった場合は-1を返却する
	return -1;
}