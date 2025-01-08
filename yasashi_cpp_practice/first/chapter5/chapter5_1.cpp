//整数の0がfalseになることを利用したバージョン

#include <iostream>
using namespace std;

int main() {

	int n;

	cout << "整数を入力してください。\n";
	cin >> n;

	if(n%2){
		cout << n << "は奇数です。\n";
	}
	else {
		cout << n << "は偶数です。\n";
	}
	
}
