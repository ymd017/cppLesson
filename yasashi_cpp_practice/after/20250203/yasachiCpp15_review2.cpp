/*
*
*/

#include <iostream>
using namespace std;

class Number {
private:
	int num;
public:
	operator int() {
		return num;
	}

	Number(int n) {
		num = n;
	}
};

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	
}