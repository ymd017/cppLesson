/*
* 問題文：
* 記号 * を縦横に並べて、一辺の長さがnである直角二等辺三角形を表示するプログラムを作成せよ。
* 直角が左下側、右下側、右上側であるものをそれぞれ作成すること
* 
* これは直角が左下側のもの
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

	// 一辺の長さnを入力する
	cout << "一辺の長さを入力してください\n";
	cin >> n;

	// for文でiを1からnまで走査する
	// iの各回で、for文でiの数だけjを走査し、*を出力する
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cout << '*';
		}
		cout << "\n";
	}

}