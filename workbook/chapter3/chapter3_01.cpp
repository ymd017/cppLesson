/*
* ��蕶�F
* �ǂݍ��񂾐����l�̕�����Ԃ��v���O�������쐬����B
* ���x�ł����͂ƕ\��������邱�ƁB
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
	int num;		// �ǂݍ��񂾐����l
	char retryChar;		// �������邩�ǂ����̓���
	char retryFlg;		// ���������̃t���O

	do {
		// ���������t���O�̃��Z�b�g
		retryFlg = 0;

		// �����l�̓���
		cout << "�����l����͂��Ă�������\n";
		cin >> num;

		// �����𔻒肵�āA�o�͂���
		if (num > 0) {
			cout << "���̒l�͐��ł��B\n";
		}
		else if (num < 0) {
			cout << "���̒l�͕��ł��B\n";
		}
		else {
			cout << "���̒l��0�ł��B\n";
		}

		// �J��Ԃ����ǂ�������͂�����
		// �����������邩�̔��������
		do {
			cout << "������x���܂���(y�F���@/�@n�F���Ȃ�)\n";
			cin >> retryChar;

			if (retryChar == 'y' || retryChar == 'Y') {
				retryFlg = 1;
			}

		} while (retryChar != 'y' && retryChar != 'Y'
			&& retryChar != 'n' && retryChar != 'N');		// ���͂�y, Y, n, N�ȊO�Ȃ���͂�������

	} while (retryFlg == 1);			// �t���O��'y'��'Y'�Ȃ�J��Ԃ�
}