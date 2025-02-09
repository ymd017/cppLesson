/*
*
*/

#include <iostream>
#include <cstring>
using namespace std;

class Time {
private:
	int second;
	int minute;
	int hour;
public:
	void setHour(int num);
	void setMinute(int num);
	void setSecond(int num);
	int getSecont();
	int getMinute();
	int getHour();
};

void Time::setHour(int num) {
	hour = num;
}

void Time::setMinute(int num) {
	minute = num;
}

void Time::setSecond(int num) {
	second = num;
}

int Time::getSecont() {
	return second;
}

int Time::getMinute() {
	return minute;
}

int Time::getHour() {
	return hour;
}

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	Time getup;
	getup.setHour(4);
	cout <<	getup.getHour();
}