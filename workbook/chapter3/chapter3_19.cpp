/*
* ��蕶�F
* ����1~12�̐����l�Ƃ��ēǂݍ���ŁA����ɑΉ�����G�߂�\������v���O�������쐬����B
* ���̓ǂݍ��݂ɂ����āA1~12�ȊO�̐��l�����͂��ꂽ�ꍇ�͍ē��͂����邱�ƁB
* �܂��A�D���Ȃ������x�ł����́E�\���ł���悤�ɂ��邱�ƁB
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
	int inputFlg;
	int retryFlg;
	string season;

	do {
		// ���̓���
		do {
			// ���͂̂��������t���O�̏�����
			inputFlg = 0;

			cout << "������͂��Ă�������\n";
			cin >> month;

			if (month < 1 || month > 12) {
				cout << "1����12�܂ł̐����l����͂��Ă��������B\n";
				inputFlg = 1;
			}
		} while (inputFlg == 1);

		// ���ɑΉ�����G�߂�\������
		switch (month) {
		case 3: case 4: case 5:
			cout << month << "�͏t�ł��B";
			break;
		case 6: case 7: case 8:
			cout << month << "�͉Ăł��B";
			break;
		case 9: case 10: case 11:
			cout << month << "�͏H�ł��B";
			break;
		case 12: case 1: case 2:
			cout << month << "�͓~�ł��B";
			break;
		}

		// ������x��邩���肵�A�t���O�Ɋi�[����
		cout << "������x���܂����H(1�ő��s�A0�ŏI��)\n";
		cin >> retryFlg;

	} while (retryFlg == 1);

}