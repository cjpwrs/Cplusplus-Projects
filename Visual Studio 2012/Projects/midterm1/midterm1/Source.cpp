#include <iostream> 
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
	srand(time(0));
	string decision= "yes";
	string tablematch;
	int itable1=0;
	int itable2=0;
	int itable3=0;
	int itable4=0;
	int itable5=0;
	int ACTScore=0;
	int count =0;
	int row = 0;
	int binary = 0;
	double r = 0;

	while(decision == "yes")
	{
//this is the start of table 1
		r= rand()%2;
		if(r == 0)
		{
			for(count = 5; count<37; count++)
			{
				binary = count%2;
				if(binary==1)
				{
					cout << count << "\t";
					row ++;
					if (row==4)
					{
						cout << endl;
						row = 0;
					}
				}

			}
			//do
			//{
			/*	std::cout << "Is your score in this table?(yes or no)" << endl;
				std::cin >> tablematch;
				if(tablematch == "yes")
				{
					itable1=1*1;
				}
				else if (tablematch == "no")
				{
					itable1= 0*1;
				}
				else
				{
					std::cout << "Not a valid input, only yes or no are valid answers." << endl;
				}
			//}while(tablematch != "yes" || tablematch!= "no");
		}
		else if(r == 1)
		{
			for(count = 5; count<37; count++)
			{
				binary = count%2;
				if(binary==0)
				{
					cout << count << "\t";
					row ++;
					if (row==4)
					{
						cout << endl;
						row = 0;
					}
				}

			}
			//do
			//{
				std::cout << "Is your score in this table?(yes or no)" << endl;
				std::cin >> tablematch;
				if(tablematch == "no")
				{
					itable1=1*1;
				}
				else if (tablematch == "yes")
				{
					itable1= 0*1;
				}
				else
				{
					std::cout << "Not a valid input, only yes or no are valid answers." << endl;
				}
			//}while(tablematch != "yes" || tablematch != "no");
		}

//this is the start of table 2
		r= rand()%2;
		if(r == 0)
		{
		for(count = 5; count<37; count++)
		{
			binary = (count/2)%2;
			if(binary == 1)
			{
				cout << count << "\t";
				row ++;
				if (row==4)
				{
					cout << endl;
					row = 0;
				}
			}

		}
			std::cout << "Is your score in this table?(yes or no)" << endl;
			std::cin >> tablematch;
			if(tablematch == "yes")
			{
				itable2=1*2;
			}
			else if (tablematch =="no")
			{
				itable2= 0*2;
			}
		}
		else if(r == 1)
		{
		for(count = 5; count<37; count++)
		{
			binary = (count/2)%2;
			if(binary == 0)
			{
				cout << count << "\t";
				row ++;
				if (row==4)
				{
					cout << endl;
					row = 0;
				}
			}

		}
			std::cout << "Is your score in this table?(yes or no)" << endl;
			std::cin >> tablematch;
			if(tablematch == "no")
			{
				itable2=1*2;
			}
			else if (tablematch == "yes")
			{
				itable2= 0*2;
			}
		}

//This is the start of table 3
		r= rand()%2;
		if(r == 0)
		{
		for(count = 5; count<37; count++)
		{
			binary = ((count/2)/2)%2;
			if(binary == 1)
			{
				cout << count << "\t";
				row ++;
				if (row==4)
				{
					cout << endl;
					row = 0;
				}
			}

		}
			std::cout << "Is your score in this table?(yes or no)" << endl;
			std::cin >> tablematch;
			if(tablematch == "yes")
			{
				itable3=1*4;
			}
			else if (tablematch =="no")
			{
				itable3= 0*4;
			}
		}
		else if(r == 1)
		{
		for(count = 5; count<37; count++)
		{
			binary = ((count/2)/2)%2;
			if(binary == 0)
			{
				cout << count << "\t";
				row ++;
				if (row==4)
				{
					cout << endl;
					row = 0;
				}
			}

		}
			std::cout << "Is your score in this table?(yes or no)" << endl;
			std::cin >> tablematch;
			if(tablematch == "no")
			{
				itable3=1*4;
			}
			else if (tablematch == "yes")
			{
				itable3= 0*4;
			}
		}

//this is the start of table 4
		r= rand()%2;
		if(r == 0)
		{
		for(count = 5; count<37; count++)
		{
			binary = (((count/2)/2)/2)%2;
			if(binary == 1)
			{
				cout << count << "\t";
				row ++;
				if (row==4)
				{
					cout << endl;
					row = 0;
				}
			}

		}
			std::cout << "Is your score in this table?(yes or no)" << endl;
			std::cin >> tablematch;
			if(tablematch == "yes")
			{
				itable4=1*8;
			}
			else if (tablematch =="no")
			{
				itable4= 0*8;
			}
		}
		else if(r == 1)
		{
		for(count = 5; count<37; count++)
		{
			binary = (((count/2)/2)/2)%2;
			if(binary == 0)
			{
				cout << count << "\t";
				row ++;
				if (row==4)
				{
					cout << endl;
					row = 0;
				}
			}

		}
			std::cout << "Is your score in this table?(yes or no)" << endl;
			std::cin >> tablematch;
			if(tablematch == "no")
			{
				itable4 = 1*8;
			}
			else if (tablematch == "yes")
			{
				itable4 = 0*8;
			}
		}

//this is the start of table 5
		r= rand()%2;
		if(r == 0)
		{
		for(count = 5; count<37; count++)
		{
			binary = ((((count/2)/2)/2)/2)%2;
			if(binary == 1)
			{
				cout << count << "\t";
				row ++;
				if (row==4)
				{
					cout << endl;
					row = 0;
				}
			}

		}
			std::cout << "Is your score in this table?(yes or no)" << endl;
			std::cin >> tablematch;
			if(tablematch == "yes")
			{
				itable5=1*16;
			}
			else if (tablematch =="no")
			{
				itable5= 0*16;
			}
		}
		else if(r == 1)
		{
		for(count = 5; count<37; count++)
		{
			binary = ((((count/2)/2)/2)/2)%2;
			if(binary == 0)
			{
				cout << count << "\t";
				row ++;
				if (row==4)
				{
					cout << endl;
					row = 0;
				}
			}

		}
			std::cout << "Is your score in this table?(yes or no)" << endl;
			std::cin >> tablematch;
			if(tablematch == "no")
			{
				itable5=1*16;
			}
			else if (tablematch == "yes")
			{
				itable5= 0*16;
			}
		}

		ACTScore = itable1 + itable2 + itable3 + itable4 + itable5;
		if(ACTScore>4)
		{
			std::cout << ACTScore << endl;
		}
		else if(ACTScore<5)
		{
			ACTScore = ACTScore + 32;
			std::cout << ACTScore << endl;
		}

		std::cout << "Do you want to repeat the process?(yes or no)" << endl;
		std::cin >> decision;*/
	}
	
	system("pause");

}