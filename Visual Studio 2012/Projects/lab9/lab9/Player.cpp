#include "Player.h"
#include <ctime>
using namespace std;

//---------------------------------------------------------------------------------------
Player::Player(string name_in)
{
	name = name_in;
	numwins = 0;
	numlosses = 0;
	numdraws = 0;
	winningrecord = 0;
}
Player::~Player(){}
//---------------------------------------------------------------------------------------
string Player::getName()
{
	return name;
}
void Player:: setPercent()
{
	if(numwins == 0 && numlosses == 0 && numdraws == 0)
	{
		winningrecord = 0;
	}
	else
	{
	winningrecord = (numwins/(numwins + numlosses + numdraws)) * 100;
	}
}

double Player:: getPercent()
{
	return winningrecord;
}
string Player::toString()
{
	//winningrecord = (numwins/(numwins + numlosses + numdraws)) * 100;
	setPercent();
	stringstream ss;
	ss << "Name: " << name << endl;
	ss << "Wins: " << numwins << endl;
	ss << "Losses: " << numlosses << endl;
	ss << "Draws: " << numdraws << endl;
	ss << "Winning Record: " << getPercent() << "%" << endl;
	return ss.str();
}
string Player::comptoString()
{
	stringstream ss;
	ss << name << endl;
	return ss.str();
}

string Player::getRPSThrow()
{
	string handthrow;
	double r=rand() %3;
	if(r == 0)
	{
		handthrow = "Rock";
	}
	if(r == 1)
	{
		handthrow = "Paper";
	}
	if(r == 2)
	{
		handthrow = "Scissors";
	}
	return handthrow;
}


void Player::setwins()
{
	numwins += 1;
}
void Player::setlosses()
{
	numlosses += 1;
}
void Player::setdraws()
{
	numdraws += 1;
}

