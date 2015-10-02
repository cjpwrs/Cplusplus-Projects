
#include <iostream>  
#include <string>                                   
using namespace std;

int main()
{
int iguests = 0;
int ilarge = 0;
int imedium = 0;
int ismall = 0;
int icost = 0;
int itip = 0;
double darea = 0;
double dperson_area = 0;
    cout << "How many pizzas do you need?" << endl; 
	cin >> iguests;
	
	if(iguests>=7)
	{
		ilarge = iguests/7;
	}
	if(iguests-(ilarge*7)>=3)
	{
		imedium = (iguests-(ilarge*7))/3;
	}
	if( iguests-(ilarge*7)-(imedium*3) >= 1)
	{
		ismall = (iguests-(ilarge*7)-(imedium*3))/1;
	}
	darea = (ilarge*(3.14159 *(10*10))) + (imedium*(3.14159 * (8*8))) + (ismall*(3.14159 *(6*6)));
	dperson_area = darea/iguests;

	cout << "How much percent of the total price would you like to pay as a tip?" << endl;
	cin >> itip;
	icost = ((itip*.01)+1) * ((ilarge*14.68)+(imedium*11.48)+(ismall*7.28)) +.5;
	
	cout << "People\tTip\tLarges\tMediums\tSmalls\tArea\tArea/Person\tCost" << endl;
	cout << iguests << "\t" << itip << "\t" << ilarge << "\t" << imedium << "\t" << ismall << "\t";
	cout << darea << "\t" << dperson_area << "\t\t" << icost << endl;




	
   system("pause");
    
}