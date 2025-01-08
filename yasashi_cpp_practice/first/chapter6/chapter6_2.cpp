#include <iostream>
using namespace std;

int main() {

	int num;
	int sum = 0;

	cout << "テストの点数を入力してください。(0で終了)\n";

	while (true) {
		cin >> num;

		if (num == 0) {
			break;
		}

		sum += num;
	}

	cout << "テストの合計点は" << sum << "点です。\n";
	
}
