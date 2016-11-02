#ifndef BOMBERMAN_H_INCLUDED
#define BOMBERMAN_H_INCLUDED
#include <vector>
using namespace std;

class bomberman_field{
private:
   char **field;
   const int Size;
public:
   bomberman_field(int SizeIni);
    ~bomberman_field();
    char **getField();
    void printBoard();
    void setPosition(int &x, int &y);
    const int getSize();
};



class Piece{
    private:
        bomberman_field* BoardObj;
    protected:
        string type;
        bool render;
    public:
        char token;
        bool getRenderState();
        void setRenderState(bool opt);
        char retPieceType();
        string getType();
        Piece(bomberman_field& Board, string typeTaker);
        void printType();
        int getBoardSize();
        bomberman_field& boardGet();
        virtual ~Piece(){}
        virtual void makeMove()=0;
        //virtual void createBomb(bomberman_field& Board, char **field)=0;
        const int checkForWall(char** field, int&x, int&y, int oldX, int oldY);
};



class bomb{
private:
    bomberman_field* Board;
    Piece* Character;
    char **field;
    long bombCreatedTime;
    int bombX;
    int bombY;
public:
    bool exploded;
    bomb(int x, int y, bomberman_field* Field, Piece* Char);
    ~bomb();
    long getCreatedTime();
    long setNewCreatedTime(long time);
    void bombTimer();
    void bombExplode();
};




class player: public Piece{
private:
    int x;
    int y;
    vector<bomb> Bombs;
    int bombTotal;
    int bombs;
public:
    player(bomberman_field& Board, string player = "Player");
    void makeMove( );
    vector<bomb> &hey();
    //void createBomb(bomberman_field& Board, char **field);
    ~player();
};



class bot: public Piece{
private:
    int x;
    int y;
    vector<bomb> Bombs;
    int bombTotal;
    int bombs;
public:
    bot(bomberman_field& Board, string Bot = "Bot");
    void makeMove();
    bomb& retBomb();
    //void createBomb(bomberman_field& Board, char **field);
    ~bot();
};



const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;
const int SPACE = 32;

const char floor = '.';
const char BOMB = 162;
void gameStart(bomberman_field& field, vector<Piece*> &Pieces);
bool gameOver(bomberman_field& field, vector<Piece*> &Pieces);
bool renderState();

#endif // BOMBERMAN_H_INCLUDED


