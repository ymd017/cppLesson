/*
* ��蕶�F
* �L�[�{�[�h����ǂݍ���3�̐����l�̒����l�����߂ĕ\������v���O�������쐬����
*/

#include <iostream>
using namespace std;

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �ϐ��錾��
	int med;
	int num1;
	int num2;
	int num3;

	// ���l�̓���
	cout << "������3���͂��Ă��������B\n";
	cin >> num1 >> num2 >> num3;

	// �����l�����߂�
	// �ꍇ���������A�召�̏��Ԃ����ƂP���܂�΁A���я����m�肷��󋵂ɂ���B
	// �c����ǂ��ɓ���邩�ŏꍇ��������B
	if (num 1 < num2) {
		if (num3 < num1) {
			med = num1;
		}
		else if (num2 < num3) {
			med = num2;
		}
		else {
			med = num3;
		}
	}
	else {					// num2 <= num1
		if (num3 < num2) {
			med = num2;
		}
		else if (num1 < num3) {
			med = num1;
		}
		else {
			med = num3;
		}
	}

	// �����l�̏o��
	cout << "�����l��" << med << "�ł��B\n";

}