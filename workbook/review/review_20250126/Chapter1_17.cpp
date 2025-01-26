/*
* 問題文：
* キーボードから読み込んだ整数値±5の範囲のランダムな整数値を生成して表示するプログラムを作成せよ
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
	int num;		// キーボードから読み込んだ整数値
	int res;		// 返却する値

	// キーボードから読み込んだ整数値の入力
	cout << "整数を入力してください。\n";
	cin >> num;

	// rand()のシード値
	srand(time(NULL));

	// キーボードから読み込んだ整数値±5の範囲のランダムな整数値の生成
	res = rand() % 11 + num - 5;

	// 結果の出力
	cout << "結果: " << res << "\n";

}