#include <iostream>
#include "Employee.h"
using namespace std;

void Employee::setNumber(int num) {
	number = num;
}

void Employee::setName(char nm[]) {
	strcpy(name, nm);
}

void Employee::setSalary(int sl) {
		salary = sl;
}

void Employee::showData(){
	cout << number << "\n";
	//cout << name << "\n";
	cout << salary << "\n";
}