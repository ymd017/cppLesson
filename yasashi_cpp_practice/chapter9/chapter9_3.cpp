#include <iostream>
using namespace std;

int length(char* str);

int main() {

	char str[20];

	//文字列の入力
	cout << "文字列を入力してください。\n";
	cin >> str;

	//関数の使用と出力
	cout << "文字列の長さは" << length(str) << "です。\n";
}

int length(char* str) {

	int i = 0;
	while (str[i]) {
		i++;
	}
	//インデックス+1の値が返ってくる

	return i;
}
