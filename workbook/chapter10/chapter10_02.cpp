/*
* ��蕶�F
* ���O�A�g���A�̏d�������o�Ƃ��Ď��l�ԃN���X���`����
*/

#include <iostream>
#include "chapter10_02.h"
using namespace std;

// �R���X�g���N�^
Human::Human(string n, int h, int w) {
	string name = n;
	int height = h;
	int weight = w;
}

// ����
void Human::growFat(int dw) {
	weight += dw;
}

// ������
void Human::slimOff(int dw) {
	weight -= dw;
}

int main() {

	Human mori("�X", 170, 60);
}
