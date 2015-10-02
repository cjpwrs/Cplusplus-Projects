#include "Arena.h"
#include "Fighter.h"
#include <string>
#include<sstream>

Arena::Arena(void)
{
	vector<FighterInterface*> fighters;
}


Arena::~Arena(void){}

/*
		 *	addFighter(string)
		 *
		 *	Adds a new fighter to the collection of fighters in the arena. Do not allow 
		 *	duplicate names.  Reject any string that does not adhere to the format 
		 *	outlined in the lab specs.
		 *
		 *	Return true if a new fighter was added; false otherwise.
		 */


		/*bool Arena::addFighter(string info)
		{
			stringstream in_file;
			
			in_file<<info;
			
			string name;
			string type;
			int hp;
			int strength;
			int magic;
			in_file >> name;
			in_file >> type;
			in_file >> hp;
			in_file >> strength;
			in_file >> magic;

			if(type == "A")
			{
				Archer *A = new Archer(name, hp, strength, magic);
			}
			else if( type == "C")
			{
				Cleric *C = new Cleric(name, hp, strength, magic);
			}
			else if(type == "R")
			{
				Robot *R = new Robot(name, hp, strength, magic);
			}



			

			
			//This is for testing inputs using sstream
			if(in_file >>x)
			{
				if(in_file >> y)
				{
				}
			}
			

		}*/

		bool Arena::addFighter(string info)
		{
			stringstream strm(info);
			string name, type;
			int hp, strength, speed, magic;
			if (strm >> name >> type >> hp >> strength >> speed >> magic) //checks for errors 
			{
				if (strm.eof()) //only process if at end of file
				{
					//do not allow non positive hp, strength, speed or magic
					if (hp <= 0 || strength <= 0 || speed <= 0 || magic <= 0) 
					{
						return false;
					}
					//checks to see if name is already in list
					for (int i = 0; i < fighters.size(); i++) 
					{
						if (name == fighters[i]->getName())
						{
							return false;
						}
					}
					//add player if not in list already
					if(type == "A")
					{
						Archer* A = new Archer(name, hp, strength, speed, magic);
						fighters.push_back(A);
					}
					else if (type == "C")
					{
						Cleric* C = new Cleric(name, hp, strength, speed, magic);
						fighters.push_back(C);
					}
					else if (type == "R")
					{
						Robot* R = new Robot(name, hp, strength, speed, magic);
						fighters.push_back(R);
					}
					else 
					{
						return false; //if type is not A or C or R
					}
				return true;
				}
				else return false;
			}
			else return false;
		}

		/*
		 *	removeFighter(string)
		 *
		 *	Removes the fighter whose name is equal to the given name.  Does nothing if 
		 *	no fighter is found with the given name.
		 *
		 *	Return true if a fighter is removed; false otherwise.
		 */
		bool Arena::removeFighter(string name)
		{

		}
		
		/*
		 *	getFighter(string)
		 *
		 *	Returns the memory address of a fighter whose name is equal to the given 
		 *	name.  Returns NULL if no fighter is found with the given name.
		 *
		 *	Return a memory address if a fighter is found; NULL otherwise.
		 */
		FighterInterface*Arena::getFighter(string name)
		{
			int i = 0 ;
            while (i < fighters.size())
            {
                Fighter trial_fighter = new Fighter(fighters[i]);
                string trial_name = trial_fighter.getName;
                if (name == trial_name)
                {
                    string *pointer = &fighters[i] ;
                    return pointer ;
                }
                else if (name != trial_name)
                {
                    i++ ;
                }
                trial_fighter.~Fighter() ;
            }
            
            if (i == fighters.size()) 
            {
                return NULL ;
            }
		}
		
		/*
		 *	getSize()
		 *
		 *	Returns the number of fighters in the arena.
		 *
		 *	Return a non-negative integer.
		 */
		int Arena::getSize()
		{
            int size = fighters.size() ;
            return size;
        }