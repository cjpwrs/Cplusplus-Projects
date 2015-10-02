#include <iostream> 
#include <string>
#include <limits>
using namespace std;
// Test Case 1: I entered in a negative number for the miles per year and it prompted me to enter a valid positive number
// Test Case 2: I entered in a string value for the cost of a hybrid car and it prompted me to enter a valid positve number
// Test Case 3: I entered the criteria as "Gas" and it displayed the hybrid car first, which used the least gallons of gas
int main()
{
	int miles_per_year = 0;
	double price_per_gal =0.0;
	int cost_hybrid=0;
	int efficiency_hybrid=0;
	int estimate_resale_h=0;
	int cost_nonhybrid=0;
	int efficiency_nonhybrid=0;
	int estimate_resale_nh=0;
	int gas_5_years_h = 0;
	int gas_5_years_nh = 0;
	double total_cost_h = 0.0;
	double total_cost_nh = 0.0;
	string buying_criteria;
	

	cout << "Enter estimated miles per year:" << endl;
	if(!(cin>>miles_per_year) || miles_per_year<0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Only positive numbers are valid, please enter estimated miles per year:" << endl;
		cin >> miles_per_year;
	}

	

	cout << "Enter estimated price of a gallon of gas:" << endl;
	if(!(cin>>price_per_gal) || price_per_gal < 0.0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Only positive numbers are valid, please enter the estimated miles per year:" << endl;
		cin >> miles_per_year;
	}

	cout << "Enter the cost of a hybrid car:" << endl;
	if(!(cin>>cost_hybrid) || cost_hybrid < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Only positive numbers are valid, please enter the cost of a hybrid car:" << endl;
		cin >> cost_hybrid;
	}

	cout << "Enter the efficiency of the hybird car in miles per gallon:" << endl;
	if(!(cin>>efficiency_hybrid) || efficiency_hybrid < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Only positive numbers are valid, please enter the effciency of the hybrid car in miles per gallon:" << endl;
		cin >> efficiency_hybrid;
	}

	cout << "Enter the estimated resale value for a hybrid after 5 years:" << endl;
	if(!(cin>>estimate_resale_h) || estimate_resale_h<0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Only positive numers are valid, please enter estimated miles per year:" << endl;
		cin >> estimate_resale_h;
	}

	cout << "Enter the cost of a non-hybrid car:" << endl;
	if(!(cin>>cost_nonhybrid) || cost_nonhybrid < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Only positve numbers are valid, please enter the cost of a non-hybrid car:" << endl;
		cin >> cost_nonhybrid;
	}

	cout << "Enter the efficiency of the non-hybrid car in miles per gallon:" << endl;
	if(!(cin>>efficiency_nonhybrid) || efficiency_nonhybrid < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Only positive numbers are valid, please enter the efficiency of the non-hybrid car in miles per gallon:" << endl;
		cin >> efficiency_nonhybrid;
	}

	cout << "Enter the estimated resale value for a non-hybrid car after 5 years:" << endl;
	if(!(cin>>estimate_resale_nh) || efficiency_nonhybrid < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Only positive numbers are valid, please enter the estimated resale value for a non-hybrid car after 5 years:" << endl;
		cin >> estimate_resale_nh;
	}

	cout << "Enter your buying criteria, 'Gas' consumption or 'Total' cost:" << endl;
	cin >> buying_criteria;
	gas_5_years_h = (miles_per_year * 5)/efficiency_hybrid;
	gas_5_years_nh = (miles_per_year * 5)/efficiency_nonhybrid;
	total_cost_h = (((miles_per_year * 5)/efficiency_hybrid) * price_per_gal) + (cost_hybrid - estimate_resale_h);
	total_cost_nh = (((miles_per_year * 5)/efficiency_nonhybrid) * price_per_gal) + (cost_nonhybrid - estimate_resale_nh);

	if(buying_criteria=="Gas")
	{
		if(gas_5_years_h <= gas_5_years_nh)
		{
			cout << "" << endl;
			cout << "Car Type: Hybrid" << endl;
			cout << "Total gallons of fuel used for 5 years: " <<  gas_5_years_h << " gallons" << endl;
			cout << "Total cost of owning the car for 5 years: $" << total_cost_h << endl;
			cout << "" << endl;
			cout << "Car Type: Non-Hybrid" << endl;
			cout << "Total gallons of fuel used for 5 years: " <<  gas_5_years_nh << " gallons" << endl;
			cout << "Total cost of owning the car for 5 years: $" << total_cost_nh << endl;
			
		}
		else
		{
			cout << "" << endl;
			cout << "Car Type: Non-Hybrid" << endl;
			cout << "Total gallons of fuel used for 5 years: " <<  gas_5_years_nh << " gallons" << endl;
			cout << "Total cost of owning the car for 5 years: $" << total_cost_nh << endl;
			cout << "" << endl;
			cout << "Car Type: Hybrid" << endl;
			cout << "Total gallons of fuel used for 5 years: " <<  gas_5_years_h << " gallons" << endl;
			cout << "Total cost of owning the car for 5 years: $" << total_cost_h << endl;
		}

	}

	if (buying_criteria == "Total")
	{
		if(total_cost_h <= total_cost_nh)
		{
			cout << "" << endl;
			cout << "Car Type: Hybrid" << endl;
			cout << "Total gallons of fuel used for 5 years: " <<  gas_5_years_h << " gallons" << endl;
			cout << "Total cost of owning the car for 5 years: $" << total_cost_h << endl;
			cout << "" << endl;
			cout << "Car Type: Non-Hybrid" << endl;
			cout << "Total gallons of fuel used for 5 years: " <<  gas_5_years_nh << " gallons" << endl;
			cout << "Total cost of owning the car for 5 years: $" << total_cost_nh << endl;
		}
		else
		{
			cout << "" << endl;
			cout << "Car Type: Non-Hybrid" << endl;
			cout << "Total gallons of fuel used for 5 years: " <<  gas_5_years_nh << " gallons" << endl;
			cout << "Total cost of owning the car for 5 years: $" << total_cost_nh << endl;
			cout << "" << endl;
			cout << "Car Type: Hybrid" << endl;
			cout << "Total gallons of fuel used for 5 years: " <<  gas_5_years_h << " gallons" << endl;
			cout << "Total cost of owning the car for 5 years: $" << total_cost_h << endl;
		}
	}

	system("pause");
    return 0;
}