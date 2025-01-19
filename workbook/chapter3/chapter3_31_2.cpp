/*
* 問題文：
* じゃんけんプログラムを作成せよ。
* いずれか一方が3回勝つまで繰り返せるようにする。
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string outputRPS(int num);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	int cpWins;			// コンピュータの勝ち数
	int playerWins;		// プレイヤーの勝ち数
	int cpNum;			// コンピュータが選んだ番号
	int playerNum;		// プレイヤーが選んだ番号
	int diff;			// コンピュータとプレイヤーの選んだ番号の差分

	// シード値
	srand(time(NULL));

	// じゃんけん開始と出力する
	cout << "じゃんけん開始！どちらかが3回勝てば終了します。\n\n";

	// do while文でコンピューターか、人間の勝数が3回になるまで反復処理をする。
	// 0~2の乱数を生成し、変数に格納する。
	// プレイヤーに0(グー), 1(チョキ), 2(パー)を入力させる
	// コンピュータとプレイヤーが選んでいた結果を出力する。0ならグー、1ならチョキ、2ならパーとする。
	// 
	// どちらが勝っているかを判定する。
	cpWins = 0;
	playerWins = 0;

	do {
		cpNum = rand() % 3;

		cout << "何を出しますか？\n0(グー), 1(チョキ), 2(パー)\n";
		cin >> playerNum;
		cout << "\n";

		cout << "コンピュータ： " << outputRPS(cpNum) << "\n";
		cout << "あなた： " << outputRPS(playerNum) << "\n";
		cout << "\n";

		// どちらが勝っているかを判定する。
		// cpNumとplayerNumの差が0なら引き分け、+1ならプレイヤーは負け、+2ならプレイヤーの勝ち。
		// cpNumとplayerNumの差をプラスの範囲で考えたいので、+3をし、0~2で循環させたいので、% 3をする。
		switch ((cpNum - playerNum + 3) % 3) {
		case 0:
			cout << "★ 引き分けです。\n\n";
			break;
		case 1:
			cout << "★ コンピュータの勝ち\n\n";
			cpWins++;
			break;
		case 2:
			cout << "★ あなたの勝ち\n\n";
			playerWins++;
			break;
		}

	} while (cpWins < 3 && playerWins < 3);


	// 勝敗を出力する。
	cout << "------------------------------\n";
	if (playerWins > cpWins) {
		cout << "あなたの勝ちです。\n";
	}
	else {
		cout << "コンピュータの勝ちです。\n";
	}
}

string outputRPS(int num) {

	switch (num) {
	case 0:
		return "グー";
		break;
	case 1:
		return "チョキ";
		break;
	case 2:
		return "パー";
		break;
	}
}
