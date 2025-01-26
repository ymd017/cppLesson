class Player {
private:
	int num;
public:
	int setNum();
};

class Answer {
private:
	int ans;
public:
	int setAns();

};

class Judgement {
private:
	bool judgement;
	char hint[50];
	int diff;
public:
	bool judgeAns(int num, int ans);
};

class Game {
private:
	Player player;
	Answer answer;
	Judgement judgement;
	int num;
	int ans;
	int result;

public:
	void play();
};

