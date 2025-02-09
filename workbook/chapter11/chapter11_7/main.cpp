/*
* Humanクラスを作成し、メンバ変数に名前と、誕生日を持たせる。
* ゲッターとセッターも用意する。
* 誕生日はchapter11_4のDateクラスを使用すること。
*/

#include <iostream>
#include "Date.h"
#include "human.h"
using namespace std;


/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	Human taro("taro", Date(2000, 4, 1));
	Date birthday = taro.getBirthday();
	cout << birthday.toString();

	
}