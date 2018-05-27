#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define SQUARE_LEN 10
#define SQUARE_SIZE SQUARE_LEN*SQUARE_LEN

enum GameState { OFF, ON, OVER };

int getRandom(int from, int to){
    int val = rand()%(to-from+1)+from;
    return val;
}

struct Position{
    int x, y;
    int getCurPos(){
        return y * SQUARE_LEN + x;
    }
    void setCurPos(int pos){
        if(pos == -1){
            y = -1, x = -1;
            return;
        }
        y = pos / SQUARE_LEN;
        x = pos % SQUARE_LEN;
    }
    void printPos(){
        cout<<"Position : "<<y*SQUARE_LEN+x+1<<endl;
    }
};

struct SmallSquare{
    //Position mPos;
    string mVal;
    void mSetVal(int num){
        mVal.clear();
        mVal += to_string(num);
    }
    void mSetVal(string str){
        mVal.clear();
        mVal = str;
    }
    string mGetVal(){
        return mVal; 
    }
    void mPrintSquare(){
        //cout<<string('_', 7)<<endl;
        cout<<"| "<<setw(8)<<mVal<<" |";
        //cout<<endl<<string('_', 7);
    }
};

struct Dice{
    int face;
    int throwDice(){
        face = getRandom(1, 6);//(rand() % 6 + 1);
        printDice();
        return face;
    }
    void printDice(){
        cout<<"Face Value : "<<face<<endl;
    }
};

class Board{
    GameState mGameState;
    SmallSquare mMaze[SQUARE_LEN][SQUARE_LEN];
    Position mCurPos;
    Dice die;
    public:
        Board();
        void mMove();
        void mGameOver();
        void mPrintBoard();
        GameState mGetGameState(){
            return mGameState;
        }
        void mInitSnakes(int count);
        void mInitLadders(int count);
        void mSetVal(int pos, int val);
};

Board :: Board(){
    mGameState = OFF;
    //Do some initialisation, will be used in future
    for(int y=0; y<SQUARE_LEN; y++)
        for(int x=0; x<SQUARE_LEN; x++)
            mMaze[y][x].mSetVal(y * SQUARE_LEN + x + 1);
    mCurPos.setCurPos(-1);
}

void Board :: mMove(){
    int step = die.throwDice();
    if(mGameState == OFF){
        if(step == 6){
            mGameState = ON;
            mCurPos.setCurPos(step-1);
            cout<<"GAME STARTS NOW"<<endl;
        }
        else
            cout<<"Need face value 6 to START the game"<<endl;
        return;
    }
    int pos = mCurPos.getCurPos();
    if( pos + step < SQUARE_SIZE ){
        mCurPos.setCurPos(pos + step);
        mCurPos.printPos();
        if( (pos + step) == SQUARE_SIZE-1)
            mGameOver();
    }
    else
        cout<<"Move not allowed"<<endl;
}

void Board :: mGameOver(){
    mGameState = OVER;
    cout<<"GAME OVER"<<endl;
    //Show number of dice throws done over the game
}

void Board :: mPrintBoard(){
    int pos = mCurPos.getCurPos();
    //cout<<"\n---------------------------------\n";
    cout<<string(123, '_')<<endl;
    for(int y=0; y<SQUARE_LEN; y++){
        cout<<"|";
        for(int x=0; x<SQUARE_LEN; x++){
            if(y*SQUARE_LEN+x != pos)
                //cout<<setw(3)<<mMaze[y][x].mGetVal()<<" ";
                mMaze[y][x].mPrintSquare();
            else
                cout<<string(12, ' ');
        }
        cout<<"|\n";
    }
    cout<<string(123, '_')<<endl;
}

void Board :: mInitSnakes(int num_snakes){
    int count=0;
    while(count < num_snakes){
        int st_snake = getRandom(10, 99);
        int en_snake = getRandom(10, st_snake-6);
        //while(en_snake >= st_snake)
        //    en_snake = getRandom(10, 99);
        count++;
        mSetVal(st_snake, en_snake-st_snake);
    }
}

void Board :: mInitLadders(int num_ladders){
    int count=0;
    while(count < num_ladders){
        int st_ladder = getRandom(5, 90);
        int en_ladder = getRandom(st_ladder+6, 90);
        //while(en_ladder <= st_ladder)
        //    en_ladder = getRandom(5, 90);
        count++;
        mSetVal(st_ladder, en_ladder-st_ladder);
    }
}

void Board :: mSetVal(int pos, int val){
    int y = pos / SQUARE_LEN;
    int x = pos % SQUARE_LEN;
    mMaze[y][x].mSetVal( "Goto "+to_string(pos+val));
}

int main(){
    char ch;
    Board gameBoard;// = new Board();
    gameBoard.mInitSnakes(5);
    gameBoard.mInitLadders(5);
    gameBoard.mPrintBoard();
    while(gameBoard.mGetGameState() != OVER){
        cout<<"Roll the Dice"<<endl;
        cin.ignore();
        system("clear");
        gameBoard.mMove();
        gameBoard.mPrintBoard();
    }
    
    return 0;
}
