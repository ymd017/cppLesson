/*
* ��蕶�F
* ����1~12�̐����l�Ƃ��ēǂݍ���ŁA����ɑΉ�����G�߂�\������v���O�������쐬����B
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
	int month;
	string season;

	// ������͂���
	cout << "������͂��Ă��������B\n";
	cin >> month;

	// �o�͂���G�߂�season�Ɋi�[����
	switch (month) {
	case 3: case 4: case 5:
		season = "�t";
		break;
	case 6: case 7: case 8:
		season = "��";
		break;
	case 9: case 10: case 11:
		season = "�H";
		break;
	case 12: case 1: case 2:
		season = "�~";
		break;
	}

	// �o�͂���
	cout << month << "����" << season << "�ł��B\n";
}