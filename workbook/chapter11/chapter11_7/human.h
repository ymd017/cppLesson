#pragma once
#include "Date.h"

class Human {
private:
	std::string name;
	Date birthday;
public:
	Human();
	Human(const char* nm, const Date& b);

	std::string getName();
	Date getBirthday();

	void setName(const char* nm);
	void setBirthday(const Date& b);
};