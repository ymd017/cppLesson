/*
* ��蕶�F
* �L������*����ׂāA������height�i�ŉ�����width�̕��s�l�ӌ`��\������v���O�������쐬����B
* �i��i�Ɖ��i�͐����ŁA���邽�т�1�����������ɂ���Ă����j
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
	int height;		// ����
	int width;		// ����
	int space;		// �X�y�[�X�̌�
	int i;			// ���[�v�C���f�b�N�X
	int j;			// ���[�v�C���f�b�N�X
	int k;			// ���[�v�C���f�b�N�X

	// height��width����͂���
	cout << "���s�l�ӌ`�̍����Ɖ�������͂��Ă�������\n";
	cout << "�����F";
	cin >> height;
	cout << "�����F";
	cin >> width;

	// space��0�ɂ���B
	space = 0;

	// for����i��1����height�܂ő�������
	// i�̊e��ŁAfor����j���X�y�[�X�̌������������āA�X�y�[�X��\������B
	// �����I�������Aspace��1���₷
	// i�̊e��ŁAfor����k��1����width�܂ő������A*��\������B
	// ���s����
	for (i = 1; i <= height; i++) {
		for (j = 0; j < space; j++) {
			cout << ' ';
		}

		space++;

		for (k = 1; k <= width; k++) {
			cout << '*';
		}

		cout << "\n";
	}


}