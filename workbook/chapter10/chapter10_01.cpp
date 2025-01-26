/*
* 問題文：
* 名前、身長、体重をメンバとして持つ人間クラスを定義せよ
*/

#include <iostream>
using namespace std;

class Human {
public:
	string name;	// 名前
	int height;		// 身長
	int weight;		// 体重
};

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	Human mori;
	Human hayashi;

	mori.name = "森";
	hayashi.name = "林";

	mori.height = 170;
	hayashi.height = 150;

	mori.weight = 60;
	hayashi.weight = 45;

	cout << "名前：" << mori.name << "、身長：" << mori.height << "、体重：" << mori.weight << "\n";
	cout << "名前：" << hayashi.name << "、身長：" << hayashi.height << "、体重：" << hayashi.weight << "\n";
}
