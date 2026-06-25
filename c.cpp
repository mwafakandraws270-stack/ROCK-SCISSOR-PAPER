 #include <cstdlib>
#include<iostream>
#include <limits>
#include <memory>
#include <stdlib.h>
#include<string>
#include<cmath>
#include<windows.h>
using namespace std;

int readnumber ( string massege )
{
    int num =0;
    do  
    {
        cout<<massege<<endl;
        cin>>num;
    }
    while ( num != 1 && num != 2 && num != 3 );
    return num-1 ;
}

int randomnumbers ( int from , int to )
{
    int random = rand() % ( to - from + 1 ) + from ;
    return random ;
}

int askforrounds ()
{
    int rounds=0;
    cout<<"How many round do you want to play 1 -------> 10 :"<<endl;
    cin>>rounds;
    return rounds;
}

string computerchoos ( string arry[3] )
{
    int randomsum = randomnumbers(0, 2);
    return arry[randomsum];
}

string playerchoos ( string arry[3] , int num )
{
    return arry[num];
}

void compare ( int &loses , int &wins , int &equalization , string arry[3] , int num )
{
    string computer = computerchoos(arry);
    cout<<"The computer choos : "<<computer <<endl;
    switch ( true  ) 
    {
        case 1 :
        {
            if  ( playerchoos(arry, num ) == computer )
            {
                cout<<endl;
            cout<<"Thats equal "<<playerchoos(arry, num )<<" for "<<computer<<endl;
            equalization++;
            break;
            }
        }
        case 2 :
        {
            if (( playerchoos(arry, num) !=computer ))
            {
                if ( playerchoos(arry, num) == "paper" && computer == "rock")
                {
                    system("color 2");
                    cout<<"congratiolations "<<endl;                   
                    wins++;
                }
                else if ( playerchoos(arry, num) == "rock" &&computer == "paper" )
                {
                    _beep(2000, 200);
                    system("color 7");
                    cout<<"Sorry for ypur lost "<<endl;
                    loses++;
                }
                else if ( playerchoos(arry, num) == "paper" && computer == "scissor")
                {
                    _beep(2000, 200);
                    cout<<"Sorry for your lost "<<endl;
                    system("color 7");
                    loses++;
                }
                else if ( playerchoos(arry, num) == "scissor" && computer == "paper" )
                {
                    cout<<"congratiulatios"<<endl;
                    system("color 2");
                    wins++;
                }
                else if ( playerchoos(arry, num) == "rock" &&computer == "scissor")
                {
                    system("color 2");
                    cout<<"congratulations"<<endl;
                    wins++;
                }
                else if ( playerchoos(arry, num) == "scissor" && computer == "rock" )
                {
                    _beep(2000, 200);
                    system("color 7");
                    cout<<"Sorry for your lost "<<endl;
                    loses++;
                }
            }
            break;
        }
    }
}
// do the as for print result 
void roundresult ( int rounds, int &loses, int& win , int& equalization , string arr[3] )
{
    
    for ( int i=0 ; i < rounds ; i++ )
    {
        int num =0;
        num = readnumber("Enter [1] paper [2] rscissor [3] rock : ");
        cout<<"The player choos : "<<playerchoos(arr, num)<<endl;
        compare(loses, win, equalization, arr, num);
        cout<<"---- Round ["<<i+1<<"] results ----"<<endl;
        cout<<"The wins "<<win<<endl;
        cout<<"The loses : "<<loses<<endl;
        cout<<"The equilaizations are : "<<equalization<<endl;
    }
}

int compareresults ( int loses , int wins , int equalization )
{
    if ( loses > wins )
    {
        return 1;
    }
    else if ( wins > loses )
    {
        return 2;
    }
    return 3;
}
 void printresult ( int &loses , int &wins , int &equalization , int rounds)
{
    // i call the askforround and put in int round without s and put it here 
        if ( compareresults(loses, wins , equalization ) == 1 )
    {
        cout<<"Hard luck try next time" <<endl;
    }
        else if ( compareresults(loses, wins , equalization ) == 2 )
    {
        cout<<"Well played you won this game that was "<<rounds<<" rounds"<<endl;
    }
    cout<<"The final results are :"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"The wins are : "<<wins<<endl;
    cout<<"The loses are : "<<loses<<endl;
    cout<<"The equaizations are : "<<equalization<<endl;
}

int palyagain ( int num )
{
    
    if ( num == 1 )
    {
        return 4;
    }
    return 5;
}
bool reseteverything ( int& loses , int &wins , int &equalization , int num )
{
    int play = palyagain(num);
    if ( play == 4 )
    {
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
    

    loses =0;
    wins=0;
    equalization=0;

    return true;
    }
    else  if ( palyagain(num) == 5 )
    {
        cout<<"End of the game "<<endl;
        return false;
    }

}

int main()
{
    srand((unsigned)time(NULL));
    string arry[3] = { "paper" , "scissor" , "rock"};
    int wins=0;
    int loses=0;
    int equalization=0;

    // i call the function ( print result ) then the function play again i put int again = readnumber then put it in play again 
   for ( int i=0 ; i < 10; i++ )
   {
    int round = askforrounds();
    roundresult(round, loses, wins, equalization,  arry);
    printresult(loses, wins, equalization, round);
    int readagain = readnumber("Enter 2 if you want to play again and 3 if you dont : ");
    if ( reseteverything(loses, wins, equalization, readagain) != true )
    {
        break;
    }

   }
}
