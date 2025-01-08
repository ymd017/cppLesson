//冗長かもしれないが、n%2 == 0 で意味をそのまま理解しやすいバージョン

#include <iostream>
using namespace std;

int main() {

	int n;

	cout << "整数を入力してください。\n";
	cin >> n;

	if(n%2==0){
		cout << n << "は偶数です。\n";
	}
	else {
		cout << n << "は奇数です。\n";
	}
	
}
