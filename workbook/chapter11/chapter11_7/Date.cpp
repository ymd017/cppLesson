#include <iostream>
#include <sstream>
#include <ctime>
#include "Date.h"
using namespace std;

Date::Date() {
	 time_t now = time(NULL);	// エポックタイムの取得（1970年からの経過秒数)
	 tm* localTime = localtime(&now);	// time_t型のnowを日本の時間にする、tm*型はメンバに年月日時分秒それぞれを持っている。

	 year = localTime->tm_year + 1900;
	 month = localTime->tm_mon + 1;
	 day = localTime->tm_mday;
	
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

Date Date::preceding_day() {
	Date temp = *this;		// 年月日の丸コピ
	int lastDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// 日付を1減らす
	temp.day -= 1;

	// 日付が0以下になる場合の処理
	// 日付をmonth-1の月の最終日にする
	// 月を-1にする
	if (temp.day <= 0) {
		int idx = ((temp.month - 2) + 12) % 12;
		temp.day = lastDay[idx]; // 添字化に-1&ひと月前で-1
		temp.month -= 1;
	}

	// 月が0以下になった時の処理
	// 月を12にする。
	// 年を-1する
	if (temp.month <= 0) {
		temp.month = 12;
		temp.year -= 1;
	}

	return temp;
}

string Date::toString() {
	stringstream ss;
	ss << year << "年" << month << "月" << day << "日";
	return ss.str();
}

int Date::week() {
	
	// ツェラーの公式を使う
	int h;

	int d = day;
	int m = month;
	int y = year;

	if (m == 1 || m == 2) {
		m += 12;
		--year;
	}

	int k = year % 100;
	int j = year / 100;

	int fml1 = d;
	int fml2 = (13 * (m + 1)) / 5;
	int fml3 = k;
	int fml4 = k / 4;
	int fml5 = j / 4;
	int fml6 = 5 * j;
	
	h = (fml1 + fml2 + fml3 + fml4 + fml5 + fml6 ) % 7;

	return h;
}
