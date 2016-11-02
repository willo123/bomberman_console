#include <iostream>
#include "bomberman.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;



int main()
{
    srand(time(NULL));
    int Size;
    int Choice;
    cout << "|madE bY bliZZarD |\n";
    cout << "|=================|\n";
    cout << "|B O M B E R M A N|\n";
    cout << "|=================|\n";
    cout << "| 1. Play vs BoT  |\n";
    cout << "| 2. Play online  |\n";
    cout << "|_________________|\n";
    cin >> Choice;

    switch (Choice){
        case 1:
            {
            int Bots = -1;
            vector <Piece*> Pieces;

            cout << "How big should the field be?\n";
            cin >> Size;
            bomberman_field* newField = new bomberman_field(Size);

            Pieces.push_back(new player(*newField));
            Pieces[0]->boardGet();

            while (Bots > 3 || Bots < 0){
            cout << "Choose botcount 1-3\n";
            cin >> Bots;
            }
            while (Bots > 0){
            Pieces.push_back(new bot(*newField));
            Bots--;
            }
            gameStart(*newField,Pieces);
            }
            break;
        case 2:
            {
            //Bomberman *Bot = new Bomberman;
            }
            break;
    }
}

