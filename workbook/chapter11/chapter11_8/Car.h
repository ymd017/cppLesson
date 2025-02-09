#pragma once

#include <string>
#include "Position.h"

class Car {
private:
	int x;
	int y;
	int number;
	int width;
	int length;
	int height;
	int purchaseYear;
	int purchaseMonth;
	int purchaseDay;
	double fuelEff;
	double tankCapa;
	double remainingFuel;
	std::string name;
	Position carpos;

public:
	Car(std::string nm, int n, int w, int l, int h, int py, int pm, int pd, double fe, double tc, double rf);

	void setPrameter();

	void printSpec();

	

};