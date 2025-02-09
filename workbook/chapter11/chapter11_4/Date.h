// #pragma once
#ifndef DateHedder
#define DateHedder

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d);
	Date();
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	Date preceding_day();
	std::string toString();
	int week();
};

#endif