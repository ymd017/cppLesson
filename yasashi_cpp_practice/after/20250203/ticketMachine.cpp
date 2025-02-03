/*
* 
*/

#include <iostream>
#include <cstring>
using namespace std;

class Menu {
private:
	int num = 1;
	int set = 0;
	int opt = 0;
	int price = 0;
	char name[20];
public:
	Menu(const char* nm = "", int n = 0, int s = 0, int o = 0, int p = 0) {
		strcpy(name, nm);
		num = n;
		set = s;
		opt = o;
		price = p;
	}
	const char* getName() {
		return name;
	}

	int getNum() {
		return num;
	}

	int getOpt() {
		return opt;
	}

	int getPrice() {
		return price;
	}

};

class Category {
private:
	int mainCnt = 0;
	int side1Cnt = 0;
	int side2Cnt = 0;
	int optCnt = 0;
	Menu menus[5] = {Menu("", 0, 0, 0, 0)};
public:
	void addMenu(Menu mn);

	void onDraw(int c);
};

class TicketMachine {
private:
	int total = 0;
	Category categories[4];
public:
	TicketMachine();

	void onDraw(int c) {
		categories[c].onDraw(c);
	}
};



void Category::addMenu(Menu mn) {

	switch (mn.getNum()) {
	case 1:
		menus[mainCnt++] = mn;
		break;
	case 2:
		menus[side1Cnt++] = mn;
		break;
	case 3:
		menus[side2Cnt++] = mn;
		break;
	case 4:
		menus[optCnt++] = mn;
		break;
	default:
		throw "������1~4�̐����ł��B";
	}

	
}

void Category::onDraw(int c) {
	int cnt;

	switch (c) {
	case 0:
		cnt = mainCnt;
		break;
	case 1:
		cnt = side1Cnt;
		break;
	case 2:
		cnt = side2Cnt;
		break;
	case 3:
		cnt = optCnt;
		break;
	default:
		throw "������1~4�̐����ł��B";
	}

	for (int i = 0; i < cnt; i++) {
		cout << menus[i].getName() << " : " << menus[i].getPrice() << "\n";
	}
}

TicketMachine::TicketMachine() {
	// �J�e�S���[�I�u�W�F�N�g�̐���
	Category mainMenu;
	Category sideMenu1;
	Category sideMenu2;
	Category option;

	// �J�e�S���[�I�u�W�F�N�g�̔z��v�f�Ƀ��j���[�I�u�W�F�N�g��������
	mainMenu.addMenu(Menu("����", 1, 1, 1, 380));
	mainMenu.addMenu(Menu("����", 1, 1, 1, 350));
	mainMenu.addMenu(Menu("����H", 1, 1, 0, 450));

	sideMenu1.addMenu(Menu("��؃T���_", 2, 1, 2, 100));
	sideMenu1.addMenu(Menu("�|�e�g�T���_", 2, 1, 2, 130));
	sideMenu1.addMenu(Menu("�Е�", 2, 1, 0, 100));
	sideMenu1.addMenu(Menu("����", 2, 0, 0, 60));
	sideMenu1.addMenu(Menu("����", 2, 0, 0, 70));

	sideMenu2.addMenu(Menu("�݂��`", 3, 1, 0, 60));
	sideMenu2.addMenu(Menu("�؏`", 3, 0, 0, 190));
	sideMenu2.addMenu(Menu("�؏`", 3, 1, 0, 200));
	
	option.addMenu(Menu("����", 4, 0, 1, 0));
	option.addMenu(Menu("�吷��", 4, 0, 1, 100));
	option.addMenu(Menu("������", 4, 0, 1, 200));
	option.addMenu(Menu("�S�}�h���b�V���O", 4, 0, 2, 0));
	option.addMenu(Menu("�a���h���b�V���O", 4, 0, 2, 0));

	// �J�e�S���[�I�u�W�F�N�g�������@�I�u�W�F�N�g�̔z��v�f�ɂ���
	// �����j���[�ǉ��O�ɂ��ƁA�l�n���Œǉ�����ĂȂ����ƂɂȂ�̂ł�
	categories[0] = mainMenu;
	categories[1] = sideMenu1;
	categories[2] = sideMenu2;
	categories[3] = option;

	

}

/*============================================================
* ���C���֐�
* �����@�F�Ȃ�
* �߂�l�F�Ȃ�
============================================================*/
int main() {

	// �����@�I�u�W�F�N�g�̐���
	TicketMachine ticketMachine;

	// ��������Ⴂ�܂��̕\��
	cout << "��������Ⴂ�܂�\n\n";

	// ���C�����j���[�̕\��
	cout << "���C�����j���[�����I�т�������\n";
	ticketMachine.onDraw(0);
}