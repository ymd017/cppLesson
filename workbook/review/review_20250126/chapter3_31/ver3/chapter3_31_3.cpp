#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chapter3_31_3.h"
using namespace std;

// ���[�U�[�̎����͂���
int User::setNum(){
	do {
		cout << "�o�������͂��Ă��������B\n";
		cout << "�O�[:0, �`���L:1, �p�[:2\n\n";
		cin >> num;
		cout << "\n";

	} while (num < 0 || 2 < num ); // 0~2�łȂ��ꍇ�͓��͂�������
	

	// �o�����ԋp����
	return num;
}

// �R���s���[�^�̎��ݒ肷��
int Computer::setNum() {
	num = rand() % 3;

	// �o�����ԋp����
	return num;
}

// Game�R���X�g���N�^
Game::Game() {
	userWin = 0;
	comWin = 0;
}

// �o�������\������
void Game::outputHand(int handNum) {
	switch (handNum) {
	case 0:
		cout << "�O�[\n";
		break;
	case 1:
		cout << "�`���L\n";
		break;
	case 2:
		cout << "�p�[\n";
		break;
	default:
		cout << "�G���[�F���\���ł��܂���ł���8\n";
	}
}

// �R���s���[�^�̎���o�͂���
void Game::outputComHand(int cnum) {
	cout << "�R���s���[�^�̎�:";
	outputHand(cnum);
}

// ���[�U�[�̎���o�͂���
void Game::outputUserHand(int unum) {
	cout << "���Ȃ��̎�:";
	outputHand(unum);
	cout << "\n";
}


// ���s�����߂�
// ���������Z����
void Game::judgeWin(int unum, int cnum) {

	// ���s�����߂�
	diff = (unum - cnum + 3) % 3;

	// ���������Z����
	switch (diff) {
	case 0:
		cout << "���������ł��B\n\n";
		break;
	case 1:
		cout << "�R���s���[�^�̏����ł��B\n\n";
		comWin++;
		break;
	case 2:
		cout << "���Ȃ��̏����ł��B\n\n";
		userWin++;
		break;
	default:
		cout << "�G���[�F���s�𔻒�ł��܂���ł����B\n\n";
	}
}

// �Q�[���i�s
void Game::playGame() {
	// �ϐ��錾��
	int userNum;
	int comNum;
	Computer com;
	User user;

	// rand()�p�̃V�[�h�l�̐ݒ�
	srand(time(NULL));

	// �����̏�����
	userWin = 0;
	comWin = 0;

	// �Q�[���X�^�[�g�̏o��
	cout << "�Q�[���X�^�[�g�I\n\n";

	do {
		// �R���s���[�^�̎��ݒ肷��
		comNum = com.setNum();

		// ���[�U�[�̎����͂���
		userNum = user.setNum();

		// �R���s���[�^�̎���o�͂���
		outputComHand(comNum);

		// ���[�U�[�̎���o�͂���
		outputUserHand(userNum);

		// ���s�����߂�
		// ���������Z����
		judgeWin(userNum, comNum);
	} while (comWin < 3 && userWin < 3);	// �ǂ��炩�����3�񏟂܂ő�����

	// ���ʂ̏o��
	cout << "**����**\n";
	if (userWin > comWin) {
		cout << "���Ȃ��̏���\n";
	}
	else {
		cout << "�R���s���[�^�̏���\n";
	}
}

Retry::Retry() {
	retryFlg = 0;
}

bool Retry::askPlaying() {

	do {
		cout << "������x�V�т܂����H(1:�V�� / 0:�V�΂Ȃ�)\n";
		cin >> retryFlg;
	} while (retryFlg != 0 && retryFlg != 1);

	// 0�ŗV�΂Ȃ��Ƃ���false, 1�ŗV�ԂƂ���true��ԋp����
	if (retryFlg == 0) {
		return false;
	}
	else {
		return true;
	}
}
