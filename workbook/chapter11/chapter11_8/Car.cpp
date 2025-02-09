#include <iostream>
#include "Position.h"
#include "Car.h"
using namespace std;

Car::Car(string nm, int n, int w, int l, int h, int py, int pm, int pd, double fe, double tc, double rf) {
	name = nm;
	number = n;
	width = w;
	length = l;
	height = h;
	purchaseYear = py;
	purchaseMonth = pm;
	purchaseDay = pd;
	fuelEff = fe;
	tankCapa = tc;
	remainingFuel = rf;

	x = 0;
	y = 0;
	carpos.setX(x);
	carpos.setY(y);

}

void Car::setPrameter() {
	cout << "車のデータを入力してください。\n";
	cout << "車の名前：";
	cin >> name;

	cout << "車のナンバー：";
	cin >> number;

	cout << "車の幅：";
	cin >> width;

	cout << "車の長さ：";
	cin >> length;

	cout << "車の高さ：";
	cin >> height;

	cout << "購入年：";
	cin >> purchaseYear;

	cout << "購入月：";
	cin >> purchaseMonth;

	cout << "購入日：";
	cin >> purchaseDay;

	cout << "燃費：";
	cin >> fuelEff;

	cout << "タンク容量：";
	cin >> tankCapa;d

	cout << "残りの燃料：";
	cin >> remainingFuel;
}

void Car::printSpec() {
	cout << "車のデータを入力してください。\n";
	cout << "車の名前：" << name << "\n";
	cout << "車のナンバー：" << number << "\n";
	cout << "車の幅：" << width << "\n";
	cout << "車の長さ：" << length << "\n";
	cout << "車の高さ：" << height << "\n";
	cout << "購入年：" << purchaseYear << "\n";
	cout << "購入月：" << purchaseMonth << "\n";
	cout << "購入日：" << purchaseDay << "\n";
	cout << "燃費：" << fuelEff << "\n";
	cout << "タンク容量：" << tankCapa << "\n";
	cout << "残りの燃料：" << remainingFuel << "\n";


}

