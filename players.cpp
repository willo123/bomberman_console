#include <iostream>
#include "bomberman.h"
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <ctime>


player::player(bomberman_field &Board, string player):Piece(Board,player){
Board.setPosition(x,y);
char **tmp = Board.getField();
token = tmp[x][y];
bombTotal = 1;
bombs = 0;
}


player::~player(){

}




void player::makeMove(){

bomberman_field &Obj = this->boardGet();
char **field = Obj.getField();
bool renderScr = true;

    int oldX = x;
    int oldY = y;

    int ch = getch();
    if (!(field[x][y] == BOMB)){
    field[x][y] = '.';
    }

        switch(ch){

            case KEY_UP:{
                field[--x][y];
                break;
            }
            case KEY_DOWN:{
                field[++x][y];
                break;
            }
            case KEY_RIGHT:{
                field[x][++y];
                break;
            }
            case KEY_LEFT:{
                field[x][--y];
                break;
            }
            case SPACE:{
                Bombs.push_back(bomb(x,y, &Obj, this));
                //this->createBomb(Obj,field);
                break;
            }
            default:
                break;
        }
        if ((checkForWall(field,x,y,oldX,oldY) == 0))
        {
            x = oldX;
            y = oldY;
            this->render = false;
            field[x][y] = token;
            return;
        }
        else if (checkForWall(field,x,y,oldX,oldY) == 1){
            this->render = true;
            field[x][y] = token;
            return;
        }
        else if (checkForWall(field,x,y,oldX,oldY) == 2){
            this->render = true;
            field[x][y] = BOMB;
        }
    }

vector<bomb> &player::hey(){
return Bombs;
}



