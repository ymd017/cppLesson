#include <iostream>
#include "Position.h"
using namespace std;

Position::Position(int xpos, int ypos) {
	x = xpos;
	y = ypos;
}

void Position::showPos() {
	cout << "Œ»Ý‚ÌÀ•WF(" << x << "," << y << ")\n"; 
}

void Position::movePos(int xpos, int ypos) {
	x += xpos;
	y += ypos;
}