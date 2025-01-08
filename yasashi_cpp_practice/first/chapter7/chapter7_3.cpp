#include <iostream>
using namespace std;

inline int square(int x);
inline double double_square(double x);

int main() {

	int n;
	
	cout << "整数を入力してください。\n";
	cin >> n;
	
	cout << n << "の2乗は" << square(n) << "です。\n";
	
	double n2;

	cout << "小数を入力してください。\n";
	cin >> n2;

	cout << n2 << "の2乗は" << double_square(n2) << "です。\n";
}

int square(int x) {
	return x * x;
}

double double_square(double x) {
	return x * x;
}
