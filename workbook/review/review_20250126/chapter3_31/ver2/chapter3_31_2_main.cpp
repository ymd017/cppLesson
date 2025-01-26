/*
* ヘッダファイルがクラスの定義
* メンバ関数定義用のソースファイル
* main()のソースファイルはオブジェクト化して、メンバ関数を使う
*/

#include <iostream>
#include "chapter3_31_2.h"
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main(){

	// 変数宣言部
	Game game1;
	Retry retry1;
	int nextPlayFlg;

	game1.play();

	do {
		// ゲームをする
		game1.play();

		// もう一度遊ぶか尋ねる
		// 遊ぶ場合は答えの整数値を決めるところから繰り返す
		// 遊ばない場合は終了する
		nextPlayFlg = 0;
		nextPlayFlg = retry1.askPlaying();
	} while (nextPlayFlg == 1);		// フラグが1なら繰り返す

	return 0;
}
