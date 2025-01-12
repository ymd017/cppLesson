#include <iostream>
#include <iomanip>
using namespace std;

/*
* ��蕶�F
* �v�f����n�ł���z��b�̐��̗v�f�݂̂�z��a�ɐ擪���珇�ɃR�s�[����֐����쐬����B
* �R�s�[�����v�f����ԋp���邱�ƁB
*/

int ary_plus_cpy(int* a, const int* b, int n);

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	const int n = 7;				// �z��̗v�f���̏�����
	int b[] = { 1,-2,3,4,-5,-6,7 };	// �z��b�̏�����
	int a[n];						// �z��a�̐錾
	int count;						// �z��a�ɃR�s�[�����v�f��

	// �z��b�̏o��
	cout << "�z��b : ";
	for (int i = 0; i < n; i++) {
		cout << setw(3) << b[i];
	}
	cout << "\n";

	// �v�f����n�ł���z��b�̑S�v�f��z��a�ɃR�s�[����֐��̎g�p
	count = ary_plus_cpy(a, b, n);

	// �z��a�̏o��
	cout << "�z��b�̐��̗v�f��z��a�ɃR�s�[���܂����B\n";

	cout << "�z��a : ";
	for (int i = 0; i < count; i++) {
		cout << setw(3) << a[i];
	}
	cout << "\n";
}

/*============================================================
* �v�f����n�ł���z��b�̑S�v�f��z��a�ɃR�s�[����֐�
* �����@�Fint* a			�R�s�[��̔z��
* �����@�Fconst int* b		�R�s�[���̔z��
* �����@�Fint n				�z��̗v�f��
* �߂�l�Fint				�R�s�[�����v�f��
============================================================*/
int ary_plus_cpy(int* a, const int* b, int n) {

	int count = 0;		// �R�s�[�����v�f��

	// for���ōŏ�����Ō�܂Ŕz��a��b�𑖍�����
	// b�̗v�f�����̗v�f�����肷��B
	// ���̗v�f�Ȃ�΁A�z��b�̗v�f�̒l�𓯂��C���f�b�N�X�̔z��a�̗v�f�ɑ�����Ă����B
	for (int i = 0; i < n; i++) {

		if (*(b + i) > 0) {
			*a++ = *(b + i);
			count++;
		}
	}

	return count;
}

