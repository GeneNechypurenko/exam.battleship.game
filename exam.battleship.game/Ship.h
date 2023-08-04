#pragma once

#include "ConsoleRenderer.h"

class Ship
{
private:
	int decks;
	string type;
	int x;
	int y;
	bool isVertical; // true = horizontal, false = vertical
	bool isActive; // true = active, false = destroyed
	vector <char> depiction;

public:
	explicit Ship(int length, const string type);
	explicit Ship(int length, const string type, int x, int y, bool direction);

	string getType() const;
	int getDecks() const;
	void getDepiction() const;
	int getX() const;
	int getY() const;
	bool getIsVertical() const;

	void setShipPlacement(int x, int y, bool direction);
	bool getShipStatus() const;
	bool shipDeckHit(int x, int y);

	void print(); //test option
};