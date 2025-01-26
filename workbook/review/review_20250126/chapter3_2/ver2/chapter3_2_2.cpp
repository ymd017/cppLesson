#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chapter3_2_2.h"
using namespace std;

int Player::setNum() {

	// �v���C���[��������
	cin >> num;

	return num;
}

int Answer::setAns() {

	// �V�[�h�l
	srand(time(NULL));

	// �����̐����l�����߂�
	ans = rand() % 90 + 10;

	return ans;
}

bool Judgement::judgeAns(int num, int ans) {
	// ���������肷��
	// �������́u�����I�v�Ɠ������o���B
	// �s�����Ȃ�A�召���r���āA�u�傫���v�u�������v�ƃ��b�Z�[�W���o���B
	// �����̂Ƃ��������肵�āA���̑傫�����傫����΁u�����Ɓv�A��������΁u���������v�ƕt����

	if (num == ans) {
		cout << "�����I\n";

		// ���ʂ�ԋp����
		return true;
	}
	else {
		// �������߂�
		diff = num - ans;

		if (diff > 0) {	// �v���C���[���I�񂾐��l���������傫���Ƃ�
			if (diff >= 10) {	// ����10�ȏ�̎�
				cout << "�����Ə����Ȑ��ł��B\n";
			}
			else {	// ����10��菬�����Ƃ�
				cout << "�������������Ȑ��ł��B\n";
			}
		}
		else {			// �v���C���[���I�񂾐��l�����������������Ƃ�
			// ���𐳂ɂ���
			diff *= -1;
			if (diff >= 10) {	// ����10�ȏ�̎�
				cout << "�����Ƒ傫�Ȑ��ł��B\n";
			}
			else {	// ����10��菬�����Ƃ�
				cout << "���������傫�Ȑ��ł��B\n";
			}
		}

		// ���ʂ�ԋp����
		return false;
	}
}

void Game::play() {

	// ��蕶�̕\��
	cout << "10~99�̐����l�𓖂ĂĂ��������B\n";

	// �����̐����l�����߂�
	ans = answer.setAns();

	do {
		// �v���C���[��������
		num = player.setNum();

		// ���������肷��
		// �������́u�����I�v�Ɠ������o���B
		// �s�����Ȃ�A�v���C���[��������̂��J��Ԃ�
		// �召���r���āA�u�傫���v�u�������v�ƃ��b�Z�[�W���o���B
		// �����̂Ƃ��������肵�āA���̑傫�����傫����΁u�����Ɓv�A��������΁u���������v�ƕt����
		result = judgement.judgeAns(num, ans);

	} while (result == false);
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
