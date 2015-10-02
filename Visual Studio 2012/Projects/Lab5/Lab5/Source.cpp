#include <iostream> 
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>


using namespace std;

double singlechipgame( double singlechip, bool print)
{
	int icount = 0;
	int end = 0;
	int prize = 0;
 
			for(icount=0; icount <12; icount++)
			{
				if(singlechip==8)
				{
					singlechip=7.5;
				}
				else if (singlechip==0)
				{
					singlechip=.5;
				}
				else
				{
					double r=rand() %2 - .5;
					singlechip=singlechip + r;

				}
				if(print ==true)
				{
				std::cout<< singlechip << endl;
				}
				end = singlechip;
			}
				return end;
}


int prizewinnings(int end)
{
	int prize = 0;
		
			if(end==0)
			{
				prize= 100;
			}
			else if(end==1)
			{
				prize = 500;
			}
			else if(end==2)
			{
				prize = 1000;
			}
			else if(end==3)
			{
				prize = 0;
			}
			else if(end==4)
			{
				prize = 10000;
			}
			else if(end==5)
			{
				prize = 0;
			}
			else if(end==6)
			{
				prize = 1000;
			}
			else if(end==7)
			{
				prize = 500;
			}
			else if(end==8)
			{
				prize = 100;
			}
			return prize;
}
double multchipgame(int numchip,int slotnum)
{
	int totalprize;
	int icount;
	int icount2;
	int end;
	int prize;

	if(slotnum >= 0 && slotnum < 9)
	{
		totalprize=0;
		for(icount2 = 0; icount2< numchip; icount2++)
		{
			end = singlechipgame(slotnum, false);
			prize = prizewinnings(end);
			totalprize = totalprize + prize;
		}
		return totalprize;
	}
	
}			
		

int main()
{
	srand(time(0)); // always first line of main if used
	int menuchoice = 0;
	int icounter = 0;
	double singlechip = 0;
	int icount = 0;
	int icount2 = 0;
	int numchips = 0;
	int end = 0;
	int prize = 0;
	int totalprize = 0;
	int slot = 0;
	double ave = 0;
	

	
	do 
	{
		std::cout << "Select an option: \n(1) Drop one chip into one slot \n(2) Drop multiple chips into one slot\n(3)Drop multiple chips into each slot \n(4) Quit the program " << endl;
		std::cin >> menuchoice;
		if (menuchoice == 1)
		{
			std::cout << "Select a number 0-8"<< endl;
			std::cin >> singlechip;
			if(singlechip >= 0 && singlechip <= 8)
			{

			end = singlechipgame(singlechip, true);
			prize = prizewinnings(end);
			std::cout << "\nYou won $" << prize << "!!\n" <<endl;
			}
			else
			{
				std::cout << "\nError! Only numbers between 0 and 8 are valid.\n" << endl;
			}
		}
		else if (menuchoice == 2)
		{
			std::cout << "\nSelect a number of chips"<< endl;
			std::cin >> numchips;
			if(numchips > 0)
			{
				std::cout << "\nSelect a slot 0 to 8 to drop your chips." << endl;
				std::cin >> slot;
				if(slot >= 0 && slot < 9)
				{
					if(slot >= 0 && slot < 9)
					{
						totalprize=0;
						totalprize = multchipgame(numchips, slot);
						
					}
				

					std::cout << "\nYour total winnings are $" << totalprize << endl;
					ave = totalprize/numchips;
					std::cout << "Your average winnings are $" << ave << " per chip\n" << endl;
				}
				else
				{
					std::cout << "\nError! Only numbers between 0 and 8 are valid.\n" << endl;
				}
				
			}
			else
			{
				std::cout << "\n<Error! Only positive numbers are valid.>\n" << endl;
			}
			
		}
		else if (menuchoice == 3)
		{
			cout << "How many chips would you like to drop into each slot?" << endl;
			cin >> numchips;
			if(numchips > 0)
			{
				totalprize = 0;
				for(icount = 0;icount<9;icount++)
				{
					totalprize = multchipgame(numchips, icount);
					std::cout << "\nYour total winnings for slot " << icount << " are $" << totalprize << endl;
					ave = totalprize/numchips;
					std::cout << "Your average winnings for slot " << icount << " are $" << ave << " per chip\n" << endl;
				}
				
			}
			else
			{
				std::cout << "\n<Error! Only positive numbers are valid.>\n" << endl;
			}		
		}
		else if(menuchoice == 4)
		{
			std::cout << "Thanks, play again!" <<endl;
			return 0;
		}
		else 
		{
			cout << "Not a valid input, please enter a number 1-3" << endl;
		}
	}while (menuchoice != 4);

	system("pause");

}