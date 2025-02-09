#pragma once
#include <iostream>
#include <vector>

// �|�C���g�N���X
class Point {
private:
	int x;
	int y;
public:
	// �R���X�g���N�^
	Point(int xpos = 0, int ypos = 0) : x(xpos), y(ypos) {};

	// �{���Z�q�̃I�[�o�[���[�h
	Point operator+(const Point& pt1) {
		return Point((x + pt1.x), (y + pt1.y));
	}

	// �Z�b�^�[
	void setX(int xpos) {
		x = xpos;
	}

	void setY(int ypos) {
		y = ypos;
	}

	// �\��
	void print() {
		std::cout << "(" << x << "," << y << ")";
	}
};

// �V�F�C�v�N���X
class Shape {
public:
	// �`��ɂ��Ă̏������z�֐�
	virtual void draw() = 0;

	// ��������֐�
	virtual Shape* clone() = 0;

	// �f�X�g���N�^
	virtual ~Shape() {};
};

// �~�N���X
class Circle : public Shape {
private:
	double radius;
	Point center;
public:
	// �R���X�g���N�^
	Circle(double r, Point c) : radius(r), center(c) {}

	// �R�s�[�R���X�g���N�^
	Circle(const Circle& circ) : radius(circ.radius), center(circ.center){}

	// ������Z�q�̃I�[�o�[���[�h
	Circle& operator=(const Circle& circ) {
		if (this != &circ) {
			radius = circ.radius;
			center = circ.center;
		}
		return *this;
	}

	// �`�悷��֐�
	// print()�͊֐����̂��֐�������cout�o�͂�����́B
	void draw() override {
		std::cout << "���W";
		center.print();
		std::cout << "�ɁA���a" << radius << "�̉~���쐬���܂����B\n";
	}

	// �N���[���֐�
	Shape* clone() override {
		return new Circle(*this);
	}

};

// �l�p�`�N���X
class Rectangle : public Shape{
private:
	int width;
	int height;
	Point pos;
public:
	// �R���X�g���N�^
	Rectangle(int w, int h, Point p) : width(w), height(h), pos(p) {}

	// �R�s�[�R���X�g���N�^
	Rectangle(const Rectangle& rest) : width(rest.width), height(rest.height), pos(rest.pos) {}

	// ������Z�q�̃I�[�o�[���[�h
	Rectangle& operator=(const Rectangle& rest) {
		if (this != &rest) {
			width = rest.width;
			height = rest.height;
			pos = rest.pos;
		}
		return *this;
	}

	// �`�悷��֐�
	void draw() override {
		std::cout << "���W";
		pos.print();
		std::cout << "����ɁA��" << width << "�A����" << height << "�̎l�p�`���쐬���܂����B\n";
	}

	// �N���[���֐�
	Shape* clone() override {
		return new Rectangle(*this);
	}
};

// ShapeContainer�N���X
template <class T>
class ShapeContainer {
private:
	std::vector<T*> shapes;
public:
	ShapeContainer() = default;

	// �f�X�g���N�^
	~ShapeContainer() {
		for (T* shape : shapes) {
			delete shape;
		}
	}

	// �R�s�[�R���X�g���N�^
	// �v�f�̓|�C���^�Ȃ̂ŁA�������̂�V�K�̔z��ɓ������ƍ��邩��Aclone()����
	ShapeContainer(const ShapeContainer& other) {
		for (const T* shape : other.shapes) {
			shapes.push_back(dynamic_cast<T*>(shape->clone()));
		}
	}

	// �v�f�̒ǉ�
	void addShape(T* shape) {
		shapes.push_back(shape->clone());
	}
	// �S�v�f���o�͂���
	void printAllShapes() {
		for (T* shape : shapes) {
			shape->draw();
		}
	}
};