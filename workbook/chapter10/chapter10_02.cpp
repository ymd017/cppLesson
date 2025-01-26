/*
* 問題文：
* 名前、身長、体重をメンバとして持つ人間クラスを定義せよ
*/

#include <iostream>
#include "chapter10_02.h"
using namespace std;

// コンストラクタ
Human::Human(string n, int h, int w) {
	string name = n;
	int height = h;
	int weight = w;
}

// 太る
void Human::growFat(int dw) {
	weight += dw;
}

// 痩せる
void Human::slimOff(int dw) {
	weight -= dw;
}

int main() {

	Human mori("森", 170, 60);
}
