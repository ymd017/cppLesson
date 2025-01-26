/*
* 問題文：
* int型の変数areaに面積を読み込んで、辺の長さが整数で面積がareaとなる四角形の各辺の長さを
* 列挙して表示するプログラムを作成せよ。
*
* なお、一辺の長さとして13が得られた場合は、辺の長さの表示を行わず、
* 「13で割り切れるため中断します」と表示して列挙を中断すること。
*
* 最後に列挙した個数を表示すること。
*/

#include <iostream>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	/*
	面積が整数値のとき、辺の長さが整数値になるということは、
	辺の長さは面積の値の約数である。
	なので、約数を列挙すればいい。
	今回は辺の長さのペアを列挙するので、面積の値の半分まで調べればいい
	*/

	// 変数宣言部
	int area;
	int edge1;
	int edge2;
	int count = 0;		// 辺のペアを列挙した個数
	int i;			// ループインデックス

	// 面積を入力する
	cout << "面積を入力してください。\n";
	cin >> area;

	// for文で1からareaの値の半分まで走査して、約数かどうか調べる
	// 約数であれば、ペアとなる辺の長さを調べて、辺のペアを出力する。列挙した個数を1増やす
	// ↑この時、辺のペアのどちらかに13である場合は列挙を中断する
	for (i = 1; i <= (area / 2); i++) {
		if ((area % i) == 0) {
			edge1 = i;
			edge2 = area / edge1;

			if (edge1 == 13 || edge2 == 13) {
				break;
			}

			cout << "(" << edge1 << " , " << edge2 << ")\n";

			count++;
		}
	}
	cout << "\n";

	// 列挙した個数を出力する
	cout << "列挙した個数：" << count << "\n";
}