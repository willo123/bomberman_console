#include <iostream>
#include "bomberman.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

bomb::bomb(int x, int y, bomberman_field* Field, Piece* Char)
:bombX(x)
,bombY(y)
,Board(Field)
,Character(Char)
,bombCreatedTime(clock())
,exploded(false)
{
field = Field->getField();
field[x][y] = BOMB;
Field->printBoard();
}

bomb::~bomb(){

}

void bomb::bombExplode(){
exploded = true;
}

void bomb::bombTimer(){
if (field[bombX][bombY] == BOMB){
    field[bombX][bombY] = '3';
}
else if (field[bombX][bombY] == '3'){
    field[bombX][bombY] = '2';
}
else if (field[bombX][bombY] == '2'){
    field[bombX][bombY] = '1';
}
else if (field[bombX][bombY] == '1'){
    this->bombExplode();
}
this->Board->printBoard();
}


long bomb::getCreatedTime(){
return bombCreatedTime;
}

long bomb::setNewCreatedTime(long time){
bombCreatedTime = time;
}
