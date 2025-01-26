/*
* 問題文：
* ①　1以上9以下のランダムな値を表示せよ
* ②　-9以上-1以下のランダムな値を表示せよ
* ③　10以上99以下のランダムな値を表示せよ
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
	int randNum1;
	int randNum2;
	int randNum3;

	// シード値
	srand(time(NULL));

	// ランダムな値を代入する
	randNum1 = rand() % 9 + 1;
	randNum2 = rand() % 9 - 9;
	randNum3 = rand() % 90 + 10;

	// 結果の出力
	cout << "1以上9以下のランダムな値  :  " << randNum1 << "\n";
	cout << "-9以上-1以下のランダムな値: " << randNum2 << "\n";
	cout << "10以上99以下のランダムな値:" << randNum3 << "\n";

}