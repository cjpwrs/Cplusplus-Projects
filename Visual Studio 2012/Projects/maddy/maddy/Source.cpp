#ifndef __PRINTSCORE_H
#define __PRINTSCORE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

void printScore(vector<string> scores, string playerName);

void awards(int strikes, int finalscore, int gutterball)
{
    if(strikes>=3)
    {
        cout<<"You won the \"Turkey\" award!"<<endl;
    }
    if (finalscore>200)
    {
        cout<<"You won the \"200 Club\" award!"<<endl;
    }
    if (finalscore==300)
    {
        cout<<"You won the \"Perfect Game\" award!"<<endl;
    }
    if (gutterball>=3)
    {
        cout<<"You won the \"Keep Your Day Job\" award!"<<endl;
    }
}

int main()
{
    vector<string>scoretable;
    string playername;
    cout<<"Please enter player's name:"<<endl;
    getline (cin, playername);
    
    int num_frames;
    cout<<"How many frames would you like to play?"<<endl;
    bool exist=false;
    while (exist==false)
    {
        cin>>num_frames;
    
        int num_games=num_frames/10;
        if(num_frames<10)
        {
            cout<<"Number of frames must be at least 10"<<endl;
        }
        else
        {
            cout<<playername<<" will play "<<num_games<<" games"<<endl;
            exist=true;
        }
    }
    
    int answer=0;
    cout<<"How will you provide input (1=USER, 2=FILE, 3=AUTOGEN):"<<endl;
    cin>>answer;
    
    if(answer==1)
    {
        int total = 0;
        for(int framecount = 0; framecount < 10; framecount++)
        {
            string frame1;
            string frame2;
            string tot;
            int f1 = 0;
            int f2 = 0;
            bool do2 = true;
            bool goodanswer = false;
            bool findtot = true;
            bool validframe = true;
            bool openframe = false;
            bool doublestrike = false;
            
            do
            {
                validframe = true;
                openframe = false;
                cout << "Roll 1 of frame " << framecount + 1 << ": ";
                cin >> frame1;
                if(frame1 =="X")
                {
                    goodanswer = true;
                    do2 = false;
                    findtot = false;
                    openframe = false;
                    frame2 = "-";
                    tot = "#";
                }
                else
                {
                    f1 = atoi(frame1.c_str());
                }
                
                
                if(do2 ==true)
                {
                    cout << "Roll 2 of frame " << framecount + 1 << ": ";
                    cin >> frame2;
                    if(frame2=="/")
                    {
                        findtot = false;
                        tot = "#";
                    }
                    else
                    {
						f2 = atoi(frame2.c_str());
                    }
                }
                if(f1>=0 && f1 <10 && f2 >= 0 && f2 < 10)
                {
                    openframe = true;
                }
                if(do2 == true && f1 + f2 > 10 && frame2 != "/" && frame2!= "G" && frame2!= "F")
                {
                    cout << "Invalid score inputs, try again." << endl;
                    validframe = false;
                }
            }while(validframe == false);
            if(scoretable.size() > 2)
            {
                cout << scoretable[scoretable.size() - 3];
                int location = scoretable.size() - 3;
                
                
                if( scoretable[location] == "X" && openframe == true && doublestrike == false)
                {
                    findtot = false;
                    total = total + 10 + (f1*2) + (f2*2);
                    tot = to_string(total);
                    int updatescore = total - f1 - f2;
                    scoretable[location + 2] = to_string(updatescore);
                    
                }
                if(scoretable[location + 1] == "/" && openframe == true)
                {
                    findtot = false;
                    total = total + 10 + (f1*2) + f2;
                    tot = to_string(total);
                    int updatescore = total - f1 - f2;
                    scoretable[location +2] = to_string(updatescore);
                }
               
                
            }
            if(findtot == true)
            {
				total = total + f1 + f2; 
				tot = to_string(total); 
                
            }
            
            scoretable.push_back(frame1);
            scoretable.push_back(frame2);
            scoretable.push_back(tot);
            printScore(scoretable, playername);
            
        
    }

    
}
if (answer==2)
{
    
    
        ifstream infile;
        string inputfilename;
        string frame1;
    
        cin.ignore(1);
        cout << "Enter the file name ";
        getline (cin, inputfilename);
        
        infile.open(inputfilename);
        int total = 0;
        int framecount = 0;
        while (infile>>frame1)
        {
            
            //for(int framecount = 0; framecount < 10; framecount++)
            //{
                //string frame1;
                string frame2;
                string frame3;
                string tot;
                
                int f1 = 0;
                int f2 = 0;
                int f3 =0;
                bool do2 = true;
                bool goodanswer = false;
                bool findtot = true;
                bool validframe = true;
                bool openframe = false;
                bool doublestrike = false;
                
                do
                {
                    validframe = true;
                    openframe = false;
                    //infile >> frame1;
                    cout << "Roll 1 of frame " << framecount + 1 << ": "<<frame1<<endl;
                    
                    if(frame1 =="X" && framecount<9)
                    {
                        goodanswer = true;
                        do2 = false;
                        findtot = false;
                        openframe = false;
                        frame2 = "-";
                        tot = "#";
                    }
                    else if(frame1=="X")
                    {
                        do2=true;
                        f1=10;
                        
                    }
                    else
                    {
                        f1 = atoi(frame1.c_str());
                    }
                    
                    
                    if(do2 ==true)
                    {
                        infile>> frame2;
                        cout << "Roll 2 of frame " << framecount + 1 << ": "<<frame2<<endl;
                        
                        if(frame2=="/")
                        {
                            findtot = false;
                            tot = "#";
                        }
                        else
                        {
                            f2 = atoi(frame2.c_str());
                        }
                    }
                    if (framecount==9)
                    {
                        infile>> frame3;
                        cout<<"Roll 3 of frame "<<framecount +1<<":"<<frame3<<endl;
                        f3 = atoi(frame3.c_str());
                    }
                    if(f1>=0 && f1 <10 && f2 >= 0 && f2 < 10)
                    {
                        openframe = true;
                    }
                    if(do2 == true && f1 + f2 > 10 && frame2 != "/" && frame2!= "G" && frame2!= "F")
                    {
                        cout << "Invalid score inputs, try again." << endl;
                        validframe = false;
                    }
                }while(validframe == false);
                if(scoretable.size() > 2)
                {
                    cout << scoretable[scoretable.size() - 3];
                    int location = scoretable.size() - 3;
                    
                    
                    if( scoretable[location] == "X" && openframe == true && doublestrike == false)
                    {
                        findtot = false;
                        total = total + 10 + (f1*2) + (f2*2);
                        tot = to_string(total);
                        int updatescore = total - f1 - f2;
                        scoretable[location + 2] = to_string(updatescore);
                        
                    }
                    if(scoretable[location + 1] == "/" && openframe == true)
                    {
                        findtot = false;
                        total = total + 10 + (f1*2) + f2;
                        tot = to_string(total);
                        int updatescore = total - f1 - f2;
                        scoretable[location +2] = to_string(updatescore);
                    }
                    
                    
                }
                if(findtot == true)
                {
                    total = total + f1 + f2+f3;
                    tot = to_string(total); 
                    
                }
                
                scoretable.push_back(frame1);
                scoretable.push_back(frame2);
                if (framecount==9)
                {
                    scoretable.push_back(frame3);
                
                }
                scoretable.push_back(tot);
                printScore(scoretable, playername);
            
            framecount++;
                
            //}
        }

    
           
        
        infile.close();
    
}

    
   
    
    
    

    
    system ("pause");
    return 0;
}

#endif