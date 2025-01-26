#include <iostream>

/*
* ��蕶�F
* �w�b�_���݂̂Ŏ������ꂽ�����ԃN���XCar���쐬����B
* ���O�A�i���o�[�A���A�����A�����A���݈ʒu���W(x���W�Ay���W)�A�R��A�^���N�ʁA�c��R��
* �̃f�[�^�����o���������邱�ƁB
* �܂��A���W�𒲂ׂ�A�����Ԃ��ړ�����A��������Ƃ��������Ƃ��s�������o�֐����`���邱�ƁB
*/

class Car {
private:
	std::string name;			// ���O
	int num;					// �i���o�[
	int width;					// ��
	int height;					// ����
	int length;					// ����
	double xpos;				// x���W
	double ypos;				// y���W
	double fuelEco;				// �R��(�P�ʋ���������ɏ����R��)
	double tankCapa;			// �^���N��
	double remainingFuel;		// �c��R��

public:
	// �R���X�g���N�^
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

	// x���W�𒲂ׂ�
	double getXpos(){
		return xpos;
	}

	// y���W�𒲂ׂ�
	double getYpos() {
		return ypos;
	}

	/*============================================================
	* �����Ԃ��ړ�����֐�
	* �����@�Fdouble dx			x���W�ړ���
	* �����@�Fdouble dy			y���W�ړ���
	* �߂�l�Fbool				�ړ��������������ǂ����̔���
	============================================================*/
	void translate(double dx, double dy) {

		// �ϐ��錾��
		double dist;
		double necessaryFuel;

		// �ړ����������߂�
		dist = sqrt((dx * dx) + (dy * dy));

		// ������R�������߂�
		necessaryFuel = dist / fuelEco;

		// �c��R������������R�����������false��Ԃ�
		if (necessaryFuel > remaingFuel) {
			return false;
		}
		else {
			// �c��̔R������A�ړ��ɂ��������R���������炷
			remaingFuel -= necessaryFuel;
			
			// ���Wx,y�ɂ��ꂼ��ړ��ʂ����Z����
			xpos += dx;
			ypos += dy;

			return true;
		}
	}

	/*============================================================
	* �����֐�
	* �����@�Fdouble df			������
	* �߂�l�F�Ȃ�
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