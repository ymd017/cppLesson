#include <iostream>
using namespace std;

int main() {

	int n1, n2;

	cout << "整数を2つ入力してください。\n";
	cin >> n1 >> n2;

	if (n1 == n2) {
		cout << "2つの数は同じ値です。\n";
	}
	else {
		if (n1 > n2) {
			cout << n2 << "より" << n1 << "のほうが大きい値です。\n";
		}
		else {
			cout << n1 << "より" << n2 << "のほうが大きい値です。\n";
		}
	}
	
}
