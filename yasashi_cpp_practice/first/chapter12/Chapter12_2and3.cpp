#include <iostream>
using namespace std;

class Point {
private:
	int x;		// X���W(0~10�͈̔�)
	int y;		// Y���W(0~10�͈̔�)

public:

	// x���W��������֐�
	void setX(int a) {
		if (a >= 0 && a <= 10) {
			x = a;
		}
		else {
			cout << a << "��0~10�͈̔͊O�Ȃ̂ő���ł��܂���B\n";
		}
	}

	// y���W��������֐�
	void setY(int b) {
		if (b >= 0 && b <= 10) {
			y = b;
		}
		else {
			cout << b << "��0~10�͈̔͊O�Ȃ̂ő���ł��܂���B\n";
		}
	}

	// x���W��Ԃ��֐�
	int getX() {
		return x;
	}

	// y���W��Ԃ��֐�
	int getY() {
		return y;
	}
};

/*============================================================
* �I�u�W�F�N�g�̃|�C���^���󂯎���āA���W��Ԃ��֐�
* �����@�FPoint* pPoint		Point�̃I�u�W�F�N�g�̃|�C���^
* �߂�l�F�Ȃ�
============================================================*/
void outputPos(Point* pPoint) {
	cout << "���W��(" << pPoint->getX() << "," << pPoint->getY() << ")�ł��B\n";
}

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �ϐ��錾��
	Point point1;
	int a;
	int b;

	// �f�[�^�����o�ɑ������
	cout << "x���W����͂��Ă��������B\n";
	cin >> a;
	point1.setX(a);

	cout << "y���W����͂��Ă��������B\n";
	cin >> b;
	point1.setY(b);

	// ���W�̏o��
	outputPos(&point1);
}
