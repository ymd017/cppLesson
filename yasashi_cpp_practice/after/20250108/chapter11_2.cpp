#include <iostream>
using namespace std;

/*============================================================
* 人に関する構造体
* メンバ：age		年齢
* メンバ：weight	体重
* メンバ：height	身長
============================================================*/
struct Person {
	int age;
	double weight;
	double height;
};

void aging(Person* p);

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {
	
	//構造体変数を宣言する
	Person person1;
	Person person2;

	//1人目の年齢、体重、身長を入力する
	cout << "年齢を入力してください。\n";
	cin >> person1.age;

	cout << "体重を入力してください。\n";
	cin >> person1.weight;

	cout << "身長を入力してください。\n";
	cin >> person1.height;

	//結果を出力する
	cout << "年齢" << person1.age << "　体重" << person1.weight << "　身長" << person1.height << "\n";
	
	//aging関数で年齢を1つ増やし、結果を出力する
	aging(&person1);
	cout << "1年経過しました。\n";
	cout << "年齢" << person1.age << "　体重" << person1.weight << "　身長" << person1.height << "\n";
}

/*============================================================
* 年齢を1つ増やす関数
* 引数　：Person* p		Person構造体のポインタ
* 戻り値：なし
============================================================*/
void aging(Person* p) {

	p->age++;
}
