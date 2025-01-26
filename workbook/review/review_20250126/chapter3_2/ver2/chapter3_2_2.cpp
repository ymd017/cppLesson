#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chapter3_2_2.h"
using namespace std;

int Player::setNum() {

	// プレイヤーが答える
	cin >> num;

	return num;
}

int Answer::setAns() {

	// シード値
	srand(time(NULL));

	// 答えの整数値を決める
	ans = rand() % 90 + 10;

	return ans;
}

bool Judgement::judgeAns(int num, int ans) {
	// 正解か判定する
	// 正解時は「正解！」と答えを出す。
	// 不正解なら、大小を比較して、「大きい」「小さい」とメッセージを出す。
	// ↑このとき差も判定して、差の大きさが大きければ「もっと」、小さければ「もう少し」と付ける

	if (num == ans) {
		cout << "正解！\n";

		// 結果を返却する
		return true;
	}
	else {
		// 差を求める
		diff = num - ans;

		if (diff > 0) {	// プレイヤーが選んだ数値が答えより大きいとき
			if (diff >= 10) {	// 差が10以上の時
				cout << "もっと小さな数です。\n";
			}
			else {	// 差が10より小さいとき
				cout << "もう少し小さな数です。\n";
			}
		}
		else {			// プレイヤーが選んだ数値が答えよりも小さいとき
			// 差を正にする
			diff *= -1;
			if (diff >= 10) {	// 差が10以上の時
				cout << "もっと大きな数です。\n";
			}
			else {	// 差が10より小さいとき
				cout << "もう少し大きな数です。\n";
			}
		}

		// 結果を返却する
		return false;
	}
}

void Game::play() {

	// 問題文の表示
	cout << "10~99の整数値を当ててください。\n";

	// 答えの整数値を決める
	ans = answer.setAns();

	do {
		// プレイヤーが答える
		num = player.setNum();

		// 正解か判定する
		// 正解時は「正解！」と答えを出す。
		// 不正解なら、プレイヤーが答えるのを繰り返す
		// 大小を比較して、「大きい」「小さい」とメッセージを出す。
		// ↑このとき差も判定して、差の大きさが大きければ「もっと」、小さければ「もう少し」と付ける
		result = judgement.judgeAns(num, ans);

	} while (result == false);
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
