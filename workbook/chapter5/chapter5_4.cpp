#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main()
{
	//�v�f�^int, �v�f����6�̔z���錾����
	int a[6];

	//�S�v�f��1~10�̗����Ŗ��߂���
	srand(time(NULL));
	for (int i = 0; i < 6; i++)
	{
		a[i] = rand() % 10 + 1;
	}

	//�v�f���o�͂���
	for (int i = 0; i < 6; i++)
	{
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
}

