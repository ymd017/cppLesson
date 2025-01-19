/*
* 問題文：
* 2桁の整数値(10~99)を当てさせる数当てゲームを作成せよ。
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

using namespace std;

int retry();
int judgeAnser(int inputNum, int ansNum);
void game();

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	game();

	cout << "ゲームを終了しました。\n";

}



/*============================================================
* 繰り返し遊ぶか入力させ、繰り返すかどうかのブール値を返却する関数
* 引数　：なし
* 戻り値：int				// 繰り返し遊ぶときはtrue、遊ばないときはfalseを返す
============================================================*/
int retry() {

	// 変数宣言部
	char ans;		// もう一度遊ぶかどうかの入力
	int flg;		// 反復処理フラグのフラグ

	do {
		// 反復処理フラグを初期化する
		flg = 0;

		// もう一度やるか入力させる
		cout << "もう一度遊びますか？（y：はい、n：いいえ）\n";
		cin >> ans;

		// 返答がy, Yならtrueを返す、nかNならfalseを返す
		// どれでもない場合はもう一度入力させる。反復処理フラグを1にする
		if (ans == 'y' || ans == 'Y') {
			return 1;
		}
		else if (ans == 'n' || ans == 'N') {
			return 0;
		}
		else {
			flg = 1;
		}

	} while (flg == 1);

}

/*============================================================
* 入力値が正解かどうか判定し、不正解時はもっと大きいか小さいか表示する関数
* 引数　：int inputNum		入力値
* 引数　：int ansNum		答えの値
* 戻り値：int				反復処理フラグ
============================================================*/
int judgeAnser(int inputNum, int ansNum) {

	// 変数宣言部
	int retryFlg;			// 反復処理フラグ
	int diff;				// 答えと入力の整数値の差

	// 入力整数値と答えが同じ大きさなら、「正解」と表示する。
	// 入力整数値よりも答えが大きければ「大きい」、小さければ「小さい」と表示する。
	// 差を求め、差の度合いで返答を変える。10以上なら「もっと大きいor小さい」、10より小さければ「もう少し大きいor小さい」
	// 反復処理判定もフラグに格納する
	if (inputNum == ansNum) {
		cout << "正解！\n";
		retryFlg = 0;
	}
	else if (inputNum < ansNum) {	// 答えより入力値が小さいとき
		diff = ansNum - inputNum;
		if (diff >= 10) {
			cout << "答えは" << inputNum << "より、もっと大きい値です\n";
		}
		else {
			cout << "答えは" << inputNum << "より、もう少し大きい値です\n";
		}
		retryFlg = 1;
	}
	else {							// inputNum > ansNum	答えより入力値が大きいとき
		diff = inputNum - ansNum;
		if (diff >= 10) {
			cout << "答えは" << inputNum << "より、もっと小さい値です\n";
		}
		else {
			cout << "答えは" << inputNum << "より、もう少し小さい値です\n";
		}
		retryFlg = 1;
	}

	return retryFlg;
}

/*============================================================
* 2桁の整数値(10~99)を当てさせる数当てゲームを実行する関数
* 引数　：なし
* 戻り値：なし
============================================================*/
void game() {

	// 変数宣言部
	int ansNum;			// 答えの整数値
	int inputNum;		// 入力した整数値
	int retryFlg;		// 反復処理のフラグ
	int gameRetryFlg;		// ゲームの反復処理フラグ
	char gameRetryAns;		// ゲームを再びやるかどうかの返答

	// シード値
	srand(time(NULL));

	// ゲーム反復処理フラグの初期化
	gameRetryFlg = 0;

	do {
		// 2桁の整数値を乱数生成して用意し、ansnumに格納する
		ansNum = rand() % 90 + 10;

		// 初回のみ、整数値を入力するように促す
		cout << "キーボードから整数値を入力して、2桁の整数値(10~99)を当ててください。\n";

		do {
			// 反復処理をリセットする
			retryFlg = 0;

			// 整数値を入力させる
			cin >> inputNum;

			// 入力値が正解かどうか判定し、不正解時はもっと大きいか小さいか表示する関数
			// 戻り値の反復処理フラグを格納する
			retryFlg = judgeAnser(inputNum, ansNum);

			// 正解時（retryFlgが0)のときはretry関数を実行する。
			// retry関数：もう一度遊ぶかどうか入力させ、遊ぶかどうかのブール値を返却する関数の実行
			if (retryFlg == 0) {
				gameRetryFlg = retry();
				break;
			}

		} while (retryFlg == 1); // 反復処理フラグが１なら繰り返す

	} while (gameRetryFlg == 1);	// gameRetryFlgが1の時はbreakし、乱数生成から再び処理する
}