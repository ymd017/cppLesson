//条件分岐したところで各々出力せずに、変数を使って最後に出力したバージョン

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
		int bigger;
		int smaller;

		if (n1 > n2) {
			bigger = n1;
			smaller = n2;
		}
		else {
			bigger = n2;
			smaller = n1;
		}

		cout << smaller << "より" << bigger << "のほうが大きい値です。\n";
	}
	
}
