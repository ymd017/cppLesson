/*
* ��蕶�F
* �v�f��n�̔z�񂩂�v�fa[idx]���폜����֐�aryrmv���쐬����B
* �폜��a[idx]������̑S�v�f��1�O���ɂ��炷���Ƃɂ���čs���B
* �����͈ړ������Ȃ��Ă悢�B
*/

#include <iostream>
using namespace std;

void aryrmv(int a[], int n, int idx);

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �ϐ��錾��
	const int n = 10;
	int a[n];
	int idx;		// �폜����v�f�̃C���f�b�N�X
	int i;			// ���[�v�C���f�b�N�X

	// �z��v�f�ɃC���f�b�N�X�̒l����������
	for (i = 0; i < n; i++) {
		a[i] = i;
	}

	// ���̔z��̏o��
	cout << "���̔z��\n";
	for (i = 0; i < n; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << "\n";

	// �폜����C���f�b�N�X�̓���
	cout << "�ǂ̃C���f�b�N�X���폜���܂���\n";
	cin >> idx;

	// �v�f��n�̔z�񂩂�v�fa[idx]���폜����֐��̎g�p
	aryrmv(a, n, idx);

	// �֐��g�p��̔z��̏o��
	cout << "�֐��g�p��̔z��\n";
	for (i = 0; i < n; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
}

void aryrmv(int a[], int n, int idx) {

	// �ϐ��錾��
	int i;			// ���[�v�C���f�b�N�X

	// idx�ȍ~�̃C���f�b�N�X�̒l��1���̃C���f�b�N�X�̒l�ɂ���B
	// �������A1���̒l�����݂��Ă���ꍇ�Ɍ���
	// for����idx�ȍ~�̒l�𑖍�����
	for (i = idx; i < n; i++) {
		if ((i + 1) < n) {
			a[i] = a[i + 1];
		}
	}
}