#include <iostream>
using namespace std;

template <class T>
T square(T x) {
	return x * x;
}

int main() {

	int n;
	double n2;
	
	cout << "整数を入力してください。\n";
	cin >> n;
	cout << "小数を入力してください。\n";
	cin >> n2;

	cout << n << "の2乗は" << square(n) << "です。\n";
	cout << n2 << "の2乗は" << square(n2) << "です。\n";
}
