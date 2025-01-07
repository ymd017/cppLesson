//forと配列を使ってみたバージョン

#include <iostream>
using namespace std;

int main() {

	int sub = 5;
	int score[5];

	for (int i = 0; i < sub; i++) {
		cout << "科目" << i + 1 << "の点数を入力してください。\n";
		cin >> score[i];
	}

	int sum = 0;
	double avg;

	for (int i = 0; i < sub; i++) {
		sum += score[i];
	}

	avg = static_cast<double>(sum) / sub;

	cout << sub << "科目の合計点は" << sum << "点です。\n";
	cout << sub << "科目の平均点は" << avg << "点です。\n";
