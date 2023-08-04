#pragma once

#include <iostream>
#include <vector>

#include "Constatnts.h"

using namespace std;

class test
{
private:

	struct ship
	{
		int decks;
		string type;
		int x;
		int y;
		bool isVertical; // true = horizontal, false = vertical
		bool isActive; // true = active, false = destroyed
		vector <char> depiction;

		ship(int decks, string type);
	};
	//ship s;

	vector<ship> ships;

public:
	test();

	void printAll();
	void setPos(int index, int x, int y, bool dir);
	int getDecks(int index);
};

