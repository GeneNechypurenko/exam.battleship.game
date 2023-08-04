#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

enum textcolor
{
	STANDART = 15,
	HIGHLIGHT = 3,
	GREEN = 10,
	RED = 4
};

enum navikeys
{
	ENTER = 13,
	ESC = 27,
	SPACE = 32,
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};


const char WATER = 32;
const char MISS = 15;


const int BOARDSIZE = 10;
const char VERTICAL = 186;
const char HORIZONTAL = 205;
const char TOPLEFT = 201;
const char BOTLEFT = 200;
const char TOPRIGHT = 187;
const char BOTRIGHT = 188;


const char POSITION[][BOARDSIZE]
{
{'R', 'E', 'S', 'P', 'U', 'B', 'L', 'I', 'C', 'A'},
{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
};

const char DECKSAFE = 254;
const char DECKHIT = 120;

const int SHIPCOUNT = 10;

const int DECKS[SHIPCOUNT] =
{
	4,
	3, 3,
	2, 2, 2,
	1, 1, 1, 1
};

const string TYPES[SHIPCOUNT] =
{
	"LINCORE",
	"FRIGATE", "FRIGATE",
	"CORVETTE", "CORVETTE", "CORVETTE",
	"BRIG", "BRIG", "BRIG", "BRIG"
};

const string DIRECTION[] = { "VERTICAL", "HORIZONTAL" };
