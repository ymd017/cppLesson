/*
* ��蕶�F
* ������str�Ɋ܂܂�镶��ch�̌���Ԃ��֐�strch_cnt���쐬����B
*/

#include <iostream>
using namespace std;

int strch_cnt(const char* str, char ch);

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �ϐ��錾��
	char str[20];
	char ch;
	int num;

	// ������̓���
	cout << "���������͂��Ă�������\n";
	cin >> str;

	// �������镶���̓���
	cout << "�������镶������͂��Ă�������\n";
	cin >> ch;

	// ������str�Ɋ܂܂�镶��ch�̌���Ԃ��֐��̎g�p
	num = strch_cnt(str, ch);

	// ���̏o��
	cout << ch << "��" << num << "�܂܂�Ă��܂���\n";
}

int strch_cnt(const char* str, char ch) {

	// �ϐ��錾��
	int num = 0;		// �����Ώە�����������Ɋ܂܂�Ă����
	const char* i;			// ���[�v�C���f�b�N�X

	// �����Ώۂ̕���������������Ɋ܂܂�Ă��邩�𐔂���
	// for���ő������A�ꕶ������if���Œ��ׂ�
	// �����Ώە����ł���΁Anum��1���₷
	for (i = str; *str != '\0'; str++) {
		if (*str == ch) {
			num++;
		}
	}

	// ����ԋp����
	return num;
}