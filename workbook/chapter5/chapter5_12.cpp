#include <iostream>
using namespace std;

/* 
* ��蕶�F
* 6�l��2�Ȗځi����A���w�j�̓_����ǂݍ���ŁA
* �Ȗڂ��Ƃ̍��v�_�ƕ��ϓ_�A�w�����Ƃ̍��v�_�ƕ��ϓ_�����߂�v���O�������쐬����B
*/

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	int sum = 0;		// ���߂鍇�v�_
	double avg;		// ���߂镽�ϓ_
	const int num = 6;	// �w���̐l��
	const int sub = 2;	// ���Ȑ�
	string subname;	// ���Ȗ�

	// �s����g�p���āA�w���̓_�����Ǘ�����Bfor�̃l�X�g��p����B
	// ���͂���Ƃ��Ɋw���P�ʂœ��͂ł���ƕ֗��Ȃ̂ŁA����w��(0~5)�A�s���Ȗ�(0~1)�Ƃ���
	// �s���錾����
	int a[num][sub];


	// �s��ɒl����͂���
	for (int i = 0; i < num; i++) {
		cout << "�w��" << i + 1 << "�̓_������͂��Ă��������B\n";

		for (int j = 0; j < sub; j++) {
			switch (j) {
			case 0:
				subname = "����";
				break;

			case 1:
				subname = "���w";
				break;
			}

			cout << subname << ": ";
			cin >> a[i][j];
		}
	}
	cout << "\n";


	// �Ȗڂ��Ƃ̍��v�_�ƕ��ϓ_�����߂āA���ʂ��o�͂���
	// �Ȗڂ��Ƃ�for�ōs��̗�̉Ȗڂ𑖍�����
	for (int i = 0; i < sub; i++) {

		// sum������������
		sum = 0;

		// ���v�_�����߂�
		for (int j = 0; j < num; j++) {
			sum += a[j][i];
		}

		// ���ϓ_�����߂�
		avg = static_cast<double>(sum) / static_cast<double>(num);

		//���ʂ��o�͂���
		switch (i) {
		case 0:
			subname = "����";
			break;

		case 1:
			subname = "���w";
			break;
		}

		cout << subname << "�̍��v�_: " << sum << "\n";
		cout << subname << "�̕��ϓ_: " << avg << "\n";

	}
	cout << "\n";


	// �w�����Ƃ̍��v�_�ƕ��ϓ_�����߂āA���ʂ��o�͂���
	for (int i = 0; i < num; i++) {

		//���v�_sum�����Z�b�g����
		sum = 0;

		cout << "�w��" << i + 1 << ":\n";

		// �w�����Ƃ̍��v�_�����߂�
		for (int j = 0; j < sub; j++) {
			sum += a[i][j];
		}

		// �w�����Ƃ̕��ϓ_�����߂�
		avg = static_cast<double>(sum) / static_cast<double>(num);

		// �w�����Ƃ̍��v�_�ƕ��ϓ_���o�͂���
		cout << "���v�_: " << sum << "\n";
		cout << "���ϓ_: " << avg << "\n";
	}


	
}