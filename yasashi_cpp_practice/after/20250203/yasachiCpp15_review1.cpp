/*
*
*/

#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) {
		x = a;
		y = b;
	}

	void showPos() {
		cout << "(" << x << "," << y << ")";
	}

	Point operator+(Point p) {
		Point temp;
		temp.x = x + p.x;
		temp.y = y + p.y;
		return temp;
	}

	Point operator++() {
		x++;
		y++;
		return *this;
	}

	Point operator++(int d) {
		Point p = *this;
		x++;
		y++;
		return p;
	}

	friend Point operator+(int a, Point p);
};

Point operator+(int a, Point p) {
	Point temp;
	temp.x = a + p.x;
	temp.y = a + p.y;
	return temp;
}

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	Point p1(2, 3);
	Point p2(5, 7);

	//Point p3 = p1 + p2;
	//p3.showPos();

	//Point p4 = p1++;
	//p4.showPos();
	//cout << "\n";
	//p1.showPos()

	Point p5 = 5 + p1;
	p5.showPos();
}