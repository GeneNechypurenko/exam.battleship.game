#include "Board.h"

Board::Board()
{
	for (int i = 0; i < BOARDSIZE; i++)
	{
		for (int j = 0; j < BOARDSIZE; j++)
		{
			gameBoard[i][j] = WATER;
			isOccupied[i][j] = false;
		}
	}

	for (int i = 0; i < SHIPCOUNT; i++)
	{
		ships.push_back(Ship(DECKS[i], TYPES[i]));
	}
}

void Board::outputPlayerBoard()
{
	rend::outputColor(GREEN);

	rend::setPosXY(5, 2);

	rend::outputAt(rend::posX, rend::posY++);
	cout << "   R E S P U B L I C A" << endl;

	rend::outputAt(rend::posX, rend::posY++);
	cout << "  " << TOPLEFT;

	for (int i = 0; i < BOARDSIZE; i++)
	{
		cout << HORIZONTAL << HORIZONTAL;
	}
	cout << TOPRIGHT << endl;

	for (int i = 0; i < BOARDSIZE; i++)
	{
		rend::outputAt(rend::posX, rend::posY++);
		cout << i << " " << VERTICAL;

		for (int j = 0; j < BOARDSIZE; j++)
		{
			cout << gameBoard[i][j] << " ";
		}

		cout << VERTICAL << endl;
	}

	rend::outputAt(rend::posX, rend::posY++);
	cout << "  " << BOTLEFT;
	for (int i = 0; i < BOARDSIZE; i++)
	{
		cout << HORIZONTAL << HORIZONTAL;
	}
	cout << BOTRIGHT << endl;

	rend::setPosXYDefault();

	rend::outputColor(STANDART);
}

void Board::outputEnemyBoard()
{
	rend::outputColor(RED);

	rend::setPosXY(29, 2);

	rend::outputAt(rend::posX, rend::posY++);
	cout << "   R E S P U B L I C A" << endl;

	rend::outputAt(rend::posX, rend::posY++);
	cout << "  " << TOPLEFT;

	for (int i = 0; i < BOARDSIZE; i++)
	{
		cout << HORIZONTAL << HORIZONTAL;
	}
	cout << TOPRIGHT << endl;

	for (int i = 0; i < BOARDSIZE; i++)
	{
		rend::outputAt(rend::posX, rend::posY++);
		cout << "  " << VERTICAL;

		for (int j = 0; j < BOARDSIZE; j++)
		{
			if (gameBoard[i][j] == DECKHIT || gameBoard[i][j] == MISS)
			{
				cout << gameBoard[i][j] << " ";
			}
			else
			{
				cout << WATER << " ";
			}
		}

		cout << VERTICAL << " " << i << endl;
	}

	rend::outputAt(rend::posX, rend::posY++);
	cout << "  " << BOTLEFT;
	for (int i = 0; i < BOARDSIZE; i++)
	{
		cout << HORIZONTAL << HORIZONTAL;
	}
	cout << BOTRIGHT << endl;

	rend::setPosXYDefault();

	rend::outputColor(STANDART);
}

void Board::setIsOccupied(int y, int x, int next, bool isVertical)
{
	if (gameBoard[y][x] == DECKSAFE)
	{
		if (isVertical)
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				isOccupied[y + i][x] = true;

				if (y + i - 1 >= 0)
				{
					isOccupied[y + i - 1][x] = true;
					if (x - 1 >= 0)
						isOccupied[y + i - 1][x - 1] = true;
					if (x + 1 < BOARDSIZE)
						isOccupied[y + i - 1][x + 1] = true;
				}

				if (y + i + 1 < BOARDSIZE)
				{
					isOccupied[y + i + 1][x] = true;
					if (x - 1 >= 0)
						isOccupied[y + i + 1][x - 1] = true;
					if (x + 1 < BOARDSIZE)
						isOccupied[y + i + 1][x + 1] = true;
				}

				if (x - 1 >= 0)
					isOccupied[y + i][x - 1] = true;

				if (x + 1 < BOARDSIZE)
					isOccupied[y + i][x + 1] = true;
			}
		}
		else
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				isOccupied[y][x + i] = true;

				if (y - 1 >= 0)
				{
					isOccupied[y - 1][x + i] = true;
					if (x - 1 >= 0)
						isOccupied[y - 1][x + i - 1] = true;
					if (x + i + 1 < BOARDSIZE)
						isOccupied[y - 1][x + i + 1] = true;
				}

				if (y + 1 < BOARDSIZE)
				{
					isOccupied[y + 1][x + i] = true;
					if (x - 1 >= 0)
						isOccupied[y + 1][x + i - 1] = true;
					if (x + i + 1 < BOARDSIZE)
						isOccupied[y + 1][x + i + 1] = true;
				}

				if (x + i - 1 >= 0)
					isOccupied[y][x + i - 1] = true;

				if (x + i + 1 < BOARDSIZE)
					isOccupied[y][x + i + 1] = true;
			}
		}
	}
}

bool Board::checkAvailability(int x, int y, bool isVertical, int next)
{
    if (isVertical)
	{
        if (y + ships[next].getDecks() > BOARDSIZE)
		{
            return false;
        }
        for (int i = 0; i < ships[next].getDecks(); i++)
		{
            if (isOccupied[y + i][x])
			{
                return false;
            }
        }
    }
    else 
	{
        if (x + ships[next].getDecks() > BOARDSIZE)
		{
            return false;
        }
        for (int i = 0; i < ships[next].getDecks(); i++) 
		{
            if (isOccupied[y][x + i])
			{
                return false;
            }
        }
    }
    return true;
}

void Board::findAvailablePlacement(int& x, int& y, bool& isVertical, int next)
{
    for (int i = 0; i < BOARDSIZE; i++)
	{
        for (int j = 0; j < BOARDSIZE; j++)
		{
            for (int k = 0; k < 2; k++)
			{ 
                if (checkAvailability(j, i, k, next))
				{
                    x = j;
                    y = i;
                    isVertical = (k == 1);
                    return;
                }
            }
        }
    }
}

void Board::placeShip(int x, int y, int next, bool isVertical)
{
    if (isVertical)
    {
        for (int i = 0; i < ships[next].getDecks(); i++)
        {
            gameBoard[y + i][x] = DECKSAFE;
        }
    }
    else
    {
        for (int i = 0; i < ships[next].getDecks(); i++)
        {
            gameBoard[y][x + i] = DECKSAFE;
        }
    }
}

void Board::clearShip(int x, int y, int next, bool isVertical)
{
    if (isVertical)
    {
        for (int i = 0; i < ships[next].getDecks(); i++)
        {
            gameBoard[y + i][x] = WATER;
        }
    }
    else
    {
        for (int i = 0; i < ships[next].getDecks(); i++)
        {
            gameBoard[y][x + i] = WATER;
        }
    }
}

bool Board::checkCollision(int x, int y, int next, bool isVertical)
{
    if (isVertical)
    {
        for (int i = 0; i < ships[next].getDecks(); i++)
        {
            if (isOccupied[y + i][x])
            {
                return true;
            }
        }
    }
    else
    {
        for (int i = 0; i < ships[next].getDecks(); i++)
        {
            if (isOccupied[y][x + i])
            {
                return true;
            }
        }
    }
    return false;
}


void Board::deployShips()
{
	char actionKey;

	bool isVertical = false;

	int x = 0;
	int y = 0;

	int next = 0;

	while (next < SHIPCOUNT)
	{
		ships[next].setShipPlacement(x, y, isVertical);

		if (isOccupied[y][x] == true)
		{
			findAvailablePlacement(x, y, isVertical, next);
		}

		placeShip(x, y, next, isVertical);

		outputPlayerBoard();

		actionKey = _getch();

		if (actionKey == UP)
		{
			y--;
			moveUp(x, y, next, isVertical);
		}

		else if (actionKey == DOWN)
		{
			y++;
			moveDown(x, y, next, isVertical);
		}

		else if (actionKey == LEFT)
		{
			x--;
			moveLeft(x, y, next, isVertical);
		}

		else if (actionKey == RIGHT)
		{
			x++;
			moveRight(x, y, next, isVertical);
		}

		else if (actionKey == SPACE)
		{
			rotation(x, y, next, isVertical);
		}

		else if (actionKey == ENTER)
		{
			setIsOccupied(y, x, next, isVertical);
			next++;
			isVertical = false;
			x = 0;
			y = 0;
		}
	}
}

void Board::moveUp(int x, int& y, int next, bool isVertical)
{
	if (isVertical)
	{
		if (y == - 1)
		{
			y = BOARDSIZE - ships[next].getDecks();

			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[i][x] = WATER;
			}
		}
		else
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y + i + 1][x] = WATER;
			}
		}
	}
	else
	{
		if (y == - 1)
		{
			y = BOARDSIZE - 1;

			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[0][x + i] = WATER;
			}
		}
		else if (isOccupied[y][x + ships[next].getDecks() - 1])
		{
			clearShip(x, y + 1, next, isVertical);
			findAvailablePlacement(x, y, isVertical, next);
			return;
		}
		else
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y + 1][x + i] = WATER;
			}
		}
	}
}

void Board::moveDown(int x, int& y, int next, bool isVertical)
{
	if (isVertical)
	{
		if (y + ships[next].getDecks() - 1 == BOARDSIZE)
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y + i - 1][x] = WATER;
			}
			y = 0;
		}
		else if (isOccupied[y + ships[next].getDecks() - 1][x])
		{
			clearShip(x, y - 1, next, isVertical);
			findAvailablePlacement(x, y, isVertical, next);
			return;
		}
		else
		{
			gameBoard[y - 1][x] = WATER;
		}
	}
	else
	{
		if (y == BOARDSIZE)
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[BOARDSIZE - 1][x + i] = WATER;
			}
			y = 0;
		}
		else if (isOccupied[y][x + ships[next].getDecks() - 1])
		{
			clearShip(x, y - 1, next, isVertical);
			findAvailablePlacement(x, y, isVertical, next);
			return;
		}
		else
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y - 1][x + i] = WATER;
			}
		}
	}
}

void Board::moveLeft(int& x, int y, int next, bool isVertical)
{
	if (isVertical)
	{
		if (x == -1)
		{
			x = BOARDSIZE - 1;

			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y + i][0] = WATER;
			}
		}
		else if (isOccupied[y + ships[next].getDecks() - 1][x])
		{
			clearShip(x + 1, y, next, isVertical);
			findAvailablePlacement(x, y, isVertical, next);
			return;
		}
		else
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y + i][x + 1] = WATER;
			}
		}
	}
	else
	{
		if (x == -1)
		{
			x = BOARDSIZE - ships[next].getDecks();

			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y][i] = WATER;
			}
		}
		else
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y][x + i + 1] = WATER;
			}
		}
	}
}

void Board::moveRight(int& x, int y, int next, bool isVertical)
{
	if (isVertical)
	{
		if (x == BOARDSIZE)
		{
			x = 0;

			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y + i][BOARDSIZE - 1] = WATER;
			}
		}
		else if (isOccupied[y + ships[next].getDecks() - 1][x])
		{
			clearShip(x - 1, y, next, isVertical);
			findAvailablePlacement(x, y, isVertical, next);
			return;
		}
		else
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y + i][x - 1] = WATER;
			}
		}
	}
	else
	{
		if (x == BOARDSIZE + 1 - ships[next].getDecks())
		{
			x = 0;

			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y][BOARDSIZE - ships[next].getDecks() + i] = WATER;
			}
		}
		else if (isOccupied[y][x + ships[next].getDecks() - 1])
		{
			clearShip(x + 1, y, next, isVertical);
			findAvailablePlacement(x, y, isVertical, next);
			return;
		}
		else
		{
			gameBoard[y][x - 1] = WATER;
		}
	}
}

void Board::rotation(int x, int y, int next, bool& isVertical)
{
	if (isVertical)
	{
		if (ships[next].getDecks() == 4 && x > BOARDSIZE - ships[next].getDecks() ||
			ships[next].getDecks() == 3 && x > BOARDSIZE - ships[next].getDecks() ||
			ships[next].getDecks() == 2 && x > BOARDSIZE - ships[next].getDecks())
		{
			isVertical = true;
		}
		else
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y + i][x] = WATER;
			}
			isVertical = false;
		}
	}
	else
	{
		if (ships[next].getDecks() == 4 && y > BOARDSIZE - ships[next].getDecks() ||
			ships[next].getDecks() == 3 && y > BOARDSIZE - ships[next].getDecks() ||
			ships[next].getDecks() == 2 && y > BOARDSIZE - ships[next].getDecks())
		{
			isVertical = false;
		}
		else
		{
			for (int i = 0; i < ships[next].getDecks(); i++)
			{
				gameBoard[y][x + i] = WATER;
			}
			isVertical = true;
		}
	}
}

void Board::printB()
{
	for (int i = 0; i < SHIPCOUNT; i++)
		ships[i].print();
}

void Board::printOccupiedCells()
{
	for (int y = 0; y < BOARDSIZE; y++)
	{
		for (int x = 0; x < BOARDSIZE; x++)
		{
			if (isOccupied[y][x])
			{
				cout << "Occupied cell at (" << y << ", " << x << ")" << endl;
			}
		}
	}
}
