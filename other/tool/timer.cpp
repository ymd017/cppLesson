/*
*
*/

#include <iostream>
#include <windows.h>
#include <sysinfoapi.h>
#include <winuser.h>
using namespace std;

/*============================================================================
* �^�C�}�[���X�^�[�g���A�X�^�[�g���̃e�B�b�N�J�E���g��ԋp����֐�
* �����F�Ȃ�
* �߂�l�FDWORD			�X�^�[�g���̃e�B�b�N�J�E���g
============================================================================*/
DWORD start() {

	// �ϐ��錾��
	char startSign;

	// �X�^�[�g�̍��}����͂�����
	// ���͂�a�Ȃ�e�B�b�N�J�E���g��Ԃ��A���̌�̏���������
	// ���͂�a�łȂ��Ȃ�A-1��Ԃ��A���̌�̏����������Ȃ�
	cout << "a�������ƁA60���Ԃ̃^�C�}�[���J�n���܂��B\n";
	cin >> startSign;
	if (startSign == 'a') {
		// �X�^�[�g�ʒm
		cout << "\n�w�K���X�^�[�g���܂���\n";
		cout << "-------------------------------\n";

		// �X�^�[�g���̃e�B�b�N�J�E���g���擾���ĕԋp����
		return GetTickCount64();
	}
	else {
		return 0;
	}

}


/*============================================================================
* �I���܂ŁA���Ԃ��v��A�ݒ莞�Ԃ𒴂�����I���t���O��Ԃ��֐�
* �����@�FDWORD startTime			�X�^�[�g���̃e�B�b�N�J�E���g
* �߂�l�Fbool						�I���ʒm�t���O
============================================================================*/
bool measureTime(DWORD startTime) {

	// �ϐ��錾��
	DWORD currentTime;
	DWORD diff;

	while (true) {
		// ���݂̃e�B�b�N�J�E���g���擾����
		currentTime = GetTickCount64();

		// ���݂ƃX�^�[�g���̃e�B�b�N�J�E���g�̍��������߂�
		diff = currentTime - startTime;

		// �e�B�b�N�J�E���g�̍�����60���𒴂��Ă��邩���肷��
		// �����Ă��Ȃ��Ȃ�A���݂̃e�B�b�N�J�E���g���擾����Ƃ��납��J��Ԃ�
		//if (diff >= 3600000) {
			//return true;
		//}
		if (diff >= 10000) {
			return true;
		}
		else {
			// ���݂̌o�ߎ��Ԃ�\������
		// cout << (diff / 60000) << "���o��\n";
			cout << (diff / 1000) << "�b�o��\n";

			// 1�����Ƃɔ��肷��
			//Sleep(60000);
			Sleep(5000);
		}
	}
}

/*============================================================================
* �I���ʒm������֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================================*/
void notifiTheEnd() {
	// �I���ʒm������
	cout << "-------------------------------\n";
	cout << "�I��\n\n";
	MessageBox(NULL, TEXT("�I�����܂���"), TEXT("�I���ʒm"), MB_OK);
}


int main() {

	while (true) {
		// �ϐ��錾��
		DWORD startTime = 0;
		bool finished = false;

		// �^�C�}�[���X�^�[�g���A�X�^�[�g���̃e�B�b�N�J�E���g��ԋp����
		startTime = start();

		// startTime��0�Ȃ炻�̌�̏����͂��Ȃ�
		if (startTime != 0) {
			// �I���܂ŁA���Ԃ��v��A�ݒ莞�Ԃ𒴂�����I���t���O��Ԃ�
			finished = measureTime(startTime);

			// �I���ʒm������
			notifiTheEnd();
		}
	}
}