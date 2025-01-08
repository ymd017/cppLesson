#include <iostream>
using namespace std;

int count(char str[], char ch);

int main() {

	char str[20];
	char ch;

	//文字列の入力
	cout << "文字列を入力してください。\n";
	cin >> str;

	//検索する文字の入力
	cout << "文字列から探す文字を入力してください。\n";
	cin >> ch;

	//関数の使用と出力
	cout << str << "の中に" << ch << "は全部で" << count(str, ch) << "個あります。\n";
}

int count(char str[], char ch) {

	int count = 0;
	int i = 0;

	while (str[i]) {
		if (str[i] == ch) {
			count += 1;
		}

		i++;
	}

	return count;
}
