
class User {
private:
	int num;		// ����񂯂�̃O�[�A�`���L�A�p�[�ɑ������鐮��0,1,2
public:
	// ���[�U�[�̎����͂���֐�
	int setNum();
};

class Computer {
private:
	int num;		// ����񂯂�̃O�[�A�`���L�A�p�[�ɑ������鐮��0,1,2
public:
	// �R���s���[�^�̎��ݒ肷��֐�
	int setNum();
};

class Game {
private:
	int userWin;
	int comWin;
	int diff;		// ���[�U�[�̎�ƃR���s���[�^�̎�̍���0�Ȃ���������A1�Ȃ烆�[�U�[�������A2�Ȃ烆�[�U�[������

public:

	Game();
	// �o�������\������
	void outputHand(int handNum);

	// �R���s���[�^�̎���o�͂���
	void outputComHand(int cnum);

	// ���[�U�[�̎���o�͂���
	void outputUserHand(int unum);

	// ���s�����߂�
	void judgeWin(int unum, int cnum);

	// �Q�[���i�s
	void playGame();
};