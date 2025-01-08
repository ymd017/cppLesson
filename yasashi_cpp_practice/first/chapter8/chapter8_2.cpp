#include <iostream>
using namespace std;

void add(int* x, int a) {
	*x += a;
}

int main() {

	int x1, x2, a;

	cout << "2科目分の点数を入力してください。\n";
	cin >> x1 >> x2;

	cout << "加算する点数を入力してください。\n";
	cin >> a;

	add(&x1, a);
	add(&x2, a);

	cout << a << "点加算しましたので\n";
	cout << "科目１は" << x1 << "点となりました。\n";
	cout << "科目２は" << x2 << "点となりました。\n";
}
