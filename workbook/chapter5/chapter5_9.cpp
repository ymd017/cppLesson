#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

/* 
* ��蕶�F
* �z��̗v�f�̕��т��V���b�t������v���O���~���O���쐬����B
*/

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �z��̗v�f��������������
	const int n = 15;

	// �z��̃��������m�ۂ���
	int a[n];

	// �z��v�f�ɁA�e�C���f�b�N�X�̒l��v�f�̒l�Ƃ��đ������
	// for���Ŕz��̐擪����Ō�܂ő������āA�C���f�b�N�X�������Ă���
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}

	//����̔z��̗v�f�̒l���o�͂���
	cout << "�V���b�t���O�̔z��\n";

	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << "\n";

	// �v�f�̕��т��V���b�t������
	// for���Ő擪����Ō�܂Ŕz��𑖍�����
	// �����_���Ɍ�����̃C���f�b�N�X��I��
	// �l����������
	srand(time(NULL));

	for (int i = 0; i < n; i++) {

		int idx;	// �����_���ɑI�񂾃C���f�b�N�X

		do {
			idx = rand() % n;	// �����_���ɃC���f�b�N�X��I��
		} while (idx == i);		// ������C���f�b�N�X�ƌ��݂̃C���f�b�N�X�������Ȃ�I�тȂ���
		
		int temp = a[i];		// �l�̌���
		a[i] = a[idx];
		a[idx] = temp;
	}

	// �V���b�t�����I��������Ƃ��o�͂���
	cout << "�V���b�t�����܂����B\n\n";


	// �V���t����̔z��̗v�f�̒l���o�͂���
	cout << "�V���b�t����̔z��\n";

	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
}
