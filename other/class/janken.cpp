/*
* ����񂯂�Q�[�����N���X��p���č쐬����
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ���[�U�[��\���N���X
class User {
private:
	int hand;
public:
	void setHand();
	int getHand();
};

// ���[�U�[�̎��I�����郁���o�֐�
void User::setHand() {
	cout << "���[�U�[�̎��I��ł�������\n";
	cout << "0:�O�[, 1:�`���L, 2:�p�[\n";
	cin >> hand;
}

int User::getHand() {
	return hand;
}

class Computer {
private:
	int hand;
public:
	void setHand();
	int getHand();
};

// �R���s���[�^�̎��I�����郁���o�֐�
void Computer::setHand() {
	hand = rand() % 3;
}

// �R���s���[�^�̎��Ԃ������o�֐�
int Computer::getHand() {
	return hand;
}

class Judge{
private:
	int judge;
public:
	void doJudge(User u, Computer c);
	void showJudge();
};

// �W���b�W�����s�𔻒肷�郁���o�֐�
void Judge::doJudge(User u, Computer c) {
	int user;		// ���[�U�[�̎�
	int computer;	// �R���s���[�^�̎�
	int diff;		// �o������̍���

	user = u.getHand();
	computer = c.getHand();

	diff = ((user - computer) + 3) % 3;

	judge = diff;
}

//�@���s��\�����郁���o�֐�
void Judge::showJudge() {
	switch (judge) {
	case 0:
		cout << "���������ł�\n";
		break;
	case 1:
		cout << "���[�U�[�̕����ł�\n";
		break;
	case 2:
		cout << "���[�U�[�̏����ł�\n";
		break;
	default:
		cout << "�G���[\n";
	}
}

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main(){

	User user;
	Computer computer;
	Judge judge;

	// �V�[�h�l
	srand(time(NULL));

	// ���[�U�[�����I������
	user.setHand();

	// �R���s���[�^�����I������
	computer.setHand();

	// ���s�𔻒肷��
	judge.doJudge(user, computer);

	// ���s��\������
	judge.showJudge();
}
