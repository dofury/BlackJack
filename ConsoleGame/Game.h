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
	int playerCall;
	bool gameStart();
	void playerWin();
	void playerLoss();
	void gameDraw(int x,int y);
	void gameClear();
	void menuClear();
	void menuDraw();
	bool betting();
	void gameLoading();
	bool cardDraw();
	bool cardACheck();
	bool resultCheck();
	string getDrawCNum();
	bool randomCard();
	int isAllNumber(char* input,int length);
	int keyControl();
	eGameResult getGameResult();
	Game();
	~Game();
private:
	void gameReset();
	int cardMaxIndex;
	gameCard card[MAX];
	int cardSetAmount;
	eGameResult gameResult;
	int progress;
	int playerResult;
	bool gameEnd;
};

