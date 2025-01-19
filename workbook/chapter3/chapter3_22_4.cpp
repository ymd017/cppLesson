/*
* 問題文：
* 記号 * を縦横に並べて、一辺の長さがnである直角二等辺三角形を表示するプログラムを作成せよ。
* 直角が左下側、左上側、右下側、右上側であるものをそれぞれ作成すること
*
* これは直角が右上側のもの
*/

#include <iostream>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	int n;		// 一辺の長さ
	int i;		// ループインデックス
	int j;		// ループインデックス
	int k;		// ループインデックス
	int space;	// スペースの数

	// 一辺の長さnを入力する
	cout << "一辺の長さを入力してください\n";
	cin >> n;

	// spaceを0にする。
	space = 0;

	// for文でiを1からnまで走査する
	// for文でspaceの数だけ' 'を表示する。
	// ↑のfor文を抜けたら、for文でn - j の個数だけ'*'を表示する。
	// spaceを1増やす
	// 改行する
	for (i = 1; i <= n; i++) {
		for (j = 0; j < space; j++) {
			cout << ' ';
		}
		for (k = 0; k < (n - j); k++) {
			cout << '*';
		}
		space++;
		cout << "\n";
	}

}
