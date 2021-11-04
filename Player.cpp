#include "Player.h"

Player::Player()
{
	this->firstName = "";
	this->secondName = "";
	this->points = 0;
}

Player::Player(string s1, string s2, int i)
{
	this->firstName = s1;
	this->secondName = s2;
	this->points = i;
}

Player::~Player()
{
	this->firstName = "";
	this->secondName = "";
	this->points = 0;
}

void Player::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Player::setSecondName(string secondName)
{
	this->secondName = secondName;
}

void Player::setPoints(int points)
{
	this->points = points;
}

string Player::getFirstName()
{
	return firstName;
}

string Player::getSecondName()
{
	return secondName;
}

int Player::getPoints()
{
	return points;
}
