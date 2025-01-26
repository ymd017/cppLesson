/*
* 問題文：
* 2桁の整数値(10~99)を当てさせる数当てゲームを作成せよ。
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chapter3_31_1.h"
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	Game game;
	int nextGameFlg;

	// ゲームをスタートさせる
	do {
		nextGameFlg = 0;
		game.playGame();

		// ゲームを繰り返すか聞く
		cout << "もう一度遊びますか？(1:遊ぶ, 0:終了する)\n";
		cin >> nextGameFlg;
	} while (nextGameFlg == 1);// フラグが1なら繰り返す
	

}