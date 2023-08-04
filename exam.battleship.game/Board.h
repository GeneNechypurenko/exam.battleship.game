#pragma once

#include "Ship.h"

using rend = ConsoleRenderer;

class Board
{
private:
	char gameBoard[BOARDSIZE][BOARDSIZE];
	bool isOccupied[BOARDSIZE][BOARDSIZE];
	vector <Ship> ships;

public:
	explicit Board();

	void outputPlayerBoard();
	void outputEnemyBoard();

	void setIsOccupied(int y, int x, int next, bool isVertical);
	bool checkAvailability(int x, int y, bool isVertical, int next);
	void findAvailablePlacement(int& x, int& y, bool& isVertical, int next);
	void placeShip(int x, int y, int next, bool isVertical);
	void clearShip(int x, int y, int next, bool isVertical);
	bool checkCollision(int x, int y, int next, bool isVertical);
	//void displayDeploymentValues();
	void deployShips();

	void moveUp(int x, int& y, int next, bool isVertical);
	void moveDown(int x, int& y, int next, bool isVertical);
	void moveLeft(int& x, int y, int next, bool isVertical);
	void moveRight(int& x, int y, int next, bool isVertical);
	void rotation(int x, int y, int next, bool& isVertical);

	void printB();

	void printOccupiedCells();
};

