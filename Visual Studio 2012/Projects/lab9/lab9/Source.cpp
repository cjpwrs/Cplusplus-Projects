#include "Player.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdlib.h> 
#include <stdio.h>
#include <fstream>
#include <cctype>
#include <ctime>

void add(vector<Player*>& players)
{
	string name;
	cin.ignore(1);
	cout << "Enter Player Name: " ;
	getline(cin, name);
	int index =-1;
	for(int icount=0; icount<players.size(); icount++)
	{
		if((*players[icount]).getName() == name)
		index=icount;
	}
	if(index == -1)
	{
		players.push_back(new Player(name));
	}
	else
	{
		cout << "This player is already on the list." << endl;
		return;
	}
}
void addtocomp(vector<Player*>& players, vector<Player*>& comp)
{
	string name;
	cin.ignore(1);
	cout << "Enter Player name: " ;
	getline(cin, name);
	int index =-1;
	for(int icount=0; icount<players.size(); icount++)
	{
		if((*players[icount]).getName() == name)
		index=icount;
	}
	if(index == -1)
	{
		cout << "This player is not on the list, enter a valid name." << endl;
		return;
	}
	else
	{
		comp.push_back(players[index]);
	}
}
void removefromcomp(vector<Player*>& comp)
{
	comp.erase(comp.begin());
}

void addwin0(vector<Player*>& allplayers, vector<Player*>& comp)
{
	for(int icount=0; icount<allplayers.size(); icount++)
	{
		if((*allplayers[icount]).getName() == (*comp[0]).getName())
		{
			(*allplayers[icount]).setwins();
		}
	}
}
void addwin1(vector<Player*>& allplayers, vector<Player*>& comp)
{
	for(int icount=0; icount<allplayers.size(); icount++)
	{
		if((*allplayers[icount]).getName() == (*comp[1]).getName())
		{
			(*allplayers[icount]).setwins();
		}
	}
}
void addloss0(vector<Player*>& allplayers, vector<Player*>& comp)
{
	for(int icount=0; icount<allplayers.size(); icount++)
	{
		if((*allplayers[icount]).getName() == (*comp[0]).getName())
		{
			(*allplayers[icount]).setlosses();
		}
	}
}
void addloss1(vector<Player*>& allplayers, vector<Player*>& comp)
{
	for(int icount=0; icount<allplayers.size(); icount++)
	{
		if((*allplayers[icount]).getName() == (*comp[1]).getName())
		{
			(*allplayers[icount]).setlosses();
		}
	}
}
void adddraw0(vector<Player*>& allplayers, vector<Player*>& comp)
{
	for(int icount=0; icount<allplayers.size(); icount++)
	{
		if((*allplayers[icount]).getName() == (*comp[0]).getName())
		{
			(*allplayers[icount]).setdraws();
		}
	}
}
void adddraw1(vector<Player*>& allplayers, vector<Player*>& comp)
{
	for(int icount=0; icount<allplayers.size(); icount++)
	{
		if((*allplayers[icount]).getName() == (*comp[1]).getName())
		{
			(*allplayers[icount]).setdraws();
		}
	}
}




using namespace std;

int main()
{
	srand(time(0));
	vector<Player*> allplayers;
	vector<Player*> competition;

	int choice = 0;
	do
	{
		cout<< "\n(1) Show Players\n(2) Add Player\n(3) Add to Line-Up\n(4) Show Line-Up\n(5) Fight\n(6) Quit\n" << endl;
		cin >> choice;
		if(choice == 1)
		{
			for(int icount = 0; icount < allplayers.size(); icount++)
			{
				cout << allplayers[icount]->toString() << endl;
			}
		}
		if(choice == 2)
		{
			add(allplayers);
		}
		if(choice == 3)
		{
			addtocomp(allplayers, competition);
		}
		if(choice == 4)
		{
			for(int icount = 0; icount < competition.size(); icount++)
			{
				cout << competition[icount]->toString() <<endl;
			}
		}
		if(choice ==5)
		{
			if(competition.size() >1)
			{
				cout << "Fight initiated between " << (*competition[0]).getName() << " and " << (*competition[1]).getName() << "!" << endl;
				if((*competition[0]).getName() == (*competition[1]).getName())
				{
					cout << "It's a draw!" << endl;
					adddraw0(allplayers, competition);
				}
				else
				{
					string throw1 = (*competition[0]).getRPSThrow();
					string throw2 = (*competition[1]).getRPSThrow();
					cout << (*competition[0]).getName() << " throws " << throw1 << "!" << endl;
					cout << (*competition[1]).getName() << " throws " << throw2 << "!" << endl;
					if((throw1 == "Rock" && throw2 == "Scissors") ||
						(throw1 == "Scissors" && throw2 == "Paper") ||
						(throw1 == "Paper" && throw2 == "Rock"))
					{
						cout << (*competition[0]).getName() << " wins!" << endl;
						addwin0(allplayers, competition);
						addloss1(allplayers, competition);
					}
					else if((throw2 == "Rock" && throw1 == "Scissors") ||
						(throw2 == "Scissors" && throw1 == "Paper") ||
						(throw2 == "Paper" && throw1 == "Rock"))
					{
						cout << (*competition[1]).getName() << " wins!" << endl;
						addwin1(allplayers, competition);
						addloss0(allplayers, competition);
					}
					else if((throw2 == "Rock" && throw1 == "Rock") ||
						(throw2 == "Scissors" && throw1 == "Scissors") ||
						(throw2 == "Paper" && throw1 == "Paper"))
					{
						cout << "It's a draw!" << endl;
						adddraw0(allplayers, competition);
						adddraw1(allplayers, competition);
					}
					
				}
				removefromcomp(competition);
				removefromcomp(competition);
			}
			else
			{
				cout << "There must be at least two players to compete." << endl;
			}


		}
		if(choice == 6)
		{
			cout<< "Thanks, come again." <<endl;
			return 0;
		}


	}while(choice != -1);





	for(int icount; icount < allplayers.size(); icount++)
	{
		delete allplayers[icount];
	}
	allplayers.clear(); 

	return 0;

}
