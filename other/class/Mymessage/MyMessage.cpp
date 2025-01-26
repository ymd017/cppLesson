#include <iostream>
#include "MyMessage.h"

using namespace std;

void MyMessage::showMessage(const char* s, int n) {
	for (int i = 0; i < n; i++) {
		cout << s << "\n";
	}
}

void MyMessage::showMessage() {
	showMessage("‚±‚ñ‚É‚¿‚Í\n", 1);
}

void MyMessage::showMessage(const char* s) {
	showMessage(s, 1);
}