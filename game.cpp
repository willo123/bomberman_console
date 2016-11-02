#include <iostream>
#include "bomberman.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
long TimeElapsed = 0;
long PlayerElapsed = 0;
bool botFound;

bool gameOver(bomberman_field& field, vector<Piece*> &Pieces){
return true;
//gettickcount();
}

void gameStart(bomberman_field& field, vector<Piece*> &Pieces){

    vector<Piece*>::iterator itr, End = Pieces.end();
    int findPlayer = 0;
    player* Player = NULL;
    vector<bomb> *Pbomb;


	while (1){

    if (clock() - TimeElapsed > 150){
		for (itr = Pieces.begin();itr!=End;++itr){
			if (findPlayer == 0 && ((*itr)->getType() == "Player")){
                Player = static_cast<player*>(*itr);
                Pbomb = &Player->hey();
				cout << endl << Pbomb;

				++findPlayer;
			}

			if ((*itr)->getType() != "Player"){
                 botFound = true;
                (*itr)->makeMove();
			}
            }
            TimeElapsed = clock();
            if (botFound){
            field.printBoard();
            }
        }


    if (!(*Pbomb).empty()){
        vector<bomb>::iterator itr = (*Pbomb).begin(), End = (*Pbomb).end();
        while(End != itr){
            --End;
        if ((*End).exploded == false){
            if (clock()-(*End).getCreatedTime() >= 750){
            (*End).bombTimer();
            (*End).setNewCreatedTime(clock());
            }
            }
        else{
            (*Pbomb).erase(End);
            }
        }
    }


    if (clock() - PlayerElapsed > 25 ){
		if (_kbhit()){
            Player->makeMove();
            if (Player->getRenderState() == true)
                field.printBoard();
		}
		PlayerElapsed = clock();
		Player->setRenderState(false);
	}
}
}








