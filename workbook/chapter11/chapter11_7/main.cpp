/*
* Human�N���X���쐬���A�����o�ϐ��ɖ��O�ƁA�a��������������B
* �Q�b�^�[�ƃZ�b�^�[���p�ӂ���B
* �a������chapter11_4��Date�N���X���g�p���邱�ƁB
*/

#include <iostream>
#include "Date.h"
#include "human.h"
using namespace std;


/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	Human taro("taro", Date(2000, 4, 1));
	Date birthday = taro.getBirthday();
	cout << birthday.toString();

	
}