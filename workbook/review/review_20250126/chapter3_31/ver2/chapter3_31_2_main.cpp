/*
* �w�b�_�t�@�C�����N���X�̒�`
* �����o�֐���`�p�̃\�[�X�t�@�C��
* main()�̃\�[�X�t�@�C���̓I�u�W�F�N�g�����āA�����o�֐����g��
*/

#include <iostream>
#include "chapter3_31_2.h"
using namespace std;

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main(){

	// �ϐ��錾��
	Game game1;
	Retry retry1;
	int nextPlayFlg;

	game1.play();

	do {
		// �Q�[��������
		game1.play();

		// ������x�V�Ԃ��q�˂�
		// �V�ԏꍇ�͓����̐����l�����߂�Ƃ��납��J��Ԃ�
		// �V�΂Ȃ��ꍇ�͏I������
		nextPlayFlg = 0;
		nextPlayFlg = retry1.askPlaying();
	} while (nextPlayFlg == 1);		// �t���O��1�Ȃ�J��Ԃ�

	return 0;
}
