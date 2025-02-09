/*
���: �}�`�̊Ǘ��V�X�e�����쐬����
�v��
1.Point �N���X
x, y ���W�������A���Z + ���Z�q���I�[�o�[���[�h����B

2.Shape �N���X�i���ۃN���X�j
draw() �֐����������z�֐��Ƃ��Ē�`����B
clone() �֐����`���A���I�ɃI�u�W�F�N�g�𕡐��ł���悤�ɂ���B

3.Circle �N���X�iShape ���p���j
���a�ƒ��S���W�����B
draw() ���I�[�o�[���C�h���ĉ~��`�悷��i�����ł͋^���I�ȏo�́j�B
�R�s�[�R���X�g���N�^�Ƒ�����Z�q���`����B

4.Rectangle �N���X�iShape ���p���j
���E�����E����̍��W�����B
draw() ���I�[�o�[���C�h���Ē����`��`�悷��B
�R�s�[�R���X�g���N�^�Ƒ�����Z�q���`����B

5.ShapeContainer<T> �e���v���[�g�N���X
���܂��܂� Shape �I�u�W�F�N�g�𓮓I�ɊǗ�����B
addShape() ���\�b�h�� Shape ��ǉ��B
printAllShapes() �� draw() ���Ăяo���B
�R�s�[�R���X�g���N�^�Ƒ�����Z�q��K�؂ɊǗ��B
*/

#include <iostream>
#include <vector>
#include "Shape.h"
using namespace std;

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �V�F�C�v���i�[����z��̗p��
	// �z��v�f�̌^�͒��ۃN���XShape�̃|�C���^
	ShapeContainer<Shape> container;

	Circle c1(5, Point(2, 3));
	Rectangle r1(10, 5, Point(0, 0));

	container.addShape(&c1);
	container.addShape(&r1);

	container.printAllShapes();

	return 0;
}