#ifndef __PRINTSCORE_H
#define __PRINTSCORE_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdlib.h> 
#include <stdio.h>
#include <fstream>

using namespace std;

void printScore(vector<string> scores, string playerName);

//this determines the awards for each series
void awards(bool strikes, bool gutters, bool club, bool perfect)
{
	if(strikes == true)
	{
		cout << "Congratulations! You won the \"Turkey\" award!" << endl;
	}
	if(gutters == true)
	{
		cout << "Congratulations! You won the \"Keep your day job\" award!" << endl;
	}
	if(club == true)
	{
		cout << "Congratulations! You won the \"200 Club\" award!" << endl;
	}
	if(perfect == true)
	{
		cout << "Congratulations! You won the \"Perfect Game\" award!" << endl;
	}
}
double gamesaverage(vector<int> myvector)
//this calculates the average score at the end
{
	double average = 0;
	int totalpoints = 0;
	for(int icount = 0; icount < myvector.size(); icount++)
	{
		totalpoints = totalpoints + myvector[icount];
	}
	average = totalpoints / myvector.size();
	return average;
}
//this determines the number of games to be played
int numofgames(int numofframes)
{
	int games = 0;
	games = numofframes / 10;
	return games;		
}
//this solves for the total score
int score(int totalpoints, int f1, int f2, int f3)
{
	totalpoints = totalpoints + f1 + f2 + f3; 
	return totalpoints;
}





int main()
{

	string playername;
	int frames;
	int games;
	string keepplaying;
	//declare variables
	
	do
	{
		cout << "What is your name?" << endl;
		getline(cin, playername);

		cout << "How many frames would you like to play?" << endl;
		//prompt for how many frames
		vector<int> gametotals;
		bool valid = false;
		bool strikeaward = false;
		bool gutteraward = false;
		bool twoclub = false;
		bool perfectgame = false;
		int totstrikecount = 0;
		int totsparecount = 0;
		double pointsaverage = 0;
		//declare variables

		while(valid == false)
		{
			cin >> frames;
			games = numofgames(frames);
			if(frames < 10)
			{
				cout << "That number of frames has to be at least 10, try again" << endl;
				//print error statement if the number of frames is less than 10
			}
			else
			{
				cout << "You will play " << games << " games." << endl;
				valid = true;
				//tell player how many games will be played
			}
		
		}
		for(int gamecount = 0; gamecount < games; gamecount++)
		{
			int input = 0;
			int total = 0;
			int rowstrikecount = 0;
			int rowguttercount = 0;
			bool correctinput = true;
			//delare variables
		
			cout << "Starting game " << gamecount + 1 << " of " << games << endl;
			cout << "\nHow will you provide input?(1 = User input, 2 = File input, 3 = Randomly generate)" << endl;
			//check which input for each game
			do
			{
				correctinput = true;
				cin >> input;
				if(input!= 1 && input!=2 && input!=3)
				//check validity of inputs
				{
					correctinput = false;
					cout << "Only 1, 2, or 3 are valid inputs. Try again." <<endl;
				}
			}while(correctinput == false);
			vector<string> scoretable;
			if(input == 1)
			//manual input
			{
			
				for(int framecount = 0; framecount < 10; framecount++)
				//loop for each frame of the game, up to 10 frames
				{
					string frame1;
					string frame2;
					string frame3;
					string tot;
					int f1 = 0;
					int f2 = 0;
					int f3 = 0;
					//declare variables
								
					bool do2 = true;
					bool do3 = true;
					bool findtot = true;
					bool validframe = false;
					bool openframe = false;
					bool doublestrike = false;
					bool triplestrike = false;
					bool doublespare = false;
					bool strikespare = false;
					bool sparestrike = false;
					bool lastframe = false;
					//declare all boolean values
				
					if(framecount == 9)
					// check to see if the game is on the last frame
					{
						lastframe = true;
					}
					do
					{
					//loop while the answers are invalid
						validframe = false;
						openframe = false;
						cout << "Roll 1 of frame " << framecount + 1 << ": ";
						cin >> frame1;
						//input score for frame 1
						if(frame1 == "1" || frame1 == "2" || frame1 == "3" || frame1 == "4" || frame1 == "5" || frame1 == "6" || frame1 == "7" || frame1 == "8" || frame1 == "9" || frame1 == "G" || frame1 == "F" || frame1 == "X")
						//check validity
						{
							validframe = true;
						}
						else
						{
						cout << "Invalid score input, try again." << endl;
						}
					}while(validframe == false);

						if(lastframe == true)
						//these are only for the final frame of the game
						{
							do2 = true;
							if(frame1 == "X")
							{
								totstrikecount++;
								f1 = 10;
								do3 = true;
							}
							else if(frame1 == "G")
							{
								f1 = 0;
								do3 = false;
								frame3 = "-";
							}
							else
							{
								f1 = atoi(frame1.c_str());
								do3 = false;
								frame3 = "-";
							}
						}
						else if(lastframe == false)
						{
							if(frame1 =="G")
							{
								do2 = true;
								findtot = true;
								f1 = 0;
							}
							else if(frame1 == "F")
							{
								do2 = true;
								findtot = true;
								f1 = 0;
							}
							else if(frame1 =="X")
							{
								do2 = false;
								findtot = false;
								openframe = false;
								frame2 = "-";
								tot = "#";
								totstrikecount++;
								if(scoretable.size() > 2)
								{
									if(scoretable[scoretable.size() - 3] == "X")
									{
										cout << scoretable[scoretable.size() - 3];
										rowstrikecount++;
										if(rowstrikecount >= 2)
										{
											strikeaward = true;
										}
									}
									else
									{
										rowstrikecount = 0;
									}
								}
							}
							else
							{
								f1 = atoi(frame1.c_str());
								do2 = true;
							}
						}
						if(do2 ==true)
						{
							do
							{
							//do this loop as long as input is invalid
							validframe = false;
							cout << "Roll 2 of frame " << framecount + 1 << ": ";
							cin >> frame2;
							if(frame2 == "1" || frame2 == "2" || frame2 == "3" || frame2 == "4" || frame2 == "5" || frame2 == "6" || frame2 == "7" || frame2 == "8" || frame2 == "9" || frame2 == "G" || frame2 == "F" || frame2 == "X" || frame2 == "/")
							{
								validframe = true;
							}
							else
							{
								cout << "Invalid score input, try again." << endl;
								validframe = false;
							}

							if (lastframe == true)
							//these are only for the final frame of the game
							{
								if(frame2 == "X")
								{
									f2 = 10;
									totstrikecount++;
									do3 = true;
								}
								//if spare
								else if(frame2 == "/")
								{
									f1 = 0;
									f2 = 10;
									do3 = true;
								}
								//if gutter ball
								else if(frame2 == "G")
								{
									f2 = 0;
								}
								//if foul
								else if(frame2 == "F")
								{
									f2 = 0;
								}
								else
								{
									f2 = atoi(frame2.c_str());
								}
								if(do3 ==true)
								{
									//these only apply for the final frame
									cout << "Roll 3 of frame " << framecount + 1 << ": ";
									cin >> frame3;
									if(frame3 == "X")
									{
										f3 = 10;
										totstrikecount++;
									}
									//if spare
									else if(frame3 == "/")
									{
										f3 = 10;
										f2 = 0;
									}
									//if gutterball
									else if(frame3 == "G")
									{
										f3 = 0;
									}
									//if foul
									else if(frame3 == "F")
									{
										f3 = 0;
									}
									else
									{
										f3 = atoi(frame3.c_str()); 
										//converts string to int
									}
								}
							}
							else if(lastframe == false)
							{
								//if spare
								if(frame2=="/")
								{
									findtot = false;
									openframe = false;
									tot = "#";
									totsparecount++;
								}
								//if gutter ball
								else if(frame2 == "G")
								{
									findtot = true;
									f2 = 0;
									openframe = true;
								}
								//if foul
								else if(frame2 == "F")
								{
									findtot = true;
									f2 = 0;
									openframe = true;
								}
								else
								//converts string to an int
								{
									f2 = atoi(frame2.c_str());
								}
								//determines if openframe
								if(f1>=0 && f1 <10 && f2 >= 0 && f2 < 10)
								{
									openframe = true;
								}
									
								//this is to validate that the sum of the two rolls is not larger than 9
								if(do2 = true && f1+f2+f3 > 9 && frame2 != "/" && frame2!= "G" && frame2!= "F")
								{
									validframe = false;
									cout << "Invalid score inputs, the sum of the two rolls must be from 0 to 9 pins, try again." << endl;
								}
							}
							
						}while(validframe == false);
					}
					if(scoretable.size() > 2)
					{
						//these statements determine 2 strikes in a row or 2 spares in a row and set booleans to true
						int location = scoretable.size() - 3;
						int sparelocation = scoretable.size() - 2;
						if(scoretable[location] == "X" && frame1 == "X")
						{
							doublestrike = true;
						}
						else if(scoretable[sparelocation] == "/" && frame2 =="/")
						{
							doublespare = true;
						}
						else if(scoretable[sparelocation] =="/" && frame1 =="X")
						{
							sparestrike = true;
						}
						else if(scoretable[location] =="X" && frame2 == "/")
						{
							strikespare = true;
						}
						if(scoretable.size()>5)
						{
							//if there are 2 or 3 strikes in a row then set the booleans to true
							if(scoretable[location] == "X" && scoretable[location - 3] =="X")
							{
								doublestrike = true;
							}
							if(scoretable[location - 3] =="X" && scoretable[location] == "X" && frame1 == "X")
							{
								triplestrike = true;
							}
						}
						if(scoretable.size() >8)
						{
							//if there are three strikes in a row, then set booleans to true
							if(scoretable[location] == "X" && scoretable[location - 3] == "X" && scoretable[location - 6] == "X")
							{
								doublestrike = true;
								triplestrike = true;
							}
						}

						//These if statements solve for multiple occurences of strikes or spares in a row
						if(scoretable[location] == "X" && strikespare == true)
						{
							findtot = false;
							int striketotal = total + 20;
							total = striketotal;
							scoretable[location + 2] = to_string(striketotal);
						}
						//solve for a single strike
						else if( scoretable[location] == "X" && openframe == true && doublestrike == false && triplestrike == false)
						{
							findtot = false;
							total = total + 10 + (f1*2) + (f2*2);
							tot = to_string(total);
							int updatescore = total - f1 - f2;
							scoretable[location + 2] = to_string(updatescore);
						}
						//solve for a single spare
						if(scoretable[location + 1] == "/"  && doublespare == false)
						{
							findtot = false;
							int spare1total = total + 10 + f1;
							total = spare1total + f1 + f2;
							tot = to_string(total);
							scoretable[sparelocation +1] = to_string(spare1total);
						}
						//solves when a spare and strike occur right after eachother
						if(scoretable[sparelocation] == "/" && doublespare == true)
						{
							findtot = false;
							int spare1total = total + 10 + f1;
							total = spare1total;
							scoretable[sparelocation +1] = to_string(spare1total);
						}
						//for when a spare and strike occur right after eachother
						if(scoretable[sparelocation] == "/" && sparestrike == true)
						{
							findtot = false;
							int sparetotal = total + 20;
							total = sparetotal;
							scoretable[sparelocation + 1] = to_string(sparetotal);
						}
						//in order to have 2 strikes in a row, the player has to complete at least 2 frames
						if(scoretable.size() > 5)
						{
							if(scoretable[location] == "X" && scoretable[location - 3] =="X" && openframe == true && triplestrike == false)
							{
								findtot = false;
								int total1 = total + 10 + 10 +f1;
								int total2 = total1 + 10 + f1 + f2;
								total = total2 + f1 + f2;
								tot = to_string(total);
								scoretable[location + 2] = to_string(total2);
								scoretable[location - 1] = to_string(total1);
							}
						}
						//in order to have 3 strikes in a row, the person has to at least have completed 3 frames
						if(scoretable.size() > 8)
						{
							if(frame1 =="X" && scoretable[location] == "X" && scoretable[location - 3] == "X" && scoretable[location - 6] == "X")
							{
								//these if statements solve for the last frame of the game, if there are strikes
								if(lastframe == true)
								{
									//calculate score for a double strike
									if(frame1 == "X" && frame2 == "X")
									{
										findtot = true;
										int total1 = total + 30;
										int total2 = total1 + 30;
										int total3 = total2 + 30;
										total = total3;
										scoretable[location + 2] = to_string(total3);
										scoretable[location - 1] = to_string(total2);
										scoretable[location - 4] = to_string(total1);
									}
									else if(frame1 == "X")
									//calculate score for a single strike
									{
										findtot = true;
										int total1 = total + 30;
										int total2 = total1 + 20 + f1;
										scoretable[location - 1] = to_string(total2);
										scoretable[location - 4] = to_string(total1);
									}
								}
								else if(lastframe ==false)
								//only for final frame
								{
									int total1 = total + 30;
									total = total1;
									scoretable[location - 4] = to_string(total1);
								}
							}
							//this function is for when there are 3 strikes in a row
							else if(scoretable[location] == "X" && scoretable[location - 3] == "X" && scoretable[location - 6] == "X")
							{
								findtot = false;
								int total1 = total + 30;
								int total2 = total1 + 10 + 10 +f1;
								int total3 = total2 + 10 + f1 + f2;
								total = total3 + f1 + f2;
								tot = to_string(total);
								scoretable[location + 2] = to_string(total3);
								scoretable[location - 1] = to_string(total2);
								scoretable[location - 4] = to_string(total1);
							}
						}
					}
					//calculate the total
					if(findtot == true)
					{
					total = score(total, f1, f2, f3); 
					tot = to_string(total); 
					}
					//add values to the vector
					scoretable.push_back(frame1);
					scoretable.push_back(frame2);
					if(lastframe == true)
					{
						scoretable.push_back(frame3);
					}
					scoretable.push_back(tot);
					//add the total to the vector
					printScore(scoretable, playername);
					//print the scoretable using function
				
					if(scoretable.size() >5)
					//test to see whether they scored 3 gutter balls in a row
					{
						if(scoretable[scoretable.size()-2]=="G" && scoretable[scoretable.size()-3]=="G" && scoretable[scoretable.size()-5]=="G")
						{
							gutteraward = true;
						}
						else if(scoretable[scoretable.size()-3]=="G" && scoretable[scoretable.size()-5]=="G" && scoretable[scoretable.size()-6]=="G")
						{
							gutteraward = true;
						}
					}
				}	
			}
			if(input == 2)
			{
				ifstream in_file;
				string filename;
				string tot;
				string frame1;
				string frame2;
				string frame3;
				int framecount = 0;
				//declare variables
	
				cin.ignore(1);
				cout << "Enter a file name to be read: ";
				getline(cin, filename);
				cout << "Receiving input from the file " << filename << "..." << endl;
				in_file.open(filename);
				//this is for opening the file to be read
				while(in_file >> frame1)
				{	
					string tot;
					int f1 = 0;
					int f2 = 0;
					int f3 = 0;
					//declare variables
							
					bool do2 = true;
					bool do3 = true;
					bool findtot = true;
					bool validframe = false;
					bool openframe = false;
					bool doublestrike = false;
					bool triplestrike = false;
					bool doublespare = false;
					bool strikespare = false;
					bool sparestrike = false;
					bool lastframe = false;
					//declare all boolean values
				
					if(framecount == 9)
					// check to see if the game is on the last frame
					{
						lastframe = true;
					}
					do
					{
					//loop while the answers are invalid
						validframe = false;
						openframe = false;
						cout << "Roll 1 of frame " << framecount + 1 << ": " << frame1 << endl;
						//input score for frame 1
						if(frame1 == "1" || frame1 == "2" || frame1 == "3" || frame1 == "4" || frame1 == "5" || frame1 == "6" || frame1 == "7" || frame1 == "8" || frame1 == "9" || frame1 == "G" || frame1 == "F" || frame1 == "X")
						//check validity
						{
							validframe = true;
						}
						else
						{
						cout << "Invalid score input, try again." << endl;
						}
					}while(validframe == false);

						if(lastframe == true)
						//these are only for the final frame of the game
						{
							do2 = true;
							if(frame1 == "X")
							{
								totstrikecount++;
								f1 = 10;
								do3 = true;
							}
							else if(frame1 == "G")
							{
								f1 = 0;
								do3 = false;
								frame3 = "-";
							}
							else
							{
								f1 = atoi(frame1.c_str());
								do3 = false;
								frame3 = "-";
							}
						}
						else if(lastframe == false)
						{
							if(frame1 =="G")
							{
								do2 = true;
								findtot = true;
								f1 = 0;
							}
							else if(frame1 == "F")
							{
								do2 = true;
								findtot = true;
								f1 = 0;
							}
							else if(frame1 =="X")
							{
								do2 = false;
								findtot = false;
								openframe = false;
								frame2 = "-";
								tot = "#";
								totstrikecount++;
								if(scoretable.size() > 2)
								{
									if(scoretable[scoretable.size() - 3] == "X")
									{
										cout << scoretable[scoretable.size() - 3];
										rowstrikecount++;
										if(rowstrikecount >= 2)
										{
											strikeaward = true;
										}
									}
									else
									{
										rowstrikecount = 0;
									}
								}
							}
							else
							{
								f1 = atoi(frame1.c_str());
								do2 = true;
							}
						}
						if(do2 ==true)
						{
							do
							{
							//do this loop as long as input is invalid
							validframe = false;
							in_file >> frame2;
							cout << "Roll 2 of frame " << framecount + 1 << ": " << frame2 << endl;
							
							if(frame2 == "1" || frame2 == "2" || frame2 == "3" || frame2 == "4" || frame2 == "5" || frame2 == "6" || frame2 == "7" || frame2 == "8" || frame2 == "9" || frame2 == "G" || frame2 == "F" || frame2 == "X" || frame2 == "/")
							{
								validframe = true;
							}
							else
							{
								cout << "Invalid score input, try again." << endl;
								validframe = false;
							}

							if (lastframe == true)
							//these are only for the final frame of the game
							{
								if(frame2 == "X")
								{
									f2 = 10;
									totstrikecount++;
									do3 = true;
								}
								//if spare
								else if(frame2 == "/")
								{
									f1 = 0;
									f2 = 10;
									do3 = true;
								}
								//if gutter ball
								else if(frame2 == "G")
								{
									f2 = 0;
								}
								//if foul
								else if(frame2 == "F")
								{
									f2 = 0;
								}
								else
								{
									f2 = atoi(frame2.c_str());
								}
								if(do3 ==true)
								{
									//these only apply for the final frame
									in_file >> frame3;
									cout << "Roll 3 of frame " << framecount + 1 << ": " << frame3 << endl;
									
									if(frame3 == "X")
									{
										f3 = 10;
										totstrikecount++;
									}
									//if spare
									else if(frame3 == "/")
									{
										f3 = 10;
										f2 = 0;
									}
									//if gutterball
									else if(frame3 == "G")
									{
										f3 = 0;
									}
									//if foul
									else if(frame3 == "F")
									{
										f3 = 0;
									}
									else
									{
										f3 = atoi(frame3.c_str()); 
										//converts string to int
									}
								}
							}
							else if(lastframe == false)
							{
								//if spare
								if(frame2=="/")
								{
									findtot = false;
									openframe = false;
									tot = "#";
									totsparecount++;
								}
								//if gutter ball
								else if(frame2 == "G")
								{
									findtot = true;
									f2 = 0;
									openframe = true;
								}
								//if foul
								else if(frame2 == "F")
								{
									findtot = true;
									f2 = 0;
									openframe = true;
								}
								else
								//converts string to an int
								{
									f2 = atoi(frame2.c_str());
								}
								//determines if openframe
								if(f1>=0 && f1 <10 && f2 >= 0 && f2 < 10)
								{
									openframe = true;
								}
									
								//this is to validate that the sum of the two rolls is not larger than 9
								if(do2 = true && f1+f2+f3 > 9 && frame2 != "/" && frame2!= "G" && frame2!= "F")
								{
									validframe = false;
									cout << "Invalid score inputs, the sum of the two rolls must be from 0 to 9 pins, try again." << endl;
								}
							}
							
						}while(validframe == false);
					}
					if(scoretable.size() > 2)
					{
						//these statements determine 2 strikes in a row or 2 spares in a row and set booleans to true
						int location = scoretable.size() - 3;
						int sparelocation = scoretable.size() - 2;
						if(scoretable[location] == "X" && frame1 == "X")
						{
							doublestrike = true;
						}
						else if(scoretable[sparelocation] == "/" && frame2 =="/")
						{
							doublespare = true;
						}
						else if(scoretable[sparelocation] =="/" && frame1 =="X")
						{
							sparestrike = true;
						}
						else if(scoretable[location] =="X" && frame2 == "/")
						{
							strikespare = true;
						}
						if(scoretable.size()>5)
						{
							//if there are 2 or 3 strikes in a row then set the booleans to true
							if(scoretable[location] == "X" && scoretable[location - 3] =="X")
							{
								doublestrike = true;
							}
							if(scoretable[location - 3] =="X" && scoretable[location] == "X" && frame1 == "X")
							{
								triplestrike = true;
							}
						}
						if(scoretable.size() >8)
						{
							//if there are three strikes in a row, then set booleans to true
							if(scoretable[location] == "X" && scoretable[location - 3] == "X" && scoretable[location - 6] == "X")
							{
								doublestrike = true;
								triplestrike = true;
							}
						}

						//These if statements solve for multiple occurences of strikes or spares in a row
						if(scoretable[location] == "X" && strikespare == true)
						{
							findtot = false;
							int striketotal = total + 20;
							total = striketotal;
							scoretable[location + 2] = to_string(striketotal);
						}
						//solve for a single strike
						else if( scoretable[location] == "X" && openframe == true && doublestrike == false && triplestrike == false)
						{
							findtot = false;
							total = total + 10 + (f1*2) + (f2*2);
							tot = to_string(total);
							int updatescore = total - f1 - f2;
							scoretable[location + 2] = to_string(updatescore);
						}
						//solve for a single spare
						if(scoretable[location + 1] == "/"  && doublespare == false)
						{
							findtot = false;
							int spare1total = total + 10 + f1;
							total = spare1total + f1 + f2;
							tot = to_string(total);
							scoretable[sparelocation +1] = to_string(spare1total);
						}
						//solves when a spare and strike occur right after eachother
						if(scoretable[sparelocation] == "/" && doublespare == true)
						{
							findtot = false;
							int spare1total = total + 10 + f1;
							total = spare1total;
							scoretable[sparelocation +1] = to_string(spare1total);
						}
						//for when a spare and strike occur right after eachother
						if(scoretable[sparelocation] == "/" && sparestrike == true)
						{
							findtot = false;
							int sparetotal = total + 20;
							total = sparetotal;
							scoretable[sparelocation + 1] = to_string(sparetotal);
						}
						//in order to have 2 strikes in a row, the player has to complete at least 2 frames
						if(scoretable.size() > 5)
						{
							if(scoretable[location] == "X" && scoretable[location - 3] =="X" && openframe == true && triplestrike == false)
							{
								findtot = false;
								int total1 = total + 10 + 10 +f1;
								int total2 = total1 + 10 + f1 + f2;
								total = total2 + f1 + f2;
								tot = to_string(total);
								scoretable[location + 2] = to_string(total2);
								scoretable[location - 1] = to_string(total1);
							}
						}
						//in order to have 3 strikes in a row, the person has to at least have completed 3 frames
						if(scoretable.size() > 8)
						{
							if(frame1 =="X" && scoretable[location] == "X" && scoretable[location - 3] == "X" && scoretable[location - 6] == "X")
							{
								//these if statements solve for the last frame of the game, if there are strikes
								if(lastframe == true)
								{
									//calculate score for a double strike
									if(frame1 == "X" && frame2 == "X")
									{
										findtot = true;
										int total1 = total + 30;
										int total2 = total1 + 30;
										int total3 = total2 + 30;
										total = total3;
										scoretable[location + 2] = to_string(total3);
										scoretable[location - 1] = to_string(total2);
										scoretable[location - 4] = to_string(total1);
									}
									else if(frame1 == "X")
									//calculate score for a single strike
									{
										findtot = true;
										int total1 = total + 30;
										int total2 = total1 + 20 + f1;
										scoretable[location - 1] = to_string(total2);
										scoretable[location - 4] = to_string(total1);
									}
								}
								else if(lastframe ==false)
								//only for final frame
								{
									int total1 = total + 30;
									total = total1;
									scoretable[location - 4] = to_string(total1);
								}
							}
							//this function is for when there are 3 strikes in a row
							else if(scoretable[location] == "X" && scoretable[location - 3] == "X" && scoretable[location - 6] == "X")
							{
								findtot = false;
								int total1 = total + 30;
								int total2 = total1 + 10 + 10 +f1;
								int total3 = total2 + 10 + f1 + f2;
								total = total3 + f1 + f2;
								tot = to_string(total);
								scoretable[location + 2] = to_string(total3);
								scoretable[location - 1] = to_string(total2);
								scoretable[location - 4] = to_string(total1);
							}
						}
					}
					//calculate the total
					if(findtot == true)
					{
					total = score(total, f1, f2, f3); 
					tot = to_string(total); 
					}
					//add values to the vector
					scoretable.push_back(frame1);
					scoretable.push_back(frame2);
					if(lastframe == true)
					{
						scoretable.push_back(frame3);
					}
					scoretable.push_back(tot);
					//add the total to the vector
					printScore(scoretable, playername);
					//print the scoretable using function
				
					if(scoretable.size() >5)
					//test to see whether they scored 3 gutter balls in a row
					{
						if(scoretable[scoretable.size()-2]=="G" && scoretable[scoretable.size()-3]=="G" && scoretable[scoretable.size()-5]=="G")
						{
							gutteraward = true;
						}
						else if(scoretable[scoretable.size()-3]=="G" && scoretable[scoretable.size()-5]=="G" && scoretable[scoretable.size()-6]=="G")
						{
							gutteraward = true;
						}
					}
				framecount++;
				}
			}
			if(input == 3)
			{
				cout << "Sorry, this feature is currently under construction" << endl;
			}
			//determine if any awards should be received
			if(total > 200)
			{
				twoclub = true;
			}
			if(total > 299)
			{
				perfectgame = true;
			}
			gametotals.push_back(total);
			}
			//print out the statistics of the series
			cout << "STATISTICS/AWARDS:" << endl;
			for(int icount = 0; icount<gametotals.size(); icount++)
			{
				cout << "Score for game " << icount + 1 << ": " << gametotals[icount] << endl;
			}
			pointsaverage = gamesaverage(gametotals);
			cout << "Average score for " << gametotals.size() << " games: " << pointsaverage << endl;
			cout << "Total number of strikes: " << totstrikecount << endl;
			cout << "Total number of spares: " << totsparecount << endl;
			awards(strikeaward, gutteraward, twoclub, perfectgame);
			cout << "\nWould you like to play another series(Y=Yes, N=No)? ";
			cin >> keepplaying;
			cout << endl;
			cin.ignore(1);
		}while(keepplaying == "Y" || keepplaying == "y");
    system("pause");
    return 0;
}

#endif