#include <iostream>
using namespace std;

struct Person {
	int age;
	double weight;
	double height;
};

void aging(Person* p);

int main() {

	int n = 2;
	Person person1;
	Person person2;

	cout << "年齢を入力してください。\n";
	cin >> person1.age;

	cout << "体重を入力してください。\n";
	cin >> person1.weight;

	cout << "身長を入力してください。\n";
	cin >> person1.height;

	cout << "年齢" << person1.age << " 体重" << person1.weight << " 身長" << person1.height << "です。\n";

	cout << "1年経過しました。\n";
	aging(&person1);
	cout << "年齢" << person1.age << " 体重" << person1.weight << " 身長" << person1.height << "です。\n";
}

void aging(Person* p) {
	p->age++;
}
