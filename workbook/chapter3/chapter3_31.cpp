/*
* ��蕶�F
* ����񂯂�v���O�������쐬����B
* �����ꂩ�����3�񏟂܂ŌJ��Ԃ���悤�ɂ���B
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string outputRPS(int num);

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �ϐ��錾��
	int cpWins;			// �R���s���[�^�̏�����
	int playerWins;		// �v���C���[�̏�����
	int cpNum;			// �R���s���[�^���I�񂾔ԍ�
	int playerNum;		// �v���C���[���I�񂾔ԍ�
	int diff;			// �R���s���[�^�ƃv���C���[�̑I�񂾔ԍ��̍���

	// �V�[�h�l
	srand(time(NULL));

	// ����񂯂�J�n�Əo�͂���
	cout << "����񂯂�J�n�I�ǂ��炩��3�񏟂ĂΏI�����܂��B\n\n";

	// do while���ŃR���s���[�^�[���A�l�Ԃ̏�����3��ɂȂ�܂Ŕ�������������B
	// 0~2�̗����𐶐����A�ϐ��Ɋi�[����B
	// �v���C���[��0(�O�[), 1(�`���L), 2(�p�[)����͂�����
	// �R���s���[�^�ƃv���C���[���I��ł������ʂ��o�͂���B0�Ȃ�O�[�A1�Ȃ�`���L�A2�Ȃ�p�[�Ƃ���B
	// 
	// �ǂ��炪�����Ă��邩�𔻒肷��B
	cpWins = 0;
	playerWins = 0;

	do {
		cpNum = rand() % 3;

		cout << "�����o���܂����H\n0(�O�[), 1(�`���L), 2(�p�[)\n";
		cin >> playerNum;
		cout << "\n";

		cout << "�R���s���[�^�F " << outputRPS(cpNum) << "\n";
		cout << "���Ȃ��F " << outputRPS(playerNum) << "\n";

		if (cpNum == 0) {
			if (playerNum == 2) {
				cout << "�� ���Ȃ��̏���\n\n";
				playerWins++;
			}
			else if (playerNum == 1) {
				cout << "�� �R���s���[�^�̏���\n\n";
				cpWins++;
			}
			else {
				cout << "�� ��������\n\n";
			}
		}
		else if (cpNum == 1) {
			if (playerNum == 0) {
				cout << "�� ���Ȃ��̏���\n\n";
				playerWins++;
			}
			else if (playerNum == 2) {
				cout << "�� �R���s���[�^�̏���\n\n";
				cpWins++;
			}
			else {
				cout << "�� ��������\n\n";
			}
		}
		else {	// cpNum == 2
			if (playerNum == 1) {
				cout << "�� ���Ȃ��̏���\n\n";
				playerWins++;
			}
			else if (playerNum == 0) {
				cout << "�� �R���s���[�^�̏���\n\n";
				cpWins++;
			}
			else {
				cout << "�� ��������\n\n";
			}
		}

	} while (cpWins < 3 && playerWins < 3);


	// ���s���o�͂���B
	cout << "------------------------------\n";
	if (playerWins > cpWins) {
		cout << "���Ȃ��̏����ł��B\n";
	}
	else {
		cout << "�R���s���[�^�̏����ł��B\n";
	}
}

string outputRPS(int num) {

	switch (num) {
	case 0:
		return "�O�[";
		break;
	case 1:
		return "�`���L";
		break;
	case 2:
		return "�p�[";
		break;
	}
}