/*
* ��蕶�F
* ���O�A�g���A�̏d�������o�Ƃ��Ď��l�ԃN���X���`����
*/

#include <iostream>
using namespace std;

class Human {
public:
	string name;	// ���O
	int height;		// �g��
	int weight;		// �̏d
};

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	Human mori;
	Human hayashi;

	mori.name = "�X";
	hayashi.name = "��";

	mori.height = 170;
	hayashi.height = 150;

	mori.weight = 60;
	hayashi.weight = 45;

	cout << "���O�F" << mori.name << "�A�g���F" << mori.height << "�A�̏d�F" << mori.weight << "\n";
	cout << "���O�F" << hayashi.name << "�A�g���F" << hayashi.height << "�A�̏d�F" << hayashi.weight << "\n";
}
