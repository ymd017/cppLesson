#include <iostream>

class Human {
private:
	std::string name;	// ���O
	int height;		// �g��
	int weight;		// �̏d
public:
	Human(std::string name, int h, int w);

	std::string getName() {
		return name;
	}

	int getHeihgt() {
		return height;
	}

	int getWeight() {
		return weight;
	}

	void growFat(int dw);
	void slimOff(int dw);
};