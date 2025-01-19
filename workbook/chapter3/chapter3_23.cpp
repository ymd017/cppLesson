/*
* 問題文：
* 記号文字*を並べて、高さがheight段で横幅がwidthの平行四辺形を表示するプログラムを作成せよ。
* （上段と下段は水平で、下るたびに1文字分ずつ左にずれていく）
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
	int height;		// 高さ
	int width;		// 横幅
	int space;		// スペースの個数
	int i;			// ループインデックス
	int j;			// ループインデックス
	int k;			// ループインデックス

	// heightとwidthを入力する
	cout << "平行四辺形の高さと横幅を入力してください\n";
	cout << "高さ：";
	cin >> height;
	cout << "横幅：";
	cin >> width;

	// spaceを0にする。
	space = 0;

	// for文でiを1からheightまで走査する
	// iの各回で、for文でjをスペースの個数だけ走査して、スペースを表示する。
	// ↑が終わったら、spaceを1増やす
	// iの各回で、for文でkを1からwidthまで走査し、*を表示する。
	// 改行する
	for (i = 1; i <= height; i++) {
		for (j = 0; j < space; j++) {
			cout << ' ';
		}

		space++;

		for (k = 1; k <= width; k++) {
			cout << '*';
		}

		cout << "\n";
	}


}