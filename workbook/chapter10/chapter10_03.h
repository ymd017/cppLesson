#include <iostream>

/*
* 問題文：
* ヘッダ部のみで実現された自動車クラスCarを作成せよ。
* 名前、ナンバー、幅、高さ、長さ、現在位置座標(x座標、y座標)、燃費、タンク量、残り燃料
* のデータメンバを持たせること。
* また、座標を調べる、自動車を移動する、給油するといったことを行うメンバ関数を定義すること。
*/

class Car {
private:
	std::string name;			// 名前
	int num;					// ナンバー
	int width;					// 幅
	int height;					// 高さ
	int length;					// 長さ
	double xpos;				// x座標
	double ypos;				// y座標
	double fuelEco;				// 燃費(単位距離あたりに消費する燃料)
	double tankCapa;			// タンク量
	double remainingFuel;		// 残り燃料

public:
	// コンストラクタ
	Car(int n, int w, int h, int l, double x, double y, double fe, double tc, double rf) {
		num = n;

		if (w >= 0) {
			width = w;
		}
		
		if (h >= 0) {
			height = h;
		}

		if (l >= 0) {
			length = l;
		}
		
		xpos = x;
		ypos = y;
		fuelEco = fe;

		if (tc >= 0) {
			tankCapa = tc;
		}

		if (0 <= rf && rf <= tankCapa) {
			remainingFuel = rf;
		}
	}

	// x座標を調べる
	double getXpos(){
		return xpos;
	}

	// y座標を調べる
	double getYpos() {
		return ypos;
	}

	/*============================================================
	* 自動車を移動する関数
	* 引数　：double dx			x座標移動量
	* 引数　：double dy			y座標移動量
	* 戻り値：bool				移動が成功したかどうかの判定
	============================================================*/
	void translate(double dx, double dy) {

		// 変数宣言部
		double dist;
		double necessaryFuel;

		// 移動距離を求める
		dist = sqrt((dx * dx) + (dy * dy));

		// 消費した燃料を求める
		necessaryFuel = dist / fuelEco;

		// 残り燃料よりもかかる燃料が多ければfalseを返す
		if (necessaryFuel > remaingFuel) {
			return false;
		}
		else {
			// 残りの燃料から、移動にかかった燃料分を減らす
			remaingFuel -= necessaryFuel;
			
			// 座標x,yにそれぞれ移動量を加算する
			xpos += dx;
			ypos += dy;

			return true;
		}
	}

	/*============================================================
	* 給油関数
	* 引数　：double df			給油量
	* 戻り値：なし
	============================================================*/
	void refuel(double df) {

		if (df > 0) {
			remainingFuel += df;

			if (remaingFuel > tankCapa) {
				remaingFuel = tankCapa;
			}
		}
	}
};