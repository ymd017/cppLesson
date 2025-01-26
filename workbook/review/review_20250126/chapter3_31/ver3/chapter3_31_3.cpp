#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chapter3_31_3.h"
using namespace std;

// ユーザーの手を入力する
int User::setNum(){
	do {
		cout << "出す手を入力してください。\n";
		cout << "グー:0, チョキ:1, パー:2\n\n";
		cin >> num;
		cout << "\n";

	} while (num < 0 || 2 < num ); // 0~2でない場合は入力させ直す
	

	// 出す手を返却する
	return num;
}

// コンピュータの手を設定する
int Computer::setNum() {
	num = rand() % 3;

	// 出す手を返却する
	return num;
}

// Gameコンストラクタ
Game::Game() {
	userWin = 0;
	comWin = 0;
}

// 出した手を表示する
void Game::outputHand(int handNum) {
	switch (handNum) {
	case 0:
		cout << "グー\n";
		break;
	case 1:
		cout << "チョキ\n";
		break;
	case 2:
		cout << "パー\n";
		break;
	default:
		cout << "エラー：手を表示できませんでした8\n";
	}
}

// コンピュータの手を出力する
void Game::outputComHand(int cnum) {
	cout << "コンピュータの手:";
	outputHand(cnum);
}

// ユーザーの手を出力する
void Game::outputUserHand(int unum) {
	cout << "あなたの手:";
	outputHand(unum);
	cout << "\n";
}


// 勝敗を決める
// 勝数を加算する
void Game::judgeWin(int unum, int cnum) {

	// 勝敗を決める
	diff = (unum - cnum + 3) % 3;

	// 勝数を加算する
	switch (diff) {
	case 0:
		cout << "引き分けです。\n\n";
		break;
	case 1:
		cout << "コンピュータの勝ちです。\n\n";
		comWin++;
		break;
	case 2:
		cout << "あなたの勝ちです。\n\n";
		userWin++;
		break;
	default:
		cout << "エラー：勝敗を判定できませんでした。\n\n";
	}
}

// ゲーム進行
void Game::playGame() {
	// 変数宣言部
	int userNum;
	int comNum;
	Computer com;
	User user;

	// rand()用のシード値の設定
	srand(time(NULL));

	// 勝数の初期化
	userWin = 0;
	comWin = 0;

	// ゲームスタートの出力
	cout << "ゲームスタート！\n\n";

	do {
		// コンピュータの手を設定する
		comNum = com.setNum();

		// ユーザーの手を入力する
		userNum = user.setNum();

		// コンピュータの手を出力する
		outputComHand(comNum);

		// ユーザーの手を出力する
		outputUserHand(userNum);

		// 勝敗を決める
		// 勝数を加算する
		judgeWin(userNum, comNum);
	} while (comWin < 3 && userWin < 3);	// どちらかが先に3回勝つまで続ける

	// 結果の出力
	cout << "**結果**\n";
	if (userWin > comWin) {
		cout << "あなたの勝ち\n";
	}
	else {
		cout << "コンピュータの勝ち\n";
	}
}

Retry::Retry() {
	retryFlg = 0;
}

bool Retry::askPlaying() {

	do {
		cout << "もう一度遊びますか？(1:遊ぶ / 0:遊ばない)\n";
		cin >> retryFlg;
	} while (retryFlg != 0 && retryFlg != 1);

	// 0で遊ばないときはfalse, 1で遊ぶときはtrueを返却する
	if (retryFlg == 0) {
		return false;
	}
	else {
		return true;
	}
}
