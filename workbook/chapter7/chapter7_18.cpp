#include <iostream>
using namespace std;

/*
* ��蕶�F
* �v�f��n�̔z��a����p�ӂ���B
* key�Ɠ������S�v�f�̓Y����z��idx�Ɋi�[����֐�search_idx���쐬����B
* �ԋp����̂�key�Ɠ������v�f�̌��Ƃ���
*/

int search_idx(int* a, int* idx, int n, int key);

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	const int n = 8;					// �v�f��������������
	int a[] = { 0,2,7,0,3,6,0,5 };		// �z��a������������
	int key;							// ��������l
	int idx[n];							// key�Ɠ������S�v�f�̓Y�����i�[����z��
	int count;							// key�Ɠ������v�f�̌�


	// for���Ő擪����Ō�܂ő������āA�z��a��\������
	cout << "�z��a\n";
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << "\n";

	// �������镶���̓���
	cout << "�������鐮���l����͂��Ă��������B\n";
	cin >> key;

	// key�Ɠ������S�v�f�̓Y����z��idx�Ɋi�[����֐����g�p����
	count = search_idx(a, idx, n, key);

	// for���Ő擪����Ō�܂ő������āA�z��idx��\������B
	cout << "�z��a��" << key << "�̓Y���͎��̒ʂ�ł��B\n";
	for (int i = 0; i < count; i++) {
		cout << idx[i] << " ";
	}
	cout << "\n";
	
}

/*============================================================
* key�Ɠ������S�v�f�̓Y����z��idx�Ɋi�[����֐�
* �����@�Fint* a			�����x�[�X�ƂȂ�z��
* �����@�Fint* idx			key�Ɠ������v�f�̓Y�����i�[����z��
* �����@�Fint n				�z��̗v�f��
* �߂�l�Fkey				��������l
============================================================*/
int search_idx(int* a, int* idx, int n, int key) {

	int count = 0;		// key�Ɠ������v�f�̌�

	// for���Ő擪����Ō�܂ő�������
	// �v�f��key�Ɠ��������ǂ������肷��
	// key�Ɠ������ꍇ�͓Y����z��idx�̗v�f�ɑ������B�J�E���g�𑝂₷�B
	for (int i = 0; i < n; i++) {
		if (*(a + i) == key) {
			*idx++ = i;
			count++;
		}
	}

	return count;
}

