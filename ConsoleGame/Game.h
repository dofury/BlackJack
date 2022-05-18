#pragma once
#define MAX 52
#include "Player.h"
#include "Utility.h"
using namespace std;
typedef enum _eGameResult {
	eGameResult_WIn = 0,
	eGameResult_Loss,
	eGameResult_Draw,
	eGameResult_Cancel,
	eGameResult_Exit

}eGameResult;
typedef struct __gameCard
{
	int number;	//카드 숫자
	string mark;	//카드문양
} gameCard;
class Game
{
public:
	Player player;
	void gameStart();
	void playerWin();
	void dealerWin();
	void gameDraw(int x,int y);
	void gameClear();
	void menuClear();
	void menuDraw();
	bool betting();
	void gameLoading();
	bool cardDraw();
	string getDrawCNum();
	gameCard randomCard(int turn);
	int isAllNumber(char* input,int length);
	int keyControl();
	eGameResult getGameResult();
	Game();
	~Game();
private:
	gameCard card[MAX];
	int cardSetAmount;
	void gotoxy(int x, int y);
	eGameResult gameResult;
};

