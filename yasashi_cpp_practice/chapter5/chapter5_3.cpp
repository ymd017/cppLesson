#include <iostream>
using namespace std;

int main() {

	int num;

	cout << "成績を入力してください。\n";
	cin >> num;

	switch (num) {
	case 1:
		cout << "成績は" << num << "です。もっとがんばりましょう。\n";
		break;
	case 2:
		cout << "成績は" << num << "です。もう少しがんばりましょう。\n";
		break;
	case 3:
		cout << "成績は" << num << "です。さらに上をめざしましょう。\n";
		break;
	case 4:
		cout << "成績は" << num << "です。たいへんよくできました。\n";
		break;
	case 5:
		cout << "成績は" << num << "です。たいへん優秀です。\n";
		break;
	}
	
}
