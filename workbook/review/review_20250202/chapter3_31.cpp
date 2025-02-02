/*
* じゃんけんゲームをクラスを用いて作成する
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// User, Computerクラスの基本クラスとなる抽象クラス
class Player {
protected:
	int hand;		// じゃんけんの手、0~2の範囲で、0:グー、1:チョキ、2:パー
public:
	virtual void setHand() = 0;

	int getHand() {
		return hand;
	}

	virtual const char* getHandName() {

		switch (hand) {
		case 0:
			return "グー";
			break;
		case 1:
			return "チョキ";
			break;
		case 2:
			return "パー";
			break;
		default:
			return "エラー";
		}
		
	}
};

// ユーザーのクラス
class User : public Player{
public:
	void setHand();
};


// コンピュータのクラス
class Computer : public Player {
public:
	void setHand();
};

// ゲームクラス
class Game {
private:
	User user;
	Computer comp;

public:
	// コンピュータの手を決める
	void setCompHand();

	// ユーザーの手を決める
	void setUserHand();

	// それぞれの手を出力する
	void showHands();

	// 勝敗を判定し、結果を出力する
	void JudgeWinner();
};



void User::setHand() {

	do {
		cout << "出す手を入力してください。(0:グー、1:チョキ、2:パー)\n";
		cin >> hand;
	} while (hand < 0 || hand > 2);

	cout << "\n";
}

void Computer::setHand() {
	
	// 0~2をランダムで選択する
	hand = rand() % 2;
}

// コンピュータの手を決める
void Game::setCompHand() {
	// 手を決める
	comp.setHand();
}

// ユーザーの手を決める
void Game::setUserHand() {
	// 手を決める
	user.setHand();
}


// それぞれの手を出力する
void Game::showHands() {
	cout << "コンピュータの手: " << comp.getHandName() << "\n";
	cout << "ユーザーの手: " << user.getHandName() << "\n\n";
}

// 勝敗を判定し、結果を出力する
void Game::JudgeWinner() {

	// 変数宣言部
	int diff;			// 出した手の整数の差

	// コンピュータを基準に、差を求める
	diff = user.getHand() - comp.getHand();
	diff += 3;		// 正の差だけにする
	diff %= 3;		// 2と0がつながり、循環するようにする

	// 差から勝敗を求める
	// 差が0なら引き分け、差が1ならコンピュータの勝利、差が2ならユーザーの勝利

	switch (diff) {
	case 0:
		cout << "結果：引き分け\n\n";
		break;
	case 1:
		cout << "結果：コンピュータの勝ち\n\n";
		break;
	case 2:
		cout << "結果：あなたの勝ち\n\n";
		break;
	default:
		cout << "勝敗が判定できませんでした\n";
		break;
	}

}



/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// rand()用シード値の設定
	srand(time(NULL));

	// ゲームオブジェクトの生成
	Game game;

	// 開始の表示
	cout << "じゃんけんゲームスタート！\n\n";

	// コンピュータの手を決める
	game.setCompHand();

	// ユーザーの手を決める
	game.setUserHand();

	// それぞれの手を出力する
	game.showHands();

	// 勝敗を判定する
	game.JudgeWinner();

}
