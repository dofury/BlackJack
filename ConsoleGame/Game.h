#pragma once
#include "Player.h"
using namespace std;
typedef enum _eGameResult {
	eGameResult_WIn = 0,
	eGameResult_Loss,
	eGameResult_Draw,
	eGameResult_Cancel,
	eGameResult_Exit

}eGameResult;
class Game
{
public:
	Player player;
	void gameStart();
	void playerWin();
	void dealerWin();
	void gameDraw();
	void gameClear();
	void menuClear();
	void menuDraw();
	bool betting();
	void cardDraw();
	int isAllNumber(char* input,int length);
	int keyDraw();
	int keyControl();
	eGameResult getGameResult();
	Game();
	~Game();
private:
	int x, y;
	char card[13];
	void gotoxy(int x, int y);
	eGameResult gameResult;
};

