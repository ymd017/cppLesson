/*
* 
*/

#include <iostream>
#include <cstring>
using namespace std;

class Menu {
private:
	int num = 1;
	int set = 0;
	int opt = 0;
	int price = 0;
	char name[20];
public:
	Menu(const char* nm = "", int n = 0, int s = 0, int o = 0, int p = 0) {
		strcpy(name, nm);
		num = n;
		set = s;
		opt = o;
		price = p;
	}
	const char* getName() {
		return name;
	}

	int getNum() {
		return num;
	}

	int getOpt() {
		return opt;
	}

	int getPrice() {
		return price;
	}

};

class Category {
private:
	int mainCnt = 0;
	int side1Cnt = 0;
	int side2Cnt = 0;
	int optCnt = 0;
	Menu menus[5] = {Menu("", 0, 0, 0, 0)};
public:
	void addMenu(Menu mn);

	void onDraw(int c);
};

class TicketMachine {
private:
	int total = 0;
	Category categories[4];
public:
	TicketMachine();

	void onDraw(int c) {
		categories[c].onDraw(c);
	}
};



void Category::addMenu(Menu mn) {

	switch (mn.getNum()) {
	case 1:
		menus[mainCnt++] = mn;
		break;
	case 2:
		menus[side1Cnt++] = mn;
		break;
	case 3:
		menus[side2Cnt++] = mn;
		break;
	case 4:
		menus[optCnt++] = mn;
		break;
	default:
		throw "引数は1~4の整数です。";
	}

	
}

void Category::onDraw(int c) {
	int cnt;

	switch (c) {
	case 0:
		cnt = mainCnt;
		break;
	case 1:
		cnt = side1Cnt;
		break;
	case 2:
		cnt = side2Cnt;
		break;
	case 3:
		cnt = optCnt;
		break;
	default:
		throw "引数は1~4の整数です。";
	}

	for (int i = 0; i < cnt; i++) {
		cout << menus[i].getName() << " : " << menus[i].getPrice() << "\n";
	}
}

TicketMachine::TicketMachine() {
	// カテゴリーオブジェクトの生成
	Category mainMenu;
	Category sideMenu1;
	Category sideMenu2;
	Category option;

	// カテゴリーオブジェクトの配列要素にメニューオブジェクトを代入する
	mainMenu.addMenu(Menu("牛丼", 1, 1, 1, 380));
	mainMenu.addMenu(Menu("牛丼", 1, 1, 1, 350));
	mainMenu.addMenu(Menu("鮭定食", 1, 1, 0, 450));

	sideMenu1.addMenu(Menu("野菜サラダ", 2, 1, 2, 100));
	sideMenu1.addMenu(Menu("ポテトサラダ", 2, 1, 2, 130));
	sideMenu1.addMenu(Menu("漬物", 2, 1, 0, 100));
	sideMenu1.addMenu(Menu("生卵", 2, 0, 0, 60));
	sideMenu1.addMenu(Menu("温泉卵", 2, 0, 0, 70));

	sideMenu2.addMenu(Menu("みそ汁", 3, 1, 0, 60));
	sideMenu2.addMenu(Menu("豚汁", 3, 0, 0, 190));
	sideMenu2.addMenu(Menu("豚汁", 3, 1, 0, 200));
	
	option.addMenu(Menu("並み", 4, 0, 1, 0));
	option.addMenu(Menu("大盛り", 4, 0, 1, 100));
	option.addMenu(Menu("特盛り", 4, 0, 1, 200));
	option.addMenu(Menu("ゴマドレッシング", 4, 0, 2, 0));
	option.addMenu(Menu("和風ドレッシング", 4, 0, 2, 0));

	// カテゴリーオブジェクトを券売機オブジェクトの配列要素にする
	// ↑メニュー追加前にやると、値渡しで追加されてないことになるのでは
	categories[0] = mainMenu;
	categories[1] = sideMenu1;
	categories[2] = sideMenu2;
	categories[3] = option;

	

}

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 券売機オブジェクトの生成
	TicketMachine ticketMachine;

	// いらっしゃいませの表示
	cout << "いらっしゃいませ\n\n";

	// メインメニューの表示
	cout << "メインメニューをお選びください\n";
	ticketMachine.onDraw(0);
}