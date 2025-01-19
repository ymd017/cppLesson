/*
* 問題文：
* キーボードから読み込んだ点数に応じて優／良／可／不可を判定して表示するプログラムを作成せよ
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
	int score;
	int flg;
	string ans;

	// 点数の入力
	// 0以上100以下でない場合は入力させ直す
	do {
		flg = 1;

		cout << "点数を入力してください\n";
		cin >> score;

		// 返答の代入
		if (0 < score && score < 59) {
			ans = "不可";
		}
		else if (60 < score && score < 69) {
			ans = "可";
		}

		else if (70 < score && score < 79) {
			ans = "良";
		}

		else if (80 < score && score < 100) {
			ans = "優";
		}
		else {
			cout << "不正な値です。もう一度入力してください。\n";
			flg = 0;
		}
	} while (flg == 0);


	// 返答の出力
	cout << "成績は" << ans << "です。\n";
}