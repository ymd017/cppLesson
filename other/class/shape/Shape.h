#pragma once
#include <iostream>
#include <vector>

// ポイントクラス
class Point {
private:
	int x;
	int y;
public:
	// コンストラクタ
	Point(int xpos = 0, int ypos = 0) : x(xpos), y(ypos) {};

	// ＋演算子のオーバーロード
	Point operator+(const Point& pt1) {
		return Point((x + pt1.x), (y + pt1.y));
	}

	// セッター
	void setX(int xpos) {
		x = xpos;
	}

	void setY(int ypos) {
		y = ypos;
	}

	// 表示
	void print() {
		std::cout << "(" << x << "," << y << ")";
	}
};

// シェイプクラス
class Shape {
public:
	// 描画についての純粋仮想関数
	virtual void draw() = 0;

	// 複製する関数
	virtual Shape* clone() = 0;

	// デストラクタ
	virtual ~Shape() {};
};

// 円クラス
class Circle : public Shape {
private:
	double radius;
	Point center;
public:
	// コンストラクタ
	Circle(double r, Point c) : radius(r), center(c) {}

	// コピーコンストラクタ
	Circle(const Circle& circ) : radius(circ.radius), center(circ.center){}

	// 代入演算子のオーバーロード
	Circle& operator=(const Circle& circ) {
		if (this != &circ) {
			radius = circ.radius;
			center = circ.center;
		}
		return *this;
	}

	// 描画する関数
	// print()は関数自体が関数内部でcout出力するもの。
	void draw() override {
		std::cout << "座標";
		center.print();
		std::cout << "に、半径" << radius << "の円を作成しました。\n";
	}

	// クローン関数
	Shape* clone() override {
		return new Circle(*this);
	}

};

// 四角形クラス
class Rectangle : public Shape{
private:
	int width;
	int height;
	Point pos;
public:
	// コンストラクタ
	Rectangle(int w, int h, Point p) : width(w), height(h), pos(p) {}

	// コピーコンストラクタ
	Rectangle(const Rectangle& rest) : width(rest.width), height(rest.height), pos(rest.pos) {}

	// 代入演算子のオーバーロード
	Rectangle& operator=(const Rectangle& rest) {
		if (this != &rest) {
			width = rest.width;
			height = rest.height;
			pos = rest.pos;
		}
		return *this;
	}

	// 描画する関数
	void draw() override {
		std::cout << "座標";
		pos.print();
		std::cout << "を基準に、幅" << width << "、高さ" << height << "の四角形を作成しました。\n";
	}

	// クローン関数
	Shape* clone() override {
		return new Rectangle(*this);
	}
};

// ShapeContainerクラス
template <class T>
class ShapeContainer {
private:
	std::vector<T*> shapes;
public:
	ShapeContainer() = default;

	// デストラクタ
	~ShapeContainer() {
		for (T* shape : shapes) {
			delete shape;
		}
	}

	// コピーコンストラクタ
	// 要素はポインタなので、同じものを新規の配列に入れられると困るから、clone()する
	ShapeContainer(const ShapeContainer& other) {
		for (const T* shape : other.shapes) {
			shapes.push_back(dynamic_cast<T*>(shape->clone()));
		}
	}

	// 要素の追加
	void addShape(T* shape) {
		shapes.push_back(shape->clone());
	}
	// 全要素を出力する
	void printAllShapes() {
		for (T* shape : shapes) {
			shape->draw();
		}
	}
};