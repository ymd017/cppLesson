
class User {
private:
	int num;		// じゃんけんのグー、チョキ、パーに相当する整数0,1,2
public:
	// ユーザーの手を入力する関数
	int setNum();
};

class Computer {
private:
	int num;		// じゃんけんのグー、チョキ、パーに相当する整数0,1,2
public:
	// コンピュータの手を設定する関数
	int setNum();
};

class Game {
private:
	int userWin;
	int comWin;
	int diff;		// ユーザーの手とコンピュータの手の差で0なら引き分け、1ならユーザーが負け、2ならユーザーが勝ち

public:

	Game();
	// 出した手を表示する
	void outputHand(int handNum);

	// コンピュータの手を出力する
	void outputComHand(int cnum);

	// ユーザーの手を出力する
	void outputUserHand(int unum);

	// 勝敗を決める
	void judgeWin(int unum, int cnum);

	// ゲーム進行
	void playGame();
};