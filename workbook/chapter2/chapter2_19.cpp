/*
* ��蕶�F
* ���݂����v���O�������쐬����B
* �����������āA��g�A���g�A���g�A�g�A���g�A���A�勥�̂����ꂩ��\�����邱�ƁB
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
	num = rand() % 7;

	switch (num) {
	case 0:
		ans = "��g";
		break;
	case 1:
		ans = "���g";
		break;
	case 2:
		ans = "���g";
		break;
	case 3:
		ans = "�g";
		break;
	case 4:
		ans = "���g";
			break;
	case 5:
		ans = "��";
			break;
	case 6:
		ans = "�勥";
		break;
	}

	// �o�͂���
	cout << ans << "\n";
}