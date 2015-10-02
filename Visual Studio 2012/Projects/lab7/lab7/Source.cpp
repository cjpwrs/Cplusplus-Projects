#include <iostream> 
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void printvector(vector<string> myvector) 
{
		for(int icount = 0; icount < myvector.size(); icount++)
		{
			if(icount != myvector.size() -1)
			{
				cout << myvector[icount] << ", ";
			}
			else
			{
				cout << myvector[icount];
			}
		}
		cout << "\n";
}

void deleterest(vector<string>& myvector)
{
		string deleterest;
		bool exists = false;
		cin.ignore(1);
		cout << "Which restaurant do you want to delete?" << endl;
		getline(cin, deleterest);

		for(int icount = 0; icount < myvector.size(); icount++)
		{
			if(myvector[icount]== deleterest)
			{
				int pos = myvector.size() - 1;
				exists = true;
				cout << "This restaurant has been deleted" << endl;

				myvector[icount] = myvector[pos];
				myvector.pop_back();
			}
		}
		if(exists == false)
		{
			cout << "This restaurant does not exist" << endl;
		}
}

int main()
{
	srand(time(NULL));
	vector<string> restaurants(16);

	restaurants[0] = "Taco Bell";
	restaurants[1] = "Del Taco";
	restaurants[2] = "Kneaders";
	restaurants[3] = "McDonalds";
	restaurants[4] = "Burger King";
	restaurants[5] = "Cafe Rio";
	restaurants[6] = "Costa Vida";
	restaurants[7] = "Happy Sumo";
	restaurants[8] = "In and Out";
	restaurants[9] = "Red Robin";
	restaurants[10] = "Panda Express";
	restaurants[11] = "Subway";
	restaurants[12] = "Jimmy Johns";
	restaurants[13] = "Dominos";
	restaurants[14] = "Wendys";
	restaurants[15] = "Whichwich";

	int choice = 0;
	do
	{
	cout << "\n\n(1)Display all restaurants\n(2)Add a restaurant\n(3)Remove a restaurant\n(4)Shuffle the vector\n(5)Begin the tournament\n(6)Quit program" << endl;
	cin >> choice;
	 
	if(choice == 1)
	{
		printvector(restaurants);
	}
	if(choice == 2)
	{
		string newrest;
		cin.ignore(1);
		cout << "Enter a new restaurant name:" << endl;
		getline(cin, newrest);
		bool exists = false;

		for(int icount = 0; icount < restaurants.size(); icount++)
		{
			if(restaurants[icount] == newrest)
			{
				cout <<"This restaurant already exists, enter a restaurant that is not already on the list" << endl;
				exists = true;
			}
		}
		if(exists == false)
		{
			restaurants.push_back(newrest);
			cout << newrest << " has been added to the list." << endl;
		}
	}
	if(choice == 3)
	{
		deleterest(restaurants);
	}
	if (choice == 4)
	{
		for ( int icount = 0; icount<100; icount++)
		{
			int x = rand() % restaurants.size();
			int y = rand() % restaurants.size();
			string original = restaurants[y];
			restaurants[y] = restaurants[x];
			restaurants[x] = original;
		}
		cout << "The list has been shuffled" << endl;
	}
	if (choice == 5)
	{
		vector<string> newvector(restaurants);
		bool valid = false;
		double num = 0;
		cin.ignore(1);

		num = newvector.size() % 2;
		if(num == 0)
		{
			valid = true;
		}
		if (valid == true)
		{
			while(newvector.size()>1)
			{
				for(int icount = 0; icount < newvector.size(); icount++)
				{

					cout<< "Please choose your favorite between:" << endl;
					cout << newvector[icount] << " and " << newvector[icount + 1] << endl;
					string answer;
					bool exists = false;
					do
					{
					getline(cin, answer);

					if(answer == newvector[icount])
					{
						newvector.erase(newvector.begin() + icount + 1);
						exists = true;
					}
					else if(answer == newvector[icount + 1])
					{
						newvector.erase(newvector.begin() + icount);
						exists = true;
					}
					else
					{
						cout << "This is not a valid restaurant, please choose one of the 2 options." << endl;
					}
					}while(exists == false);
					//printvector(newvector);

				}
			}
			cout << newvector[0] << " is the winner!" << endl;
		}
		else
		{
			cout << "The number of restaurants needs to be an even number" << endl;
		}
	}
	}while(choice != 6);
	system("pause");
    return 0;
}