#pragma once

class Position {
private:
	int x;
	int y;
public:
	Position(int xpos = 0, int ypos = 0);

	int getX() { return x; }
	int getY() { return y; }

	void setX(int xpos) { x = xpos; }
	void setY(int ypos) { y = ypos; }

	void showPos();

	void movePos(int xpos, int ypos);
};