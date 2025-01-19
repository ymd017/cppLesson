#include <iostream>
using namespace std;

class Point {
private:
	int x;		// X座標(0~10の範囲)
	int y;		// Y座標(0~10の範囲)

public:

	// x座標を代入する関数
	void setX(int a) {
		if (a >= 0 && a <= 10) {
			x = a;
		}
		else {
			cout << a << "は0~10の範囲外なので代入できません。\n";
		}
	}

	// y座標を代入する関数
	void setY(int b) {
		if (b >= 0 && b <= 10) {
			y = b;
		}
		else {
			cout << b << "は0~10の範囲外なので代入できません。\n";
		}
	}

	// x座標を返す関数
	int getX() {
		return x;
	}

	// y座標を返す関数
	int getY() {
		return y;
	}
};

/*============================================================
* オブジェクトのポインタを受け取って、座標を返す関数
* 引数　：Point* pPoint		Pointのオブジェクトのポインタ
* 戻り値：なし
============================================================*/
void outputPos(Point* pPoint) {
	cout << "座標は(" << pPoint->getX() << "," << pPoint->getY() << ")です。\n";
}

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// 変数宣言部
	Point point1;
	int a;
	int b;

	// データメンバに代入する
	cout << "x座標を入力してください。\n";
	cin >> a;
	point1.setX(a);

	cout << "y座標を入力してください。\n";
	cin >> b;
	point1.setY(b);

	// 座標の出力
	outputPos(&point1);
}
