#include <iostream>
using namespace std;

void max(const int score[], int n);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {
	
	int num;

	//学生の数を入力する
	cout << "学生の数を入力してください\n";
	cin >> num;

	//点数を格納する、学生の数に応じた要素数の配列を宣言する。
	int* test = new int[num];

	//配列に点数を入力する
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "人目の点数を入力してください。\n";
		cin >> test[i];
	}

	//max関数で最高点を求めて、結果を出力する。
	max(test, num);
}

/*============================================================
* 最高点を求めて結果を出力する関数
* 引数　：const int score[]		テストの点数が格納されている配列
* 戻り値：なし
============================================================*/
void max(const int score[], int n) {
	//最高点を格納する変数を非常に小さな値で初期化しておく。
	int max = -10000;

	//最高点を求める。今のmaxの値よりも大きい値が出てきたら、maxの値を更新する。
	for (int i = 0; i < n; i++) {
		if (max < score[i]) {
			max = score[i];
		}
	}

	//結果を出力する
	cout << "最高点は" << max << "点です。\n";
}
