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
	int rangeMin;
	int rangeMax;
	int rangeStep;
	int height;
	int weight;

	// �\������g���͈̔́i�J�n�l�A�I���l�A�����j�̓���
	cout << "�\������g���̊J�n�l�F";
	cin >> rangeMin;
	cout << "�\������g���̏I���l�F";
	cin >> rangeMax;
	cout << "�\������g���̑����F";
	cin >> rangeStep;

	cout << "-------------------------------------\n";

	// �g���ƕW���̏d��\������
	// �\�̍��ږ����o�͂���
	// for���Őg��height����͂����J�n�l����I���l�܂ŁA�X�e�b�v�̐��������₵�Ȃ��瑖������B
	// �e��ł��̉�̐g���̒l�ɑΉ������W���̏d�����߂�
	// �g���ƕW���̏d��\�̌`�ŏo�͂���B

	cout << setw(10) << "�g��" << setw(10) << "�W���̏d" << "\n";

	for (height = rangeMin; height <= rangeMax; height += rangeStep) {

		weight = (height - 100) * 0.9;

		cout << setw(10) << height << setw(10) << weight << "\n";
	}


}