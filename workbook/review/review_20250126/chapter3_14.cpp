/*
* ��蕶�F
* �g���Ƒ̏d�̑Ή��\��\������v���O�������쐬����B
* �\������g���͈̔́i�J�n�l�A�I���l�A�����j�́A�����l�Ƃ��ēǂݍ��ނ��ƁB
* 5�\�����邲�Ƃɉ��s���邱�ƁB
* ���W���̏d�́i�g��-100) �~ 0.9
*/

#include <iostream>
#include <iomanip>
using namespace std;

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �ϐ��錾��
	int height;
	double weight;
	int height_start;	// �g���\���̊J�n�l
	int height_last;	// �g���\���̏I���l
	int height_step;	// �g���\���̑���
	int outCount = 0;	// �o�͂�����

	// �g���J�n�l�ƏI���l�A��������͂���
	cout << "�\������g���̊J�n�l:";
	cin >> height_start;

	cout << "�\������g���̏I���l:";
	cin >> height_last;

	cout << "�\������g���̑���:";
	cin >> height_step;

	// �\���o�͂���
	// for���Őg���J�n�l����A�I���l�܂ŁA���͑����������₵�đ�������
	// ���efor���̉�ŁA�g����\������B�܂��A�W���̏d�����߂ďo�͂���B
	// ���efor���̉�ŁA�o�͂��������J�E���g���A5�̔{���ɂȂ������A���s������B
	for (height = height_start; height < height_last; height += height_step) {

		weight = (height - 100) * 0.9;

		cout << setw(4) << height << setw(8) << weight << "\n";
		
		outCount++;
		if ((outCount % 5) == 0) {
			cout << "\n";
		}

	}
}