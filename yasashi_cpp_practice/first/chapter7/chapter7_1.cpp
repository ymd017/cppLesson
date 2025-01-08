#include <iostream>
using namespace std;

int square(int x);

int main() {

	int n;
	
	cout << "整数を入力してください。\n";
	cin >> n;
	
	cout << n << "の2乗は" << square(n) << "です。\n";
	
}

int square(int x) {
	return x * x;
}
