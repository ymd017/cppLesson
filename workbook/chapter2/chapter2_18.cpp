/*
* 問題文：
* 0, 1, 2のいずれかの値を乱数生成し、0であれば「グー」、
* 1であれば「チョキ」、2であれば「パー」を表示するプログラムを作成せよ。
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
	num = rand() % 3;

	switch (num) {
	case 0:
		ans = "グー";
		break;
	case 1:
		ans = "チョキ";
		break;
	case 2:
		ans = "パー";
		break;
	}

	// 出力する
	cout << ans << "\n";
}