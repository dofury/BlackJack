#pragma once
#define MAX 52
#include "Player.h"
#include "Dealer.h"
#include "Utility.h"
using namespace std;
typedef enum _eGameResult {
	eGameResult_Default = 0,
	eGameResult_WIn,
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
typedef enum _eMember {
	eGamePlayer = 0,
	eGameDealer
}eMember;
class Game
{
public:
	Player player;
	Dealer dealer;
	int playerCall,reward;
	bool gameStart();
	void playerWin();
	void playerLoss();
	void playerDraw();
	void playerInvest();
	void gameDraw(eMember member,int x,int y);
	void gameClear();
	void menuClear();
	void valueUpdate();
	bool betting();
	bool investment();
	void gameLoading();
	bool playerCardDraw();
	bool dealerCardDraw();
	bool cardACheck();
	void cardACount();
	bool resultCheck(eMember member);
	string getDrawCNum(eMember member);
	bool randomCard(eMember member);
	int isAllNumber(char* input,int length);
	int keyControl();
	eGameResult getGameResult();
	Game();
	~Game();
private:
	void gameReset();
	int cardMaxIndex;
	int aCount;
	gameCard card[MAX];
	int cardSetAmount;
	eGameResult gameResult;
	eMember member;
	int progress;
	bool gameEnd;
	bool invest;
};

