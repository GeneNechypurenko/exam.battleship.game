#include "ConsoleRenderer.h"

HANDLE ConsoleRenderer::hSettings = GetStdHandle(STD_OUTPUT_HANDLE);

int ConsoleRenderer::posX = 0;
int ConsoleRenderer::posY = 0;

void ConsoleRenderer::setPosXY(short x, short y)
{
	posX = x;
	posY = y;
}

void ConsoleRenderer::setPosXYDefault()
{
	posX = 0;
	posY = 0;
}

void ConsoleRenderer::outputAt(short x, short y)
{
	SetConsoleCursorPosition(hSettings, { x,y });
}

void ConsoleRenderer::outputColor(int textcolor)
{
	SetConsoleTextAttribute(hSettings, textcolor);
}
