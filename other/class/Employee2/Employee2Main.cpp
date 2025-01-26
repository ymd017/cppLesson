/*
* ヘッダファイルがクラスの定義
* メンバ関数定義用のソースファイル
* main()のソースファイルはオブジェクト化して、メンバ関数を使う
*/

#include <iostream>
#include "Employee2.h"

using namespace std;
/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main(){

	Employee2 person[3];

	person[0].setNumber(1111);
	person[0].setSalary(100000);
	person[0].setName("田中");

	person[1].setNumber(2222);
	person[1].setSalary(200000);
	person[1].setName("高橋");

	person[2].setNumber(3333);
	person[2].setSalary(300000);
	person[2].setName("佐藤");

	for (int i = 0; i < 3; i++) {
		person[i].showData();
	}
}
