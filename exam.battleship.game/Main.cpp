#include <iostream>
#include <vector>
#include <conio.h>

#include "Board.h"
#include "test.h"

using namespace std;

void main()
{
	//Ship lincore(4, "Lincore", 2, 4, false);
	//lincore.setShipPlacement(5, 3, true);
	//lincore.shipDeckHit(5, 3);
	//lincore.shipDeckHit(5, 5);

	//lincore.print();

	//cout << endl << (lincore.getShipStatus() ? "ship is still in battle" : "ship is sunk");

	Board b;
	//b.outputPlayerBoard();
	b.outputEnemyBoard();

	b.deployShips();

	//b.printB();

	//test t;
	//t.printAll();
	//t.setPos(3, 5, 2, true);
}