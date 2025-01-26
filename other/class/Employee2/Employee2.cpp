#include <iostream>
#include "Employee2.h"

using namespace std;

void Employee2::setNumber(int num) {
	number = num;
}

void Employee2::setSalary(int sal) {
	salary = sal;
}

void Employee2::setName(const char* nm) {
	strcpy(name, nm);
}

void Employee2::showData() {
	cout << number << "\n";
	cout << salary << "\n";
	cout << name << "\n";
}