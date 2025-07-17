#include <iostream>
#include <windows.h>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

void Print(vector<string>PrintDeck)
{
    string str=*PrintDeck.begin();

    string symbol;
    if(str[1]=='S') // ♠
    {
        symbol=u8"♠";
    }
    else if(str[1]=='D') // ♦
    {
        symbol=u8"♦";
    }
    else if(str[1]=='C') // ♣
    {
        symbol=u8"♣";
    }
    else if(str[1]=='H') // ♥
    {
        symbol=u8"♥";
    }
    else
    {
        cout<<"  ┌─────────────┐"<<endl;
        cout<<"  │ ERROR       │"<<endl;
        cout<<"  │             │"<<endl;
        cout<<"  │             │"<<endl;
        cout<<"  │      ☠️     │"<<endl;
        cout<<"  │             │"<<endl;
        cout<<"  │             │"<<endl;
        cout<<"  │       ERROR │"<<endl;
        cout<<"  └─────────────┘"<<endl;
    }

    char digit=str[0];
    cout<<"  ┌─────────────┐"<<endl;
    cout<<"  │ "<<digit<<"           │"<<endl;
    cout<<"  │             │"<<endl;
    cout<<"  │             │"<<endl;
    cout<<"  │      "<<symbol<<"      │"<<endl;
    cout<<"  │             │"<<endl;
    cout<<"  │             │"<<endl;
    cout<<"  │           "<<digit<<" │"<<endl;
    cout<<"  └─────────────┘"<<endl;
}

int CardValue(string str)
{
    int tmp;
    if(str[0]=='2')
        tmp=2;
    else if(str[0]=='3')
        tmp=3;
    else if(str[0]=='4')
        tmp=4;
    else if(str[0]=='5')
        tmp=5;
    else if(str[0]=='6')
        tmp=6;
    else if(str[0]=='7')
        tmp=7;
    else if(str[0]=='8')
        tmp=8;
    else if(str[0]=='9')
        tmp=9;
    else if(str[0]=='1')
        tmp=10;
    else if(str[0]=='J')
        tmp=11;
    else if(str[0]=='Q')
        tmp=12;
    else if(str[0]=='K')
        tmp=13;
    else
        tmp=14;
    return tmp;
}

void Game(vector<string>&PlayerDeck,vector<string>&ComputerDeck) // This code is retarded but I won't bother to update this shit
{
    int tmp_player,tmp_computer;
    string str_player=*PlayerDeck.begin(),str_computer=*ComputerDeck.begin();

    tmp_player=CardValue(str_player);
    tmp_computer=CardValue(str_computer);

    if(tmp_player>tmp_computer)
    {
        PlayerDeck.insert(PlayerDeck.end(),PlayerDeck.front());
        PlayerDeck.insert(PlayerDeck.end(),ComputerDeck.front());
        PlayerDeck.erase(PlayerDeck.begin());
        ComputerDeck.erase(ComputerDeck.begin());
    }
    else if(tmp_player<tmp_computer)
    {
        ComputerDeck.insert(ComputerDeck.end(),ComputerDeck.front());
        ComputerDeck.insert(ComputerDeck.end(),PlayerDeck.front());
        ComputerDeck.erase(ComputerDeck.begin());
        PlayerDeck.erase(PlayerDeck.begin());
    }
    else //WAR | both cards are the same
    {
        vector<string>war;

        war.insert(war.begin(),{PlayerDeck.front(),ComputerDeck.front()});
        PlayerDeck.erase(PlayerDeck.begin());
        ComputerDeck.erase(ComputerDeck.begin());

        while(true)
        {
            cout<<"<<<<< [ WAR ] >>>>>"<<endl;
            system("pause");

            war.insert(war.begin(),{PlayerDeck.front(),ComputerDeck.front()});
            cout<<"<<<<< [ PLAYER'S CARD ] >>>>>"<<endl;
            Print(PlayerDeck);
            cout<<"<<<<< [ COMPUTER'S CARD ] >>>>>"<<endl;
            Print(ComputerDeck);
            if(!PlayerDeck.empty() && !ComputerDeck.empty())
            {
                ComputerDeck.erase(ComputerDeck.begin());
                PlayerDeck.erase(PlayerDeck.begin());
            }
            else
                return;

            str_player=*war.begin();
            str_computer=*(war.begin()+1);

            tmp_player=CardValue(str_player);
            tmp_computer=CardValue(str_computer);

            if(tmp_player>tmp_computer)
            {
                PlayerDeck.insert(PlayerDeck.end(),war.begin(),war.end());
                break;
            }
            if(tmp_player<tmp_computer)
            {
                ComputerDeck.insert(ComputerDeck.end(),war.begin(),war.end());
                break;
            }
        }
    }
}

void Deal(vector<string>Deck,vector<string>&PlayerDeck,vector<string>&ComputerDeck)
{
    for(int i=0;i<52;i++)
    {
        if(i%2==0 || i==0) //Player
        {
            PlayerDeck.push_back(Deck[0]);
            Deck.erase(Deck.begin());
        }
        else //Computer
        {
            ComputerDeck.push_back(Deck[0]);
            Deck.erase(Deck.begin());
        }
    }
}

void ShuffleAnimation()
{
   const int sleep=1;

            cout<<"  ┌─────────────┐"<<endl;
            cout<<"  │ 2           │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │      ♦      │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │           2 │"<<endl;
            cout<<"  └─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐┐"<<endl;
            cout<<"  │ 2           ││"<<endl;
            cout<<"  │             ││"<<endl;
            cout<<"  │             ││"<<endl;
            cout<<"  │      ♦      ││"<<endl;
            cout<<"  │             ││"<<endl;
            cout<<"  │             ││"<<endl;
            cout<<"  │           2 ││"<<endl;
            cout<<"  └─────────────┘┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐─┐"<<endl;
            cout<<"  │ 2           │ │"<<endl;
            cout<<"  │             │ │"<<endl;
            cout<<"  │             │ │"<<endl;
            cout<<"  │      ♦      │ │"<<endl;
            cout<<"  │             │ │"<<endl;
            cout<<"  │             │ │"<<endl;
            cout<<"  │           2 │ │"<<endl;
            cout<<"  └─────────────┘─┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐──┐"<<endl;
            cout<<"  │ 2           │  │"<<endl;
            cout<<"  │             │  │"<<endl;
            cout<<"  │             │  │"<<endl;
            cout<<"  │      ♦      │  │"<<endl;
            cout<<"  │             │  │"<<endl;
            cout<<"  │             │  │"<<endl;
            cout<<"  │           2 │A │"<<endl;
            cout<<"  └─────────────┘──┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐───┐"<<endl;
            cout<<"  │ 2           │   │"<<endl;
            cout<<"  │             │   │"<<endl;
            cout<<"  │             │   │"<<endl;
            cout<<"  │      ♦      │   │"<<endl;
            cout<<"  │             │   │"<<endl;
            cout<<"  │             │   │"<<endl;
            cout<<"  │           2 │ A │"<<endl;
            cout<<"  └─────────────┘───┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐────┐"<<endl;
            cout<<"  │ 2           │    │"<<endl;
            cout<<"  │             │    │"<<endl;
            cout<<"  │             │    │"<<endl;
            cout<<"  │      ♦      │    │"<<endl;
            cout<<"  │             │    │"<<endl;
            cout<<"  │             │    │"<<endl;
            cout<<"  │           2 │  A │"<<endl;
            cout<<"  └─────────────┘────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐─────┐"<<endl;
            cout<<"  │ 2           │     │"<<endl;
            cout<<"  │             │     │"<<endl;
            cout<<"  │             │     │"<<endl;
            cout<<"  │      ♦      │     │"<<endl;
            cout<<"  │             │     │"<<endl;
            cout<<"  │             │     │"<<endl;
            cout<<"  │           2 │   A │"<<endl;
            cout<<"  └─────────────┘─────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐──────┐"<<endl;
            cout<<"  │ 2           │      │"<<endl;
            cout<<"  │             │      │"<<endl;
            cout<<"  │             │      │"<<endl;
            cout<<"  │      ♦      │      │"<<endl;
            cout<<"  │             │      │"<<endl;
            cout<<"  │             │      │"<<endl;
            cout<<"  │           2 │    A │"<<endl;
            cout<<"  └─────────────┘──────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐───────┐"<<endl;
            cout<<"  │ 2           │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │      ♦      │♠      │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │           2 │     A │"<<endl;
            cout<<"  └─────────────┘───────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐───────┐"<<endl;
            cout<<"  │ 2           │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │      ♦      │♠      │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │           2 │     A │"<<endl;
            cout<<"  └─────────────┘───────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐────────┐"<<endl;
            cout<<"  │ 2           │        │"<<endl;
            cout<<"  │             │        │"<<endl;
            cout<<"  │             │        │"<<endl;
            cout<<"  │      ♦      │ ♠      │"<<endl;
            cout<<"  │             │        │"<<endl;
            cout<<"  │             │        │"<<endl;
            cout<<"  │           2 │      A │"<<endl;
            cout<<"  └─────────────┘────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐─────────┐"<<endl;
            cout<<"  │ 2           │         │"<<endl;
            cout<<"  │             │         │"<<endl;
            cout<<"  │             │         │"<<endl;
            cout<<"  │      ♦      │  ♠      │"<<endl;
            cout<<"  │             │         │"<<endl;
            cout<<"  │             │         │"<<endl;
            cout<<"  │           2 │       A │"<<endl;
            cout<<"  └─────────────┘─────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐──────────┐"<<endl;
            cout<<"  │ 2           │          │"<<endl;
            cout<<"  │             │          │"<<endl;
            cout<<"  │             │          │"<<endl;
            cout<<"  │      ♦      │   ♠      │"<<endl;
            cout<<"  │             │          │"<<endl;
            cout<<"  │             │          │"<<endl;
            cout<<"  │           2 │        A │"<<endl;
            cout<<"  └─────────────┘──────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐───────────┐"<<endl;
            cout<<"  │ 2           │           │"<<endl;
            cout<<"  │             │           │"<<endl;
            cout<<"  │             │           │"<<endl;
            cout<<"  │      ♦      │    ♠      │"<<endl;
            cout<<"  │             │           │"<<endl;
            cout<<"  │             │           │"<<endl;
            cout<<"  │           2 │         A │"<<endl;
            cout<<"  └─────────────┘───────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐────────────┐"<<endl;
            cout<<"  │ 2           │A           │"<<endl;
            cout<<"  │             │            │"<<endl;
            cout<<"  │             │            │"<<endl;
            cout<<"  │      ♦      │     ♠      │"<<endl;
            cout<<"  │             │            │"<<endl;
            cout<<"  │             │            │"<<endl;
            cout<<"  │           2 │          A │"<<endl;
            cout<<"  └─────────────┘────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐─────────────┐"<<endl;
            cout<<"  │ 2           │ A           │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │      ♦      │      ♠      │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │           2 │           A │"<<endl;
            cout<<"  └─────────────┘─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐┌─────────────┐"<<endl;
            cout<<"  │ 2           ││ A           │"<<endl;
            cout<<"  │             ││             │"<<endl;
            cout<<"  │             ││             │"<<endl;
            cout<<"  │      ♦      ││      ♠      │"<<endl;
            cout<<"  │             ││             │"<<endl;
            cout<<"  │             ││             │"<<endl;
            cout<<"  │           2 ││           A │"<<endl;
            cout<<"  └─────────────┘└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┌─────────────┐"<<endl;
            cout<<"  │ 2           │ A           │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │      ♦      │      ♠      │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │           2 │           A │"<<endl;
            cout<<"  └─────────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌────────────┌─────────────┐"<<endl;
            cout<<"  │ 2          │ A           │"<<endl;
            cout<<"  │            │             │"<<endl;
            cout<<"  │            │             │"<<endl;
            cout<<"  │      ♦     │      ♠      │"<<endl;
            cout<<"  │            │             │"<<endl;
            cout<<"  │            │             │"<<endl;
            cout<<"  │           2│           A │"<<endl;
            cout<<"  └────────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌───────────┌─────────────┐"<<endl;
            cout<<"  │ 2         │ A           │"<<endl;
            cout<<"  │           │             │"<<endl;
            cout<<"  │           │             │"<<endl;
            cout<<"  │      ♦    │      ♠      │"<<endl;
            cout<<"  │           │             │"<<endl;
            cout<<"  │           │             │"<<endl;
            cout<<"  │           │           A │"<<endl;
            cout<<"  └───────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌──────────┌─────────────┐"<<endl;
            cout<<"  │ 2        │ A           │"<<endl;
            cout<<"  │          │             │"<<endl;
            cout<<"  │          │             │"<<endl;
            cout<<"  │      ♦   │      ♠      │"<<endl;
            cout<<"  │          │             │"<<endl;
            cout<<"  │          │             │"<<endl;
            cout<<"  │          │           A │"<<endl;
            cout<<"  └──────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────┌─────────────┐"<<endl;
            cout<<"  │ 2       │ A           │"<<endl;
            cout<<"  │         │             │"<<endl;
            cout<<"  │         │             │"<<endl;
            cout<<"  │      ♦  │      ♠      │"<<endl;
            cout<<"  │         │             │"<<endl;
            cout<<"  │         │             │"<<endl;
            cout<<"  │         │           A │"<<endl;
            cout<<"  └─────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌────────┌─────────────┐"<<endl;
            cout<<"  │ 2      │ A           │"<<endl;
            cout<<"  │        │             │"<<endl;
            cout<<"  │        │             │"<<endl;
            cout<<"  │      ♦ │      ♠      │"<<endl;
            cout<<"  │        │             │"<<endl;
            cout<<"  │        │             │"<<endl;
            cout<<"  │        │           A │"<<endl;
            cout<<"  └────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌───────┌─────────────┐"<<endl;
            cout<<"  │ 2     │ A           │"<<endl;
            cout<<"  │       │             │"<<endl;
            cout<<"  │       │             │"<<endl;
            cout<<"  │      ♦│      ♠      │"<<endl;
            cout<<"  │       │             │"<<endl;
            cout<<"  │       │             │"<<endl;
            cout<<"  │       │           A │"<<endl;
            cout<<"  └───────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌──────┌─────────────┐"<<endl;
            cout<<"  │ 2    │ A           │"<<endl;
            cout<<"  │      │             │"<<endl;
            cout<<"  │      │             │"<<endl;
            cout<<"  │      │      ♠      │"<<endl;
            cout<<"  │      │             │"<<endl;
            cout<<"  │      │             │"<<endl;
            cout<<"  │      │           A │"<<endl;
            cout<<"  └──────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────┌─────────────┐"<<endl;
            cout<<"  │ 2   │ A           │"<<endl;
            cout<<"  │     │             │"<<endl;
            cout<<"  │     │             │"<<endl;
            cout<<"  │     │      ♠      │"<<endl;
            cout<<"  │     │             │"<<endl;
            cout<<"  │     │             │"<<endl;
            cout<<"  │     │           A │"<<endl;
            cout<<"  └─────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌────┌─────────────┐"<<endl;
            cout<<"  │ 2  │ A           │"<<endl;
            cout<<"  │    │             │"<<endl;
            cout<<"  │    │             │"<<endl;
            cout<<"  │    │      ♠      │"<<endl;
            cout<<"  │    │             │"<<endl;
            cout<<"  │    │             │"<<endl;
            cout<<"  │    │           A │"<<endl;
            cout<<"  └────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌───┌─────────────┐"<<endl;
            cout<<"  │ 2 │ A           │"<<endl;
            cout<<"  │   │             │"<<endl;
            cout<<"  │   │             │"<<endl;
            cout<<"  │   │      ♠      │"<<endl;
            cout<<"  │   │             │"<<endl;
            cout<<"  │   │             │"<<endl;
            cout<<"  │   │           A │"<<endl;
            cout<<"  └───└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌──┌─────────────┐"<<endl;
            cout<<"  │ 2│ A           │"<<endl;
            cout<<"  │  │             │"<<endl;
            cout<<"  │  │             │"<<endl;
            cout<<"  │  │      ♠      │"<<endl;
            cout<<"  │  │             │"<<endl;
            cout<<"  │  │             │"<<endl;
            cout<<"  │  │           A │"<<endl;
            cout<<"  └──└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─┌─────────────┐"<<endl;
            cout<<"  │ │ A           │"<<endl;
            cout<<"  │ │             │"<<endl;
            cout<<"  │ │             │"<<endl;
            cout<<"  │ │      ♠      │"<<endl;
            cout<<"  │ │             │"<<endl;
            cout<<"  │ │             │"<<endl;
            cout<<"  │ │           A │"<<endl;
            cout<<"  └─└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌┌─────────────┐"<<endl;
            cout<<"  ││ A           │"<<endl;
            cout<<"  ││             │"<<endl;
            cout<<"  ││             │"<<endl;
            cout<<"  ││      ♠      │"<<endl;
            cout<<"  ││             │"<<endl;
            cout<<"  ││             │"<<endl;
            cout<<"  ││           A │"<<endl;
            cout<<"  └└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐"<<endl;
            cout<<"  │ A           │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │      ♠      │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │           A │"<<endl;
            cout<<"  └─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐┐"<<endl;
            cout<<"  │ A           ││"<<endl;
            cout<<"  │             ││"<<endl;
            cout<<"  │             ││"<<endl;
            cout<<"  │      ♠      ││"<<endl;
            cout<<"  │             ││"<<endl;
            cout<<"  │             ││"<<endl;
            cout<<"  │           A ││"<<endl;
            cout<<"  └─────────────┘┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐─┐"<<endl;
            cout<<"  │ A           │ │"<<endl;
            cout<<"  │             │ │"<<endl;
            cout<<"  │             │ │"<<endl;
            cout<<"  │      ♠      │ │"<<endl;
            cout<<"  │             │ │"<<endl;
            cout<<"  │             │ │"<<endl;
            cout<<"  │           A │ │"<<endl;
            cout<<"  └─────────────┘─┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐──┐"<<endl;
            cout<<"  │ A           │  │"<<endl;
            cout<<"  │             │  │"<<endl;
            cout<<"  │             │  │"<<endl;
            cout<<"  │      ♠      │  │"<<endl;
            cout<<"  │             │  │"<<endl;
            cout<<"  │             │  │"<<endl;
            cout<<"  │           A │7 │"<<endl;
            cout<<"  └─────────────┘──┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐───┐"<<endl;
            cout<<"  │ A           │   │"<<endl;
            cout<<"  │             │   │"<<endl;
            cout<<"  │             │   │"<<endl;
            cout<<"  │      ♠      │   │"<<endl;
            cout<<"  │             │   │"<<endl;
            cout<<"  │             │   │"<<endl;
            cout<<"  │           A │ 7 │"<<endl;
            cout<<"  └─────────────┘───┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐────┐"<<endl;
            cout<<"  │ A           │    │"<<endl;
            cout<<"  │             │    │"<<endl;
            cout<<"  │             │    │"<<endl;
            cout<<"  │      ♠      │    │"<<endl;
            cout<<"  │             │    │"<<endl;
            cout<<"  │             │    │"<<endl;
            cout<<"  │           A │  7 │"<<endl;
            cout<<"  └─────────────┘────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐─────┐"<<endl;
            cout<<"  │ A           │     │"<<endl;
            cout<<"  │             │     │"<<endl;
            cout<<"  │             │     │"<<endl;
            cout<<"  │      ♠      │     │"<<endl;
            cout<<"  │             │     │"<<endl;
            cout<<"  │             │     │"<<endl;
            cout<<"  │           A │   7 │"<<endl;
            cout<<"  └─────────────┘─────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐──────┐"<<endl;
            cout<<"  │ A           │      │"<<endl;
            cout<<"  │             │      │"<<endl;
            cout<<"  │             │      │"<<endl;
            cout<<"  │      ♠      │      │"<<endl;
            cout<<"  │             │      │"<<endl;
            cout<<"  │             │      │"<<endl;
            cout<<"  │           A │    7 │"<<endl;
            cout<<"  └─────────────┘──────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐───────┐"<<endl;
            cout<<"  │ A           │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │      ♠      │♠      │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │           A │     7 │"<<endl;
            cout<<"  └─────────────┘───────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐───────┐"<<endl;
            cout<<"  │ A           │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │      ♠      │♠      │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │             │       │"<<endl;
            cout<<"  │           A │     7 │"<<endl;
            cout<<"  └─────────────┘───────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐────────┐"<<endl;
            cout<<"  │ A           │        │"<<endl;
            cout<<"  │             │        │"<<endl;
            cout<<"  │             │        │"<<endl;
            cout<<"  │      ♠      │ ♠      │"<<endl;
            cout<<"  │             │        │"<<endl;
            cout<<"  │             │        │"<<endl;
            cout<<"  │           A │      7 │"<<endl;
            cout<<"  └─────────────┘────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐─────────┐"<<endl;
            cout<<"  │ A           │         │"<<endl;
            cout<<"  │             │         │"<<endl;
            cout<<"  │             │         │"<<endl;
            cout<<"  │      ♠      │  ♠      │"<<endl;
            cout<<"  │             │         │"<<endl;
            cout<<"  │             │         │"<<endl;
            cout<<"  │           A │       7 │"<<endl;
            cout<<"  └─────────────┘─────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐──────────┐"<<endl;
            cout<<"  │ A           │          │"<<endl;
            cout<<"  │             │          │"<<endl;
            cout<<"  │             │          │"<<endl;
            cout<<"  │      ♠      │   ♠      │"<<endl;
            cout<<"  │             │          │"<<endl;
            cout<<"  │             │          │"<<endl;
            cout<<"  │           A │        7 │"<<endl;
            cout<<"  └─────────────┘──────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐───────────┐"<<endl;
            cout<<"  │ A           │           │"<<endl;
            cout<<"  │             │           │"<<endl;
            cout<<"  │             │           │"<<endl;
            cout<<"  │      ♠      │    ♠      │"<<endl;
            cout<<"  │             │           │"<<endl;
            cout<<"  │             │           │"<<endl;
            cout<<"  │           A │         7 │"<<endl;
            cout<<"  └─────────────┘───────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐────────────┐"<<endl;
            cout<<"  │ A           │7           │"<<endl;
            cout<<"  │             │            │"<<endl;
            cout<<"  │             │            │"<<endl;
            cout<<"  │      ♠      │     ♠      │"<<endl;
            cout<<"  │             │            │"<<endl;
            cout<<"  │             │            │"<<endl;
            cout<<"  │           A │          7 │"<<endl;
            cout<<"  └─────────────┘────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐─────────────┐"<<endl;
            cout<<"  │ A           │ 7           │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │      ♠      │      ♠      │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │           2 │           7 │"<<endl;
            cout<<"  └─────────────┘─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐┌─────────────┐"<<endl;
            cout<<"  │ A           ││ 7           │"<<endl;
            cout<<"  │             ││             │"<<endl;
            cout<<"  │             ││             │"<<endl;
            cout<<"  │      ♠      ││      ♠      │"<<endl;
            cout<<"  │             ││             │"<<endl;
            cout<<"  │             ││             │"<<endl;
            cout<<"  │           A ││           7 │"<<endl;
            cout<<"  └─────────────┘└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┌─────────────┐"<<endl;
            cout<<"  │ A           │ 7           │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │      ♠      │      ♠      │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │             │             │"<<endl;
            cout<<"  │           A │           7 │"<<endl;
            cout<<"  └─────────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌────────────┌─────────────┐"<<endl;
            cout<<"  │ A          │ 7           │"<<endl;
            cout<<"  │            │             │"<<endl;
            cout<<"  │            │             │"<<endl;
            cout<<"  │      ♠     │      ♠      │"<<endl;
            cout<<"  │            │             │"<<endl;
            cout<<"  │            │             │"<<endl;
            cout<<"  │           A│           7 │"<<endl;
            cout<<"  └────────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌───────────┌─────────────┐"<<endl;
            cout<<"  │ A         │ 7           │"<<endl;
            cout<<"  │           │             │"<<endl;
            cout<<"  │           │             │"<<endl;
            cout<<"  │      ♠    │      ♠      │"<<endl;
            cout<<"  │           │             │"<<endl;
            cout<<"  │           │             │"<<endl;
            cout<<"  │           │           7 │"<<endl;
            cout<<"  └───────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌──────────┌─────────────┐"<<endl;
            cout<<"  │ A        │ 7           │"<<endl;
            cout<<"  │          │             │"<<endl;
            cout<<"  │          │             │"<<endl;
            cout<<"  │      ♠   │      ♠      │"<<endl;
            cout<<"  │          │             │"<<endl;
            cout<<"  │          │             │"<<endl;
            cout<<"  │          │           7 │"<<endl;
            cout<<"  └──────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────┌─────────────┐"<<endl;
            cout<<"  │ A       │ 7           │"<<endl;
            cout<<"  │         │             │"<<endl;
            cout<<"  │         │             │"<<endl;
            cout<<"  │      ♠  │      ♠      │"<<endl;
            cout<<"  │         │             │"<<endl;
            cout<<"  │         │             │"<<endl;
            cout<<"  │         │           7 │"<<endl;
            cout<<"  └─────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌────────┌─────────────┐"<<endl;
            cout<<"  │ A      │ 7           │"<<endl;
            cout<<"  │        │             │"<<endl;
            cout<<"  │        │             │"<<endl;
            cout<<"  │      ♠ │      ♠      │"<<endl;
            cout<<"  │        │             │"<<endl;
            cout<<"  │        │             │"<<endl;
            cout<<"  │        │           7 │"<<endl;
            cout<<"  └────────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌───────┌─────────────┐"<<endl;
            cout<<"  │ A     │ 7           │"<<endl;
            cout<<"  │       │             │"<<endl;
            cout<<"  │       │             │"<<endl;
            cout<<"  │      ♠│      ♠      │"<<endl;
            cout<<"  │       │             │"<<endl;
            cout<<"  │       │             │"<<endl;
            cout<<"  │       │           7 │"<<endl;
            cout<<"  └───────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌──────┌─────────────┐"<<endl;
            cout<<"  │ A    │ 7           │"<<endl;
            cout<<"  │      │             │"<<endl;
            cout<<"  │      │             │"<<endl;
            cout<<"  │      │      ♠      │"<<endl;
            cout<<"  │      │             │"<<endl;
            cout<<"  │      │             │"<<endl;
            cout<<"  │      │           7 │"<<endl;
            cout<<"  └──────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────┌─────────────┐"<<endl;
            cout<<"  │ A   │ 7           │"<<endl;
            cout<<"  │     │             │"<<endl;
            cout<<"  │     │             │"<<endl;
            cout<<"  │     │      ♠      │"<<endl;
            cout<<"  │     │             │"<<endl;
            cout<<"  │     │             │"<<endl;
            cout<<"  │     │           7 │"<<endl;
            cout<<"  └─────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌────┌─────────────┐"<<endl;
            cout<<"  │ A  │ 7           │"<<endl;
            cout<<"  │    │             │"<<endl;
            cout<<"  │    │             │"<<endl;
            cout<<"  │    │      ♠      │"<<endl;
            cout<<"  │    │             │"<<endl;
            cout<<"  │    │             │"<<endl;
            cout<<"  │    │           7 │"<<endl;
            cout<<"  └────└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌───┌─────────────┐"<<endl;
            cout<<"  │ A │ 7           │"<<endl;
            cout<<"  │   │             │"<<endl;
            cout<<"  │   │             │"<<endl;
            cout<<"  │   │      ♠      │"<<endl;
            cout<<"  │   │             │"<<endl;
            cout<<"  │   │             │"<<endl;
            cout<<"  │   │           7 │"<<endl;
            cout<<"  └───└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌──┌─────────────┐"<<endl;
            cout<<"  │ A│ 7           │"<<endl;
            cout<<"  │  │             │"<<endl;
            cout<<"  │  │             │"<<endl;
            cout<<"  │  │      ♠      │"<<endl;
            cout<<"  │  │             │"<<endl;
            cout<<"  │  │             │"<<endl;
            cout<<"  │  │           7 │"<<endl;
            cout<<"  └──└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─┌─────────────┐"<<endl;
            cout<<"  │ │ 7           │"<<endl;
            cout<<"  │ │             │"<<endl;
            cout<<"  │ │             │"<<endl;
            cout<<"  │ │      ♠      │"<<endl;
            cout<<"  │ │             │"<<endl;
            cout<<"  │ │             │"<<endl;
            cout<<"  │ │           7 │"<<endl;
            cout<<"  └─└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌┌─────────────┐"<<endl;
            cout<<"  ││ 7           │"<<endl;
            cout<<"  ││             │"<<endl;
            cout<<"  ││             │"<<endl;
            cout<<"  ││      ♠      │"<<endl;
            cout<<"  ││             │"<<endl;
            cout<<"  ││             │"<<endl;
            cout<<"  ││           7 │"<<endl;
            cout<<"  └└─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
            cout<<"  ┌─────────────┐"<<endl;
            cout<<"  │ 7           │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │      ♠      │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │             │"<<endl;
            cout<<"  │           7 │"<<endl;
            cout<<"  └─────────────┘"<<endl;
            Sleep(sleep);
            system("cls");
}

void Shuffle(vector<string>&Deck) // Fisher–Yates shuffle
{
    for(int i=Deck.size()-1;i>0;i--)
    {
        int j=rand()%(i+1);
        swap(Deck[i],Deck[j]);
    }
    ShuffleAnimation();
}

int main()
{
    system("chcp 65001"); // UTF-8
    system("cls");
    srand(time(NULL));
    vector<string>Deck= // system used for card storage: "[card_name][color]"
    {
    // Spades ♠
    "2S","3S","4S","5S","6S","7S","8S","9S","1S","JS","QS","KS","AS",
    // Diamonds ♦
    "2D","3D","4D","5D","6D","7D","8D","9D","1D","JD","QD","KD","AD",
    // Clubs ♣
    "2C","3C","4C","5C","6C","7C","8C","9C","1C","JC","QC","KC","AC",
    // Hearts ♥
    "2H","3H","4H","5H","6H","7H","8H","9H","1H","JH","QH","KH","AH"
    };
    vector<string>PlayerDeck;
    vector<string>ComputerDeck;

    Shuffle(Deck);
    Deal(Deck,PlayerDeck,ComputerDeck);

    while(true)
    {
        if(ComputerDeck.empty())
        {
            cout<<"<<<<< [ PLAYER HAS WON ] >>>>>\n";
            break;
        }
        if(PlayerDeck.empty())
        {
            cout<<"<<<<< [ COMPUTER HAS WON ] >>>>>\n";
            break;
        }
        {
            cout<<"<<<<< [ PLAYER HAS "<<PlayerDeck.size()<<" CARDS ] >>>>>\n";
            Print(PlayerDeck);
            cout<<"<<<<< [ COMPUTER HAS "<<ComputerDeck.size()<<" CARDS ] >>>>>\n";
            Print(ComputerDeck);
            Game(PlayerDeck,ComputerDeck);
            system("pause");
            system("cls");
        }
    }
    system("pause");
    return 0;
}
