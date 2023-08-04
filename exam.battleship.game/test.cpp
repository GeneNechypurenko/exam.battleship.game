#include "test.h"

test::ship::ship(int decks, string type)
	:
	decks(decks),
	type(type)
{
	x = -1;
	y = -1;
	isVertical = true; // true = horizontal, false = vertical
	isActive = true; // true = active, false = destroyed

	for (int i = 0; i < decks; i++)
		depiction.push_back(DECKSAFE);
}

test::test()
{
	for (int i = 0; i < SHIPCOUNT; i++)
	{
		ships.push_back(ship(DECKS[i], TYPES[i]));
	}
}

void test::printAll()
{
	for (int i = 0; i < SHIPCOUNT; i++)
	{
		cout << ships[i].decks << endl;
		cout << ships[i].type << endl;
		cout << ships[i].isActive << endl;
		cout << ships[i].isVertical << endl;
		cout << ships[i].x << endl;
		cout << ships[i].y << endl;

		cout << endl;
	}

}

void test::setPos(int index, int x, int y, bool dir)
{
	ships[index].x = x;
	ships[index].y = y;
	ships[index].isVertical = dir;
}

int test::getDecks(int index)
{
	return ships[index].decks;
}
