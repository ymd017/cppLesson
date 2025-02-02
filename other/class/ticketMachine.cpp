/*
* https://qiita.com/rawr/items/51af11d187aa60207ee3
* 上記サイトを真似して、券売機のシステムを作ってみる
* クラスの分け方について学ぶ
*/

#include <iostream>
#include <cstring>
using namespace std;

// 各メニューのクラス
class Menu {
private:
	int num;			// カテゴリの番号
	int set;			// セットメニュー可否
	int opt;			// オプションの有無
	int price;			// 値段
	char name[20];			// 商品名
public:
	// コンストラクタ
	Menu(const char nm[] = " ", int n = 0, int s = 0, int o = 0, int p = 0) {
		num = n;
		set = s;
		opt = o;
		price = p;
		strcpy(name, nm);
	}

	// メンバ変数を返す関数
	char* getName() {
		return name;
	}

	int getNum() {
		return num;
	}
	int getPrice() {
		return price;
	}
};

// メニューのカテゴリ分けをするクラス
class Category {
private:
	int num;			// カテゴリの番号
	int mainCnt;			// メインメニューの要素数
	int side1Cnt;			// サイドメニュー１の要素数
	int side2Cnt;			// サイドメニュー２の要素数
	int optionCnt;			// オプションの要素数
	Menu menus[10];			// メニューの配列（カテゴリがそれぞれのメニュー配列を持つ）

public:
	// コンストラクタ
	Category(int n = 0) {
		num = n;
		mainCnt = 0;
		side1Cnt = 0;
		side2Cnt = 0;
		optionCnt = 0;

		for (int i = 0; i < 10; i++) {			// メニュー配列の初期化
			menus[i] = Menu("", 0, 0, 0, 0);
		}
	}

	// menus配列の要素にメニューを代入する関数
	void addMenu(Menu menu) {
		switch (menu.getNum()) {
		case 1:
			menus[mainCnt++] = menu;
			break;
		case 2:
			menus[side1Cnt++] = menu;
			break;
		case 3:
			menus[side2Cnt++] = menu;
			break;
		case 4:
			menus[optionCnt++] = menu;
			break;
		default:
			cout << "エラー\n";
			break;
		}

	}

	// カテゴリが持つメニューを表示する関数
	void onDraw(int c = 0) {

		int loop = 0;

		switch (c) {
		case 0:
			loop = mainCnt;
			break;
		case 1:
			loop = side1Cnt;
			break;
		case 2:
			loop = side2Cnt;
			break;
		case 3:
			loop = optionCnt;
			break;
		default:
			cout << "エラー\n";
		}

		for (int i = 0; i < loop; i++) {
			cout << menus[i].getName() << " : " << menus[i].getPrice() << "\n";
		}
	}
};

class TicketMachine {
private:
	Category categories[4];
	Menu selectedMenus[10];
public:
	// コンストラクタ
	// メニューをそれぞれのカテゴリの配列要素に代入する
	TicketMachine() {

		categories[0].addMenu(Menu("牛丼", 1, 1, 1, 380));
		categories[0].addMenu(Menu("豚丼", 1, 1, 1, 350));
		categories[0].addMenu(Menu("鮭定食", 1, 1, 0, 450));

		categories[1].addMenu(Menu("野菜サラダ", 2, 1, 2, 100));
		categories[1].addMenu(Menu("ポテトサラダ", 2, 1, 2, 130));
		categories[1].addMenu(Menu("漬物", 2, 1, 0, 100));
		categories[1].addMenu(Menu("生卵", 2, 0, 0, 60));
		categories[1].addMenu(Menu("温泉卵", 2, 0, 0, 70));

		categories[2].addMenu(Menu("みそ汁", 3, 1, 0, 60));
		categories[2].addMenu(Menu("豚汁", 3, 0, 0, 190));
		categories[2].addMenu(Menu("スープ", 3, 1, 0, 200));

		categories[3].addMenu(Menu("並", 4, 0, 1, 0));
		categories[3].addMenu(Menu("大盛り", 4, 0, 1, 100));
		categories[3].addMenu(Menu("特盛り", 4, 0, 1, 200));
		categories[3].addMenu(Menu("ゴマドレッシング", 4, 0, 2, 0));
		categories[3].addMenu(Menu("和風ドレッシング", 4, 0, 2, 0));

	}

	// 合計金額を算出する関数
	int getTotal();

	// 各カテゴリのonDraw関数を呼び出して、メニューを表示させる関数
	void onDraw(int c = 0) {
		categories[c].onDraw();
	}
};


int TicketMachine::getTotal() {

	// 変数宣言部
	int sum = 0;				// 合計金額
	int mainOrderedFlg = 0;			// メインメニューが注文された時のフラグ
	int side1OrderedFlg = 0;		// サイドメニュー１が注文された時のフラグ
	int side2OrderedFlg = 0;		// サイドメニュー２が注文された時のフラグ

	// セットメニュー割引のフラグ処理
	// セットメニューになる商品が注文されたときのみなので、ここの処理は間違っている
	for (int i = 0; i < 10; i++) {
		sum += selectedMenus[i].getPrice();

		switch (selectedMenus[i].getNum()) {
		case 0:
			mainOrderedFlg = 1;
			break;
		case 1:
			side1OrderedFlg = 1;
			break;
		case 2:
			side2OrderedFlg = 1;
			break;
		default:
			cout << "エラー\n";
		}
	}

	// メイン、サイド１、サイド２が全て注文されている場合、50円引きにする
	if (mainOrderedFlg == 1
		&& side1OrderedFlg == 1
		&& side2OrderedFlg == 1) {
		sum -= 50;
	}

	// 合計金額を返却する
	return sum;
}


/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 初期化
	int totalPrice;
	TicketMachine machine;

	// いらっしゃいませの表示
	cout << "いらっしゃいませ\n\n";

	// メインメニューを表示する
	cout << "メインメニューを選んでください(0~2)\n";
	machine.onDraw(0);

	// メインメニューを選択する

	/*
	// 合計金額を算出する
	totalPrice = machine.getTotal();
	cout << "合計金額: " << totalPrice << "\n";
	*/
}
