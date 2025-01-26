#include <iostream>

class Human {
private:
	std::string name;	// 名前
	int height;		// 身長
	int weight;		// 体重
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