/*
* ��蕶�F
* 2���̐����l(10~99)�𓖂Ă����鐔���ăQ�[�����쐬����B
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chapter3_31_3.h"
using namespace std;

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �ϐ��錾��
	Game game;
	Retry retry;

	// �Q�[�����X�^�[�g������
	do {
		game.playGame();

		// �Q�[�����J��Ԃ�������
		retry.askPlaying();

	} while (retry.getRetryFlg() == 1);// �t���O��1�Ȃ�J��Ԃ�
	

}