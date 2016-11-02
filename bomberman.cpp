#include <iostream>
#include "bomberman.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;


//////PIECE////////
string Piece::getType(){
return type;
}

const int Piece::checkForWall(char **field, int &x, int &y, int oldX, int oldY){
    if (field[x][y] == '.'){
        return 1;
    }
    if (field[x][y] == BOMB && x == oldX && y == oldY){
        return 2;
    }
    else{
        return 0;
    }

}

void Piece::setRenderState(bool opt){
render = opt;
}

bool Piece::getRenderState(){
return render;
}

bomberman_field &Piece::boardGet(){
    return *BoardObj;
}


Piece::Piece(bomberman_field &Field, string typeTaker): type(typeTaker), BoardObj(&Field){

}

void Piece::printType(){
cout << type << endl;
}

/////// Field /////////

bomberman_field::~bomberman_field(){

}

bomberman_field::bomberman_field(int SizeIni):Size(SizeIni){
    field = new char*[Size];
        for (int i = 0; i<Size; ++i){
            field[i] = new char[Size];
        }

         for (int i = 0; i<Size; ++i){
            for (int j = 0; j<Size; ++j){
                if (i == 0 || j == 0 || i == Size-1 || j == Size-1){
                    field[i][j] = 254;
                }
                else if (i % 2 == 0 && j % 2 == 0){
                    field[i][j] = 254;
                }
                else{
                    int random = rand()%2;
                    if ((random == 1) &&
                        (!((i < 3 && j > Size-4) || (i < 3 && j < 3) ||
                        (i>Size-4 && j > Size-4) || (i > Size-4 && j < 3 )  ))){
                        field[i][j] = 127;
                    }
                    else{
                    field[i][j] = '.';
                    }
                }
            }
         }

    }

char **bomberman_field::getField(){
    return field;
}

const int bomberman_field::getSize(){
    return Size;
}


void bomberman_field::printBoard(){
     system("cls");
     cout << endl<<endl<<endl;
     for (int i = 0; i<Size; ++i){
                cout << "\t\t\t";
            for (int j = 0; j<Size; ++j){
                cout << field[i][j] << " ";
            }
            cout << endl;
         }
}

void bomberman_field::setPosition(int &x, int &y){
    if (field[1][1] == '.'){
        field[1][1] = 'A';
        x = 1;
        y = 1;
    }
    else if (field[Size-2][Size-2] == '.'){
        field[Size-2][Size-2] = 'B';
        x = Size-2;
        y = Size-2;
    }
    else if (field[1][Size-2] == '.'){
        field[1][Size-2] = 'C';
        x = 1;
        y = Size-2;
    }
    else{
        field[Size-2][1] = 'D';
        x = Size-2;
        y = 1;
    }
}
