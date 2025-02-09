/*
問題: 図形の管理システムを作成せよ
要件
1.Point クラス
x, y 座標を持ち、加算 + 演算子をオーバーロードする。

2.Shape クラス（抽象クラス）
draw() 関数を純粋仮想関数として定義する。
clone() 関数を定義し、動的にオブジェクトを複製できるようにする。

3.Circle クラス（Shape を継承）
半径と中心座標を持つ。
draw() をオーバーライドして円を描画する（ここでは疑似的な出力）。
コピーコンストラクタと代入演算子を定義する。

4.Rectangle クラス（Shape を継承）
幅・高さ・左上の座標を持つ。
draw() をオーバーライドして長方形を描画する。
コピーコンストラクタと代入演算子を定義する。

5.ShapeContainer<T> テンプレートクラス
さまざまな Shape オブジェクトを動的に管理する。
addShape() メソッドで Shape を追加。
printAllShapes() で draw() を呼び出す。
コピーコンストラクタと代入演算子を適切に管理。
*/

#include <iostream>
#include <vector>
#include "Shape.h"
using namespace std;

/*============================================================
* メイン関数
* 引数　：なし
* 戻り値：なし
============================================================*/
int main() {

	// シェイプを格納する配列の用意
	// 配列要素の型は抽象クラスShapeのポインタ
	ShapeContainer<Shape> container;

	Circle c1(5, Point(2, 3));
	Rectangle r1(10, 5, Point(0, 0));

	container.addShape(&c1);
	container.addShape(&r1);

	container.printAllShapes();

	return 0;
}