#include <iostream>
using namespace std;

/* 
* 問題文：
* 6人の2科目（国語、数学）の点数を読み込んで、
* 科目ごとの合計点と平均点、学生ごとの合計点と平均点を求めるプログラムを作成せよ。
*/

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	int sum = 0;		// 求める合計点
	double avg;		// 求める平均点
	const int num = 6;	// 学生の人数
	const int sub = 2;	// 教科数
	string subname;	// 教科名

	// 行列を使用して、学生の点数を管理する。forのネストを用いる。
	// 入力するときに学生単位で入力できると便利なので、列を学生(0~5)、行を科目(0~1)とする
	// 行列を宣言する
	int a[num][sub];


	// 行列に値を入力する
	for (int i = 0; i < num; i++) {
		cout << "学生" << i + 1 << "の点数を入力してください。\n";

		for (int j = 0; j < sub; j++) {
			switch (j) {
			case 0:
				subname = "国語";
				break;

			case 1:
				subname = "数学";
				break;
			}

			cout << subname << ": ";
			cin >> a[i][j];
		}
	}
	cout << "\n";


	// 科目ごとの合計点と平均点を求めて、結果を出力する
	// 科目ごとのforで行列の列の科目を走査する
	for (int i = 0; i < sub; i++) {

		// sumを初期化する
		sum = 0;

		// 合計点を求める
		for (int j = 0; j < num; j++) {
			sum += a[j][i];
		}

		// 平均点を求める
		avg = static_cast<double>(sum) / static_cast<double>(num);

		//結果を出力する
		switch (i) {
		case 0:
			subname = "国語";
			break;

		case 1:
			subname = "数学";
			break;
		}

		cout << subname << "の合計点: " << sum << "\n";
		cout << subname << "の平均点: " << avg << "\n";

	}
	cout << "\n";


	// 学生ごとの合計点と平均点を求めて、結果を出力する
	for (int i = 0; i < num; i++) {

		//合計点sumをリセットする
		sum = 0;

		cout << "学生" << i + 1 << ":\n";

		// 学生ごとの合計点を求める
		for (int j = 0; j < sub; j++) {
			sum += a[i][j];
		}

		// 学生ごとの平均点を求める
		avg = static_cast<double>(sum) / static_cast<double>(num);

		// 学生ごとの合計点と平均点を出力する
		cout << "合計点: " << sum << "\n";
		cout << "平均点: " << avg << "\n";
	}


	
}