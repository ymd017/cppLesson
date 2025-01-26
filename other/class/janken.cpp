/*
* じゃんけんゲームをクラスを用いて作成する
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ユーザーを表すクラス
class User {
private:
	int hand;
public:
	void setHand();
	int getHand();
};

// ユーザーの手を選択するメンバ関数
void User::setHand() {
	cout << "ユーザーの手を選んでください\n";
	cout << "0:グー, 1:チョキ, 2:パー\n";
	cin >> hand;
}

int User::getHand() {
	return hand;
}

class Computer {
private:
	int hand;
public:
	void setHand();
	int getHand();
};

// コンピュータの手を選択するメンバ関数
void Computer::setHand() {
	hand = rand() % 3;
}

// コンピュータの手を返すメンバ関数
int Computer::getHand() {
	return hand;
}

class Judge{
private:
	int judge;
public:
	void doJudge(User u, Computer c);
	void showJudge();
};

// ジャッジが勝敗を判定するメンバ関数
void Judge::doJudge(User u, Computer c) {
	int user;		// ユーザーの手
	int computer;	// コンピュータの手
	int diff;		// 出した手の差分

	user = u.getHand();
	computer = c.getHand();

	diff = ((user - computer) + 3) % 3;

	judge = diff;
}

//　勝敗を表示するメンバ関数
void Judge::showJudge() {
	switch (judge) {
	case 0:
		cout << "引き分けです\n";
		break;
	case 1:
		cout << "ユーザーの負けです\n";
		break;
	case 2:
		cout << "ユーザーの勝ちです\n";
		break;
	default:
		cout << "エラー\n";
	}
}

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main(){

	User user;
	Computer computer;
	Judge judge;

	// シード値
	srand(time(NULL));

	// ユーザーが手を選択する
	user.setHand();

	// コンピュータが手を選択する
	computer.setHand();

	// 勝敗を判定する
	judge.doJudge(user, computer);

	// 勝敗を表示する
	judge.showJudge();
}
