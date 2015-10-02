#include "Car.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdlib.h> 
#include <stdio.h>
#include <fstream>
#include <cctype>

using namespace std;

int find(vector<Car> cars, string nameofcar)
{
	for(int icount = 0; icount<cars.size(); icount++)
	{
		if(cars[icount].getName() == nameofcar)
		{
			return icount;
		}
	}
	return -1;
}




int main()
{
	int input = 0;
	double balance = 10000;
	vector<Car> collection;

	do
	{
		cout << "(1) Show Current Inventory\n(2) Show Current Balance\n(3) Buy a Car\n(4) Sell a Car\n(5) Paint a Car\n(6) Load File\n(7) Save File\n(8) Quit Program\n" << endl;
		cin >> input;
		
		//Show Current inventory
		if(input == 1)
		{
			for(int icount = 0; icount < collection.size(); icount++)
			{
				cout << collection[icount].toString();
			}
		}

		//Show Current Balance
		if(input == 2)
		{
			cout << balance << endl;
		}

		//Buy a car
		if(input == 3)
		{
			string carname;
			string color;
			double price = 0;
			int valid = 0;
			cout << "What is the car name?" << endl;
			cin >> carname;
			valid = find(collection, carname);
			if(valid == -1)
			{
				cout << "What is the color of the car?" << endl;
				cin >> color;
				cout << "How much is the car?" << endl;
				cin >> price;
				if(price <= balance)
				{
					Car newcar =  Car(carname, color, price);
					collection.push_back(newcar);
					balance-= price;
				}
				else
				{
					cout << "This car costs too much, try again." <<  endl;
				}

			}
			else if(valid >= 0)
			{
				cout << "This car is already in inventory, enter a car that you don't already have" << endl;
			}

		}

		//Sell a car
		if(input == 4)
		{
			string carname;
			string color;
			double price = 0;
			int valid = 0;
			cout << "What is the car name?" << endl;
			cin >> carname;
			valid = find(collection, carname);
			if(valid >= 0)
			{
				balance += collection[valid].getPrice();
				collection.erase(collection.begin() + valid);
			}
			else if(valid == 0)
			{
				cout << "You do not own this car, enter a car that you have in inventory." << endl;
			}
		}

		//Paint a car
		if(input == 5)
		{
			string carname;
			string color;
			double price = 0;
			int valid = 0;
			cout << "What is the car name?" << endl;
			cin >> carname;
			valid = find(collection, carname);
			if(valid >= 0)
			{
				cout << "What color would you like to paint the car?" << endl;
				cin >> color;
				collection[valid].paint(color);
			}
			else if(valid == -1)
			{
				cout << "You do not own this car, try again." << endl;
			}
		}

		//Load File
		if(input == 6)
		{
		//reading
			double tempbalance;
			string filename;
			ifstream  in;
			cout << "Enter the file name to be read: ";
			cin >> filename;
			in.open(filename);
			in >> tempbalance;
			balance += tempbalance;
			string name;
			string color;
			double price;
			while(in >> name >> color >> price)
			{
				Car newcar(name, color, price);
				collection.push_back(newcar);
			}
	

			in.close();
		}

		//Save File
		
		if(input == 7)
		{
		//writing
			string filename;
			ofstream out;
			cout << "Enter a file to write to: ";
			cin >> filename;
			out.open(filename);
			out << balance << endl;
			for(int icount = 0; icount<collection.size(); icount++)
			{	
				out <<collection[icount].getName()<<endl;
				out <<collection[icount].getColor()<<endl;
				out <<collection[icount].getPrice() << endl;
			}

			out.close();
		}

		//Quit Program
		if(input == 8)
		{
			return 0;
		}


	}while(input != 8);
	
    system("pause");
    return 0;
}
