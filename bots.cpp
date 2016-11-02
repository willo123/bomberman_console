#include <iostream>
#include "bomberman.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

bot::bot(bomberman_field& Board, string Bot):Piece(Board, Bot){
Board.setPosition(x,y);
char **tmp = Board.getField();
token = tmp[x][y];
}

bot::~bot(){

}

void bot::makeMove(){
bomberman_field &Obj = this->boardGet( );
char **field = Obj.getField();
int oldX = x;
int oldY = y;

    if (1){
    if (field[x+1][y] == '.'){
        ++x;
        field[oldX][y] = '.';
    }
    else if (field[x-1][y] == '.'){
        --x;
        field[oldX][y] = '.';
    }
        field[x][y] = token;
        this->render = true;
    }
    else{
    this->render = false;
    }




}

