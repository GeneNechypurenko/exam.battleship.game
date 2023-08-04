#include "Ship.h"

Ship::Ship(int length, const string type)
	:
	decks(length),
	type(type)
{
	x = -1;
	y = -1;

	isVertical = true;

	isActive = true; // active

	for (int i = 0; i < decks; i++)
		depiction.push_back(DECKSAFE);
}

Ship::Ship(int length, const string type, int x, int y, bool direction)
	:
	decks(length),
	type(type),
	x(x),
	y(y),
	isVertical(direction)
{
	isActive = true; // active

	for (int i = 0; i < decks; i++)
		depiction.push_back(DECKSAFE);
}

string Ship::getType() const
{
	return type;
}

int Ship::getDecks() const
{
	return decks;
}

void Ship::getDepiction() const
{
	for (int i = 0; i < decks; i++)
		cout << depiction[i] << " ";
}

int Ship::getX() const
{
	return x;
}

int Ship::getY() const
{
	return y;
}

bool Ship::getIsVertical() const
{
	return isVertical;
}

void Ship::setShipPlacement(int x, int y, bool direction)
{
	this->x = x;
	this->y = y;
	isVertical = direction;
}

bool Ship::shipDeckHit(int x, int y)
{
	if (isVertical && x == x && y >= y && y < y + decks)
	{
		depiction[y - y] = DECKHIT;
		return true;
	}
	else if (!isVertical && y == y && x >= x && x < x + decks)
	{
		depiction[x - x] = DECKHIT;
		return true;
	}
	return false;
}

bool Ship::getShipStatus() const
{
	for (int i = 0; i < decks; i++)
		if (depiction[i] == DECKSAFE)
			return false; // If at least one intact deck is found, the ship is not sunk

	return true; // All decks are hit, the ship is sunk
}


void Ship::print()
{
	cout << "type: " << type << endl;
	cout << "size: " << decks << endl;

	for (int i = 0; i < decks; i++)
		cout << depiction[i] << " ";

	cout << endl << "status: " << isActive << endl;
	cout << "coord X: " << x << endl;
	cout << "coord Y: " << y << endl;
	cout << "direction: " << isVertical << endl << endl;
}