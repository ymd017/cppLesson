/*
* ��蕶�F
* 0, 1, 2�̂����ꂩ�̒l�𗐐��������A0�ł���΁u�O�[�v�A
* 1�ł���΁u�`���L�v�A2�ł���΁u�p�[�v��\������v���O�������쐬����B
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �ϐ��錾��
	int num;
	string ans;

	// �V�[�h�l
	srand(time(NULL));

	// �����𐶐����A�\��������̂�ans�Ɋi�[����
	num = rand() % 3;

	switch (num) {
	case 0:
		ans = "�O�[";
		break;
	case 1:
		ans = "�`���L";
		break;
	case 2:
		ans = "�p�[";
		break;
	}

	// �o�͂���
	cout << ans << "\n";
}