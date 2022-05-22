#include "Player.h"
void Player::setMoney(int amount)
{
	this->money = amount;
}
bool Player::subMoney(int amount)
{
	if (this->money - amount >= 0)
	{
		this->money -= amount;
		return true;
	}
	else
	{
		return false;
	}

}
int Player::getMoney()
{
	return money;
}
void Player::setCard(int card)
{
	this->card = card;
}
int Player::getCard()
{
	return card;
}
void Player::setMark(string mark)
{
	this->mark = mark;
}
string Player::getMark()
{
	return mark;
}
void Player::setCardSum(int card)
{
	this->cardSum = card;
}
int Player::getCardSum()
{
	return cardSum;
}
