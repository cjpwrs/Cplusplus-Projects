#include <iostream> 
#include <array>
#include <fstream>

using namespace std;

bool updateposition(double myarray[20][20])
{
	bool repeat = false;
	int x = 0;
	int y = 0;
	double initial = 0;

	for(x = 0; x < 20; x++)
	{
		for(y = 0; y < 20; y++)
		{
			initial = myarray[x][y];
			if((x > 0 && x < 19) && (y > 0 && y < 19))
			{
				myarray[x][y] = (myarray[x+1][y] + myarray[x-1][y] + myarray[x][y +1] + myarray[x][y - 1]) / 4;		
			}
			else
			{
				myarray[x][y] = initial;
			}
			if(repeat == false)
			{
				if(abs(initial - myarray[x][y]) >  .1)
				{
					repeat = true;
				}
			}
		}
	}				
	return repeat;
}

double initialize( double myarray[20][20])
{
	int icount = 0;
	int icount2 = 0;
	//initialize counts

	for(icount = 0; icount < 20; icount++)
	{
		for(icount2 = 0; icount2 < 20; icount2++)
		{
			if(icount == 0 || icount == 19)
			{
				if(icount2 > 0 && icount2 <19)
				{
					myarray[icount][icount2] = 100;
				}
				else
				{
				 myarray[icount][icount2] = 0;
				}
			}
			else
			{
			 myarray[icount][icount2] = 0;
			}	
		}
		
		//return 0; 
	}
	return myarray[icount][icount2];
}

double printarray(double myarray[20][20])
{
	int icount = 0;
	int icount2 = 0;
	//initialize counts

	for(icount = 0; icount <20; icount++)
	{
		for(icount2 = 0; icount2 < 20; icount2++)
		{
			cout << myarray[icount][icount2] << ",";
		}
		cout << "\n";
	}
	cout << "\n\n";
	return 0;
}

int main()
{
	ofstream myfile;


		bool update = true;
		double hotplate[20][20];

		initialize(hotplate);

		printarray(hotplate);

		updateposition(hotplate);
		printarray(hotplate);

		while(updateposition(hotplate) == true)
		{
		updateposition(hotplate);
		}

		printarray(hotplate);

		myfile.open("hotplate.csv");
		int icount = 0;
		int icount2 = 0;
		//initialize counts

		for(icount = 0; icount <20; icount++)
		{
			for(icount2 = 0; icount2 < 20; icount2++)
			{
				myfile << hotplate[icount][icount2] << ",";
			}
			myfile << "\n";
		}
		myfile.close();

    system("pause");
    return 0;
}