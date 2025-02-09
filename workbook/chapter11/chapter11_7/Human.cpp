#include <iostream>
#include <sstream>
#include <ctime>
#include "Date.h"
#include "human.h"
using namespace std;

Human::Human() {
	name = "nanashi";
	birthday = Date(2025, 1, 1);
}

Human::Human(const char* nm, const Date& b) {
	name = nm;
	birthday = b;
}

inline std::string Human::getName() {
	return name;
};

inline Date Human::getBirthday() {
	return birthday;
};


void Human::setName(const char* nm) {
	name = nm;
}

void Human::setBirthday(const Date& b) {
	birthday = b;
}
