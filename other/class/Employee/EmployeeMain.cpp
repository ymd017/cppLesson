/*
* �w�b�_�t�@�C�����N���X�̒�`
* �����o�֐���`�p�̃\�[�X�t�@�C��
* main()�̃\�[�X�t�@�C���̓I�u�W�F�N�g�����āA�����o�֐����g��
*/

#include <iostream>
#include "Employee.h"
/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main(){

	Employee tanaka;

	tanaka.setNumber(1234);
	//tanaka.setName("�c����Y");
	tanaka.setSalary(200000);

	tanaka.showData();
}
