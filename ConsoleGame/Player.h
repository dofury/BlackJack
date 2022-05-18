#pragma once
#include "Utility.h"
class Player
{
private:
	int money, card, cardSum;
	string mark;

	void stop();
public:
	void setMoney(int amount);
	bool subMoney(int amount);
	int getMoney();
	void setCard(int card);
	int getCard();
	void setMark(string mark);
	string getMark();
	void setCardSum(int card);
	int getCardSum();
};

