#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define SQUARE_LEN 10
#define SQUARE_SIZE SQUARE_LEN*SQUARE_LEN

enum GameState { OFF, ON, OVER };

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

struct Dice{
	int face;
	int throwDice(){
		face = (rand() % 6 + 1);
		printDice();
		return face;
	}
	void printDice(){
		cout<<"Face Value : "<<face<<endl;
	}
};

class Board{
	GameState mGameState;
	char mMaze[SQUARE_LEN][SQUARE_LEN];
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
};

Board :: Board(){
	mGameState = OFF;
	//Do some initialisation, will be used in future
	for(int y=0; y<SQUARE_LEN; y++)
		for(int x=0; x<SQUARE_LEN; x++)
			mMaze[y][x] = (y * SQUARE_LEN + x + 1);
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
    cout<<string(43, '_')<<endl;
	for(int y=0; y<SQUARE_LEN; y++){
        cout<<"| ";
		for(int x=0; x<SQUARE_LEN; x++){
            if(y*SQUARE_LEN+x != pos)
    			cout<<setw(3)<<(int)mMaze[y][x]<<" ";
            else
                cout<<string(4, ' ');
		}
		cout<<"|\n";
	}
    cout<<string(43, '_')<<endl;
}

int main(){
    char ch;
	Board gameBoard;// = new Board();
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
