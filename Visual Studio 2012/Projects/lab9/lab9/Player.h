#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Player
{
	private:
		string name;
		double numwins;
		double numlosses;
		double numdraws;
		double winningrecord;

	public:
		Player(string name_in);
		virtual ~Player();
		string getName();
		string toString();
		string comptoString();
		string getRPSThrow();
		void setwins();
		void setdraws();
		void setlosses();
		double getPercent();
		void setPercent();
};