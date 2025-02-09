#include <iostream>
#include <sstream>
#include <ctime>
#include "Date.h"
using namespace std;

Date::Date() {
	 time_t now = time(NULL);	// �G�|�b�N�^�C���̎擾�i1970�N����̌o�ߕb��)
	 tm* localTime = localtime(&now);	// time_t�^��now����{�̎��Ԃɂ���Atm*�^�̓����o�ɔN���������b���ꂼ��������Ă���B

	 year = localTime->tm_year + 1900;
	 month = localTime->tm_mon + 1;
	 day = localTime->tm_mday;
	
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

Date Date::preceding_day() {
	Date temp = *this;		// �N�����̊ۃR�s
	int lastDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// ���t��1���炷
	temp.day -= 1;

	// ���t��0�ȉ��ɂȂ�ꍇ�̏���
	// ���t��month-1�̌��̍ŏI���ɂ���
	// ����-1�ɂ���
	if (temp.day <= 0) {
		int idx = ((temp.month - 2) + 12) % 12;
		temp.day = lastDay[idx]; // �Y������-1&�Ђƌ��O��-1
		temp.month -= 1;
	}

	// ����0�ȉ��ɂȂ������̏���
	// ����12�ɂ���B
	// �N��-1����
	if (temp.month <= 0) {
		temp.month = 12;
		temp.year -= 1;
	}

	return temp;
}

string Date::toString() {
	stringstream ss;
	ss << year << "�N" << month << "��" << day << "��";
	return ss.str();
}

int Date::week() {
	
	// �c�F���[�̌������g��
	int h;

	int d = day;
	int m = month;
	int y = year;

	if (m == 1 || m == 2) {
		m += 12;
		--year;
	}

	int k = year % 100;
	int j = year / 100;

	int fml1 = d;
	int fml2 = (13 * (m + 1)) / 5;
	int fml3 = k;
	int fml4 = k / 4;
	int fml5 = j / 4;
	int fml6 = 5 * j;
	
	h = (fml1 + fml2 + fml3 + fml4 + fml5 + fml6 ) % 7;

	return h;
}
