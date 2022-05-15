#pragma once
class Player
{
private:
	int money, cardSum;

	void stop();
public:
	void setMoney(int amount);
	void subMoney(int amount);
	int getMoney();
};

