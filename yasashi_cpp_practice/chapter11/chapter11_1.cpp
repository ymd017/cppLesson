#include <iostream>
using namespace std;

int main() {

	struct Person {
		int age;
		double weight;
		double height;
	};

	int n = 2;
	Person person1;
	Person person2;

	cout << "年齢を入力してください。\n";
	cin >> person1.age;

	cout << "体重を入力してください。\n";
	cin >> person1.weight;

	cout << "身長を入力してください。\n";
	cin >> person1.height;

	cout << "年齢を入力してください。\n";
	cin >> person2.age;

	cout << "体重を入力してください。\n";
	cin >> person2.weight;

	cout << "身長を入力してください。\n";
	cin >> person2.height;

	cout << "年齢" << person1.age << " 体重" << person1.weight << " 身長" << person1.height << "です。\n";
	cout << "年齢" << person2.age << " 体重" << person2.weight << " 身長" << person2.height << "です。\n";
}
