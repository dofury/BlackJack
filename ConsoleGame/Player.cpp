#include "Player.h"
#include "Dealer.h"
void Player::setMoney(int amount)
{
	this->money = amount;
}
void Player::subMoney(int amount)
{
	this->money -= amount;
}
int Player::getMoney()
{
	return money;
}
