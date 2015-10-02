#include <iostream> 
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

/*
TEST 1: I entered negative numbers in all possible entries for chips and i made sure my program only accepted valid entries for slots which is 0-8;
TEST 2: I tested the boarders of my plinko board by entering in a chip to the slot 0 and to the slot 8 and i made sure the chip didnt go negative or go above 8
TEST 3: On Multiple chips I used break points to check and see if my slot was being reset to the original value that the user entered in, meaning that that after every game it got reset to the original value.
*/
using namespace std;
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
	
	cout << "Select an option: \n(1) Drop one chip into one slot \n(2) Drop multiple chips into one slot \n(3) Quit the program " << endl;
	cin >> menuchoice;
	
	while (menuchoice != 3)
	{
		if (menuchoice == 1)
		{
			cout << "Select a number 0-8"<< endl;
			cin >> singlechip;

			if(singlechip >= 0 && singlechip <= 8)
			{
 
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
					cout<< singlechip << endl;

				}
				end = singlechip ;
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
				cout << "\nYou won $" << prize << "!!\n" <<endl;
			}
			else
			{
				cout << "\nError! Only numbers between 0 and 8 are valid.\n" << endl;
			}

			
		}
		else if (menuchoice == 2)
		{
			cout << "\nSelect a number of chips"<< endl;
			cin >> numchips;
			if(numchips > 0)
			{
				cout << "\nSelect a slot 0 to 8 to drop your chips." << endl;
				cin >> slot;
				if(slot >= 0 && slot < 9)
				{
					totalprize=0;
					for(icount2 = 0; icount2< numchips; icount2++)
					{
					singlechip = slot;
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
							//cout<< singlechip << endl;

						}
						end = singlechip ;
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
						//cout << "You won $" << prize << "!!" <<endl;
						totalprize = totalprize + prize;
					}
					cout << "\nYour total winnings are $" << totalprize << endl;
					ave = totalprize/numchips;
					cout << "Your average winnings are $" << ave << " per chip\n" << endl;
				}
				else
				{
					cout << "\nError! Only numbers between 0 and 8 are valid.\n" << endl;
				}
				
			}
			else
			{
				cout << "\n<Error! Only positive numbers are valid.>\n" << endl;
			}
			
		}
		else 
		{
			cout << "Not a valid input, please enter a number 1-3" << endl;
		}
		cout << "Select an option: \n(1) Drop one chip into one slot \n(2) Drop multiple chips into one slot \n(3) Quit the program " << endl;
		cin >> menuchoice;
	}
	cout << "Thanks, play again!" <<endl;
	system("pause");

}
