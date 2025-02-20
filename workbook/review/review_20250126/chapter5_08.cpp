/*
* 問題文：
* int型の15つの要素数を持つ配列の全要素に0~10の乱数を代入する
* 縦方向の棒グラフで値を表示する。棒グラフは'*'を並べて表示する。
* 最下段に添字を10で割った剰余を表示する。
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	int a[15];
	int i;		// ループインデックス
	int j;		// ループインデックス

	// rand()用のシード値の用意
	srand(time(NULL));

	// 配列に0^10のランダムな整数値を代入する
	for (i = 0; i < 15; i++) {
		a[i] = rand() % 11;
	}

	// 縦方向にグラフを表示する。
	// 縦方向は1つの要素における値の大きさを表すi、横方向は配列のインデックスを表すjを用いてfor文で走査する
	// 縦方向は下から*を積み上げるので、10から1までデクリメントしていく。
	// 横方向はインデックスなので0から14までインクリメントする
	// 各要素がi以上の値であれば*、iより小さければスペースを表示する
	for (i = 10; i >= 1; i--) {
		for (j = 0; j < 15; j++) {
			if (a[j] >= i) {
				cout << setw(2) << '*';
			}
			else {
				cout << setw(2) << ' ';
			}
		}
		cout << "\n";
	}

	// バーの出力
	// 2 * 配列の要素数だけ出力する
	for (i = 0; i < (2 * 15); i++) {
		cout << '-';
	}
	cout << "\n";

	// インデックスを10で割った剰余の出力
	for (i = 0; i < 15; i++) {
		cout << setw(2) << i % 10;
	}
	cout << "\n\n";

	// 値確認用の出力
	for (i = 0; i < 15; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
}