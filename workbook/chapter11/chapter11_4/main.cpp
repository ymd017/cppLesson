/*
* ����N�A���A���Ńf�[�^�����o�ō\�������A���t�N���X���쐬����B
* �N�A���A����3�̒l���󂯎��R���X�g���N�^���`����
* ���݂̓��t���ŏ���������f�t�H���g�R���X�g���N�^���`����
* �N���������o�̃Q�b�^���`����
* �O���̓��t��ԋp���郁���o�֐�preceding_day���`����
*/

#include <iostream>
#include "Date.h"
using namespace std;


/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	Date now;
	cout << now.toString() << "\n";
	cout << now.week() << "\n";

	Date newyearsDay(2025, 1, 1);
	Date yesterday = newyearsDay.preceding_day();
	cout << yesterday.toString();


	
}