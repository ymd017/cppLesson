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
	cout << "�Ԃ̃f�[�^����͂��Ă��������B\n";
	cout << "�Ԃ̖��O�F";
	cin >> name;

	cout << "�Ԃ̃i���o�[�F";
	cin >> number;

	cout << "�Ԃ̕��F";
	cin >> width;

	cout << "�Ԃ̒����F";
	cin >> length;

	cout << "�Ԃ̍����F";
	cin >> height;

	cout << "�w���N�F";
	cin >> purchaseYear;

	cout << "�w�����F";
	cin >> purchaseMonth;

	cout << "�w�����F";
	cin >> purchaseDay;

	cout << "�R��F";
	cin >> fuelEff;

	cout << "�^���N�e�ʁF";
	cin >> tankCapa;d

	cout << "�c��̔R���F";
	cin >> remainingFuel;
}

void Car::printSpec() {
	cout << "�Ԃ̃f�[�^����͂��Ă��������B\n";
	cout << "�Ԃ̖��O�F" << name << "\n";
	cout << "�Ԃ̃i���o�[�F" << number << "\n";
	cout << "�Ԃ̕��F" << width << "\n";
	cout << "�Ԃ̒����F" << length << "\n";
	cout << "�Ԃ̍����F" << height << "\n";
	cout << "�w���N�F" << purchaseYear << "\n";
	cout << "�w�����F" << purchaseMonth << "\n";
	cout << "�w�����F" << purchaseDay << "\n";
	cout << "�R��F" << fuelEff << "\n";
	cout << "�^���N�e�ʁF" << tankCapa << "\n";
	cout << "�c��̔R���F" << remainingFuel << "\n";


}

