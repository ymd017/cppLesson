/*
* ��蕶�F
* 3��int�^����a,b,c�̒����l�����߂�֐�med���쐬����
*/

#include <iostream>
using namespace std;

int med(int a, int b, int c);

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �ϐ��錾��
	int medNum;
	int a;
	int b;
	int c;

	// 3�̐����l�̓���
	cout << "3�̐�������͂��Ă�������\n";
	cin >> a >> b >> c;

	// 3��int�^����a,b,c�̒����l�����߂�֐��̎g�p
	medNum = med(a, b, c);

	// �����l�̏o��
	cout << "�����l:" << medNum << "\n";

}

/*============================================================
* ���C���֐�
* �����@�Fint a		�����l�����߂�̂Ɏg�p���鐮���l
* �����@�Fint b		�����l�����߂�̂Ɏg�p���鐮���l
* �����@�Fint c		�����l�����߂�̂Ɏg�p���鐮���l
* �߂�l�Fint		�����l
============================================================*/
int med(int a, int b, int c) {

	// �ϐ��錾��
	int medNum;

	// ���ƈ�ʒu�����܂�΁A�召�֌W�̈ʒu���m�肷��󋵂ɂ���
	// �e�󋵂ł̒����l��med�Ɋi�[����
	if (a < b) {
		if (c < a) {
			medNum = a;
		}
		else if (b < c) {
			medNum = b;
		}
		else {
			medNum = c;
		}
	}
	else {	// b < a;
		if (c < b) {
			medNum = b;
		}
		else if (a < c) {
			medNum = a;
		}
		else {
			medNum = c;
		}
	}

	// �����l��ԋp����
	return medNum;
}