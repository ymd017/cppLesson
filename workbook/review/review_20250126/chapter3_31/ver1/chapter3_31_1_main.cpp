/*
* ��蕶�F
* 2���̐����l(10~99)�𓖂Ă����鐔���ăQ�[�����쐬����B
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chapter3_31_1.h"
using namespace std;

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �ϐ��錾��
	Game game;
	int nextGameFlg;

	// �Q�[�����X�^�[�g������
	do {
		nextGameFlg = 0;
		game.playGame();

		// �Q�[�����J��Ԃ�������
		cout << "������x�V�т܂����H(1:�V��, 0:�I������)\n";
		cin >> nextGameFlg;
	} while (nextGameFlg == 1);// �t���O��1�Ȃ�J��Ԃ�
	

}