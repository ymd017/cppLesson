/*
* ��蕶�F
* �S�Ă̕����ɂ��āA�����A�p�啶���A�p�������A�L���������킩��ꗗ�\���o�͂���v���O�������쐬����
* ��ԍ��̗�ɕ����A2�Ԗڂɕ����R�[�h�A3�Ԗڂɕ�����ނ�\������
*/

#include <iostream>
#include <climits>
#include <cctype>
#include <iomanip>
using namespace std;

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �ϐ��錾��
	int i;			// ���[�v�C���f�b�N�X

	// for���ŕ����R�[�h�ɑ�������i���g���āACHAR_MIN����CHSR_MAX�܂őS�Ă̕����𑖍�����
	for (i = 0; i <= CHAR_MAX; i++) {
		// ��ԍ��̗�ɕ������o�͂���
		// �������o�͂ł�����̂��ǂ�����isprint(i)�ɂ���Ē��ׂ�
		// �����o�͂ł�����̂͂��̂܂܏o�͂��A�ł��Ȃ����̂̓X�y�[�X���o�͂���
		switch (i) {
		case '\a':
			cout << setw(4) << "\\a";
			break;
		case '\b':
			cout << setw(4) << "\\b";
			break;
		case '\f':
			cout << setw(4) << "\\f";
			break;
		case '\n':
			cout << setw(4) << "\\n";
			break;
		case '\r':
			cout << setw(4) << "\\r";
			break;
		case '\t':
			cout << setw(4) << "\\t";
			break;
		case '\v':
			cout << setw(4) << "\\v";
			break;
		default:
			if (isprint(i) != 0) {
				cout << setw(4) << static_cast<char>(i);
			}
			else {
				cout << setw(4) << ' ';
			}
			break;
		}

		// 2�Ԗڂ̗�ɕ����R�[�h�ɑ�������i��\������
		cout << setw(4) << hex <<  i;

		// if���Ɗe��֐��ŕ�����ނ���肵�A�o�͂���
		if (isspace(i) != 0) {
			cout << setw(16) << "�󔒗ޕ���" << "\n";
		}
		else if (isdigit(i) != 0) {
			cout << setw(16) << "��������" << "\n";
		}
		else if (islower(i) != 0) {
			cout << setw(16) << "�p������" << "\n";
		}
		else if (isupper(i) != 0) {
			cout << setw(16) << "�p�啶��" << "\n";
		}
		else if (ispunct(i) != 0) {
			cout << setw(16) << "�L������" << "\n";
		}
		else if (iscntrl(i) != 0) {
			cout << setw(16) << "���䕶��" << "\n";
		}
		else {
		}

		// �����R�[�h��CHAR_MAX�𒴂���ƃG���[�ɂȂ��Ă��܂��̂ŁAi��CHAR_MAX�ɂȂ�����̍Ō��break����
		if (i == CHAR_MAX) {
			break;
		}
	}
}