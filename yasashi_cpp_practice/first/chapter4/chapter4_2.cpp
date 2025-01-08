#include <iostream>
using namespace std;

int main() {
	double height;
	double width;

	cout << "三角形の高さを入力してください。\n";
	cin >> height;
	
	cout << "三角形の底辺を入力してください。\n";
	cin >> width;

	cout << "三角形の面積は" << height * width / 2.0 << "です。\n";
	

}
