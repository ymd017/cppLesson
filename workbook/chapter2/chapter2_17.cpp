/*
* 問題文：
* 実数値を読み込んで、2.5で割り切れるかどうかを表示するプログラムを作成せよ。
* 割り切れないときは剰余を表示すること。
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
	int num;

	// 数値の入力
	cout << "実数値を入力してください。\n";
	cin >> num;

	// 2.5で割り切れるか判定する
	// 割り切れないときは剰余を計算し返却する
	if (fmod(num, 2.5) == 0) {
		cout << num << "は2.5で割り切れます\n";
	}
	else {
		cout << num << "は2.5で割り切れません。\n2.5で割ったあまりは " << fmod(num, 2.5) << " です。\n";
	}

	
}