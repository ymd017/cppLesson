#include <iostream>
using namespace std;

int add(int x, int a) {
	return x + a;
}

int main() {

	int x1, x2, a;

	cout << "2科目分の点数を入力してください。\n";
	cin >> x1 >> x2;

	cout << "加算する点数を入力してください。\n";
	cin >> a;

	cout << a << "点加算しましたので\n";
	cout << "科目１は" << add(x1, a) << "点となりました。\n";
	cout << "科目２は" << add(x2, a) << "点となりました。\n";
}
