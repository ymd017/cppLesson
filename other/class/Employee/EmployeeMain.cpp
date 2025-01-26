/*
* ヘッダファイルがクラスの定義
* メンバ関数定義用のソースファイル
* main()のソースファイルはオブジェクト化して、メンバ関数を使う
*/

#include <iostream>
#include "Employee.h"
/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main(){

	Employee tanaka;

	tanaka.setNumber(1234);
	//tanaka.setName("田中一郎");
	tanaka.setSalary(200000);

	tanaka.showData();
}
