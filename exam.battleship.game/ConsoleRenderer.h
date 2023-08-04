#pragma once

#include "Constatnts.h"



class ConsoleRenderer
{
public:
	static HANDLE hSettings;

	static int posX;
	static int posY;

	static void setPosXY(short x, short y);
	static void setPosXYDefault();

	static void outputAt(short x, short y);
	static void outputColor(int textcolor);
};