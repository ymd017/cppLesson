/*
* 1���ԃL�[�{�[�h�ƃ}�E�X�̗��������삳��Ȃ�������A�X���[�v��Ԃɂ���
*/

#include <iostream>
#include <windows.h>
#include <winnt.h>
#include <powrprof.h>
#include <winuser.h>
#include <thread>
#pragma comment(lib, "powrprof.lib")
using namespace std;

// ���삳��Ă��Ȃ����Ԃ�Ԃ��֐�
DWORD getIdleTime() {
	// �ϐ��錾��
	DWORD idleTime;		// ���߂鑀�삳��ĂȂ�����

	// �Ō�̓��͂̎����f�[�^(dwTime�����o)�����\���̂̐���
	LASTINPUTINFO lii;

	// �\���̃����o�ɒl��ݒ肷��
	lii.cbSize = sizeof(LASTINPUTINFO);		// �o�[�W��������p

	GetLastInputInfo(&lii);					// �e�B�b�N�J�E���g�iPC�N������̌o�ߎ��ԁj�A1�b��1000

	// ���삳��ĂȂ����Ԃ����߂�
	idleTime = static_cast<DWORD>(GetTickCount64()) - lii.dwTime;

	// ���삳��ĂȂ����Ԃ�Ԃ�
	return idleTime;
}

// PC���X���[�v��Ԃɂ��������L���ɂ���֐�
void enableSleepPrivilege() {
	// �g�[�N���n���h���̍쐬
	HANDLE hToken;

	TOKEN_PRIVILEGES tp;

	// OpenProcessToken�֐��ŁA���݂̃v���Z�X�i���s���̂��̃v���O�����j��n���A�����̃A�N�Z�X�g�[�N�������炤�B
	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);
	tp.PrivilegeCount = 1;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	// AdjustTokenPrivileges�֐��ŁA���݂̃v���Z�X�̃A�N�Z�X�g�[�N����L���ɂ���
	AdjustTokenPrivileges(&hToken, false, &tp, 0, NULL, NULL);

	// �g�[�N�������
	CloseHandle(hToken);
}

// �X���[�v�O�ʒm������֐�
void warning() {
	MessageBox(NULL, TEXT("���������X���[�v��ԂɂȂ�܂�"), TEXT("�ʒm"), MB_OK);
}

int main() {

	// �ϐ��錾��
	DWORD idleThreshold = 3600000;	// �X���[�v�̂������l�ƂȂ鎞�Ԃ̐ݒ�i�~���b�j�@1����
	DWORD idleTime;								// �L�[�{�[�h�ƃ}�E�X�����삳��ĂȂ�����
	DWORD warningTime = idleThreshold - 60000;					// 1��
	bool warningShown = false;

	// ���m
	cout << "1���Ԉȏ�L�[�{�[�h�ƃ}�E�X�����삳��Ȃ���΁A�X���[�v���܂��B\n";

	while (true) {

		// �L�[�{�[�h���ƃ}�E�X���̖����쎞�Ԃ��擾
		idleTime = getIdleTime();

		// �����쎞�Ԃ̕\��
		//cout << "�������܂̖����쎞�ԁF " << (idleTime / 1000 / 60) << "��\n";
		cout << "�������܂̖����쎞�ԁF " << (idleTime / 1000 ) << "�b\n";

		// 1���O�Ȃ�X���[�v�O�ʒm���o��
		if (idleTime > warningTime && warningShown == false) {
			thread warningMsg(warning);
			warningMsg.detach();
			warningShown = true;
		}

		// ���삳��ĂȂ����Ԃ��������l�̎��Ԉȏ�ɂȂ�΁A PC���X���[�v��Ԃɂ���
		if (idleTime > idleThreshold) {
			enableSleepPrivilege();

			cout << "1���Ԗ����삾�������߁A�X���[�v���܂��B\n";
			SetSuspendState(false, false, false);
			break;
		}

		// 1�����ƂɌJ��Ԃ�
		Sleep(5000);
	}
}