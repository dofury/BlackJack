#pragma once
#include "Utility.h"
class Dealer
{
private:
	int card, cardSum,cardScore;
	string mark;
public:
	void setCard(int card);
	int getCard();
	void setCardScore(int score);
	int getCardScore();
	void setMark(string mark);
	string getMark();
	void setCardSum(int card);
	int getCardSum();
};

