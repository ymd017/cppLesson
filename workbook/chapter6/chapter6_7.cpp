#include <iostream>
using namespace std;

/*
* ��蕶�F
* �w�肳�ꂽ�t���̋G�߂�\������֐�print_season���쐬����
* �t�F�R�C�S�C�T
* �āF�U�C�V�C�W
* �H�F�X�A�P�O�A�P�P
* �~�F�P�Q�A�P�A�Q
* ��L�ȊO�͉����\�����Ȃ�
*/

void print_season(int m);

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �G�߂̕ϐ���錾
	int m;

	// �G�߂���͂���
	cout << "������͂��Ă�������\n";
	cin >> m;

	// �����Ŏ󂯎�����������ƂɁA�G�߂��o�͂���֐����g�p����
	print_season(m);
}

/*============================================================
*  �����Ŏ󂯎�����������ƂɁA�G�߂��o�͂���֐�
* �����@�Fint m			��
* �߂�l�F�Ȃ�
============================================================*/
void print_season(int m) {

	switch (m){
		case 3: case 4: case 5:
			cout << "�G�߂͏t�ł��B\n";
			break;
		case 6: case 7: case 8:
			cout << "�G�߂͉Ăł��B\n";
			break;
		case 9: case 10: case 11:
			cout << "�G�߂͏H�ł��B\n";
			break;
		case 12: case 1: case 2:
			cout << "�G�߂͓~�ł��B\n";
			break;
	}
}