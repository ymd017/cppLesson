/*
* 問題文：
* おみくじプログラムを作成せよ。
* 乱数生成して、大吉、中吉、小吉、吉、末吉、凶、大凶のいずれかを表示すること。
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	int num;
	string ans;

	// シード値
	srand(time(NULL));

	// 乱数を生成し、表示するものをansに格納する
	num = rand() % 7;

	switch (num) {
	case 0:
		ans = "大吉";
		break;
	case 1:
		ans = "中吉";
		break;
	case 2:
		ans = "小吉";
		break;
	case 3:
		ans = "吉";
		break;
	case 4:
		ans = "末吉";
			break;
	case 5:
		ans = "凶";
			break;
	case 6:
		ans = "大凶";
		break;
	}

	// 出力する
	cout << ans << "\n";
}