#include <iostream>
#include <typeinfo>
using namespace std;

/*
* ��蕶�F
* �O��̃v���O������ n, &n, ptr, *ptr, &ptr�̌^����\������v���O�������쐬����B
*
* (�O��)
* int*�^�̃|�C���^ptr���Aint�^�I�u�W�F�N�gn���w���悤�ɏ���������ƂƂ��ɁA
* n, &n, ptr, *ptr, &ptr�̒l��\������v���O�������쐬����B
*/


/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// n�̏�����
	int n = 5;

	// �|�C���^�̏�����
	int* ptr = &n;

	// �e�l���o�͂���
	cout << "n: " << typeid(n).name() << "\n";
	cout << "&n: " << typeid(&n).name() << "\n";
	cout << "ptr: " << typeid(ptr).name() << "\n";
	cout << "*ptr: " << typeid(*ptr).name() << "\n";
	cout << "&ptr: " << typeid(&ptr).name() << "\n";
}
