#include "Arena.h"
Arena::Arena()
{
    vector<FighterInterface*> players;
}

bool Arena::addFighter(string info)
{
    stringstream strm(info);
    string name; 
	string type;
    int hp;
	int strength;
	int speed; 
	int magic;
    if (strm >> name >> type >> hp >> strength >> speed >> magic) 
	// this is to check for errors 
	{
		if (strm.eof()) 
		{
			//check for non positives
			if (hp <= 0 || strength <= 0 || speed <= 0 || magic <= 0) 
			{
				return false;
			}
			//check to see if name is already in list
			for (int i = 0; i < players.size(); i++) 
			{
				if (name == players[i]->getName())
				{
					return false;
				}
			}
			//if archer
			if(type == "A")
			{
				Archer* A = new Archer(name, hp, strength, speed, magic);
				players.push_back(A);
			}
			//if cleric
			else if (type == "C")
			{
				Cleric* C = new Cleric(name, hp, strength, speed, magic);
				players.push_back(C);
			}
			//if robot
			else if (type == "R")
			{
				Robot* R = new Robot(name, hp, strength, speed, magic);
				players.push_back(R);
			}
			//if none of the types, dont allow to continue
			else 
			{
				return false; 
			}
		return true;
		}
		else 
		{
			return false;
		}
	}
	else 
	{
		return false;
	}
}
bool Arena::removeFighter(string name)
{
    for (int i = 0; i < players.size(); i++)
    {
        if (name == players[i]->getName())
        {
            players.erase(players.begin() + i);
            return true;
        }
    }
    return false;
}
FighterInterface* Arena::getFighter(string name)
{
    for (int i = 0; i < players.size(); i++)
    {
        if (name == players[i]->getName())
        {
            return players[i];
        }
    }
    return false;
}
int Arena::getSize()
{
    return players.size();
}