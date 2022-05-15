#pragma once
#include "Player.h"
class Game
{
public:
	Player player;
	void playerWin();
	void dealerWin();
	void gameDraw();
	void betting();
	int keyDraw();
	Game();
	~Game();
private:
	int x, y,call;
	char card[13];
	int keyControl();
	void gotoxy(int x, int y);
};

