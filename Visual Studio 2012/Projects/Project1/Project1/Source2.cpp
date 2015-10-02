#include <iostream> 
#include <string>
#include <limits>
using namespace std;

int main()
{
double gpa = 0;
int credits = 0;
string answer;

cin >> gpa;
cin >> credits;
cin >> answer;

if((gpa > 2.96) && (credits>13) && (answer=="No"))
{
	if(gpa >= 3.5)
	{
		cout << "Congratulations! You have been awarded $8000" << endl;
	}
	else if(gpa <=3.5)
	{
		cout << "Congratulations! You have been awarded $5000" << endl;
	}
}
else if((gpa>=3.9) && (credits <14))
{
	cout << "Congratulations! You have been awarded $8000" <<endl;
}
else cout << "Please apply again next year" << endl;
system("pause");
}