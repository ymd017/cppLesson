/*
* 西暦年、月、日でデータメンバで構成される、日付クラスを作成せよ。
* 年、月、日の3つの値を受け取るコンストラクタを定義する
* 現在の日付けで初期化するデフォルトコンストラクタを定義する
* 年月日メンバのゲッタを定義する
* 前日の日付を返却するメンバ関数preceding_dayを定義する
*/

#include <iostream>
#include "Date.h"
using namespace std;


/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	Date now;
	cout << now.toString() << "\n";
	cout << now.week() << "\n";

	Date newyearsDay(2025, 1, 1);
	Date yesterday = newyearsDay.preceding_day();
	cout << yesterday.toString();


	
}