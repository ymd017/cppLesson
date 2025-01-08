#include <iostream>
using namespace std;

int max(int a[], int n);

int main() {

	int num;

	cout << "生徒の数を入力してください。\n";
	cin >> num;

	//動的な配列を用意
	int* test = new int[num];

	//点数を代入する
	cout << "テストの点数を入力してください。\n";

	for (int i = 0; i < num; i++) {
		cin >> test[i];
	}

	//最大値を求める関数の使用と出力
	cout << "最高点は" << max(test, num) << "です。\n";

	delete[] test;
}

int max(int a[], int n) {
	int max = -10000;

	for (int i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}

	return max;
}
