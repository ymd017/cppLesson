/*
* 問題文：
* 2桁の整数値(10~99)を当てさせる数当てゲームを作成せよ。
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chapter3_31_3.h"
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	Game game;
	Retry retry;

	// ゲームをスタートさせる
	do {
		game.playGame();

		// ゲームを繰り返すか聞く
		retry.askPlaying();

	} while (retry.getRetryFlg() == 1);// フラグが1なら繰り返す
	

}