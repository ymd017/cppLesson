/*
* �w�b�_�t�@�C�����N���X�̒�`
* �����o�֐���`�p�̃\�[�X�t�@�C��
* main()�̃\�[�X�t�@�C���̓I�u�W�F�N�g�����āA�����o�֐����g��
*/

#include <iostream>
#include "Employee2.h"

using namespace std;
/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main(){

	Employee2 person[3];

	person[0].setNumber(1111);
	person[0].setSalary(100000);
	person[0].setName("�c��");

	person[1].setNumber(2222);
	person[1].setSalary(200000);
	person[1].setName("����");

	person[2].setNumber(3333);
	person[2].setSalary(300000);
	person[2].setName("����");

	for (int i = 0; i < 3; i++) {
		person[i].showData();
	}
}
