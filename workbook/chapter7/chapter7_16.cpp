#include <iostream>
#include <iomanip>
using namespace std;

/*
* ��蕶�F
* �v�f����n�ł���z��b�̑S�v�f��z��a�ɃR�s�[����֐����쐬����B
*/

void ary_cpy(int* a, const int* b, int n);

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	const int n = 7;				// �z��̗v�f���̏�����
	int b[] = { 1,2,3,4,5,6,7 };	// �z��b�̏�����
	int a[n];						// �z��a�̐錾

	// �z��b�̏o��
	cout << "�z��b : ";
	for (int i = 0; i < n; i++) {
		cout << setw(2) << b[i];
	}
	cout << "\n";

	// �v�f����n�ł���z��b�̑S�v�f��z��a�ɃR�s�[����֐��̎g�p
	ary_cpy(a, b, n);

	// �z��a�̏o��
	cout << "�z��b��z��a�ɃR�s�[���܂����B\n";

	cout << "�z��a : ";
	for (int i = 0; i < n; i++) {
		cout << setw(2) << a[i];
	}
	cout << "\n";
}

/*============================================================
* �v�f����n�ł���z��b�̑S�v�f��z��a�ɃR�s�[����֐�
* �����@�Fint* a			�R�s�[��̔z��
* �����@�Fconst int* b		�R�s�[���̔z��
* �����@�Fint n				�z��̗v�f��
* �߂�l�F�Ȃ�
============================================================*/
void ary_cpy(int* a, const int* b, int n) {

	// for���ōŏ�����Ō�܂Ŕz��a��b�𑖍�����
	// �z��b�̗v�f�̒l�𓯂��C���f�b�N�X�̔z��a�̗v�f�ɑ�����Ă����B
	for (int i = 0; i < n; i++) {
		*(a + i) = *(b + i);
	}

}