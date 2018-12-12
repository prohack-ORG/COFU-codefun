#include <iostream>
#include <stdio.h>
#include <string.h>

#define cin std::cin
#define cout std::cout
#define endl std::endl
#define string std::string

enum BoardState{
    UNDECIDED,
    DRAW,
    DECIDED,
};

enum RecordState{
    WON,
    LOST
};

class Board{
    char mMat3x3[3][3];
    int currY;
    int currX;
    int mMoveCount;
    public:
        Board(){
            mInit();
        }
        void mInit(){
            mMoveCount = 0;
            cout<<"Board Initialization"<<endl;
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                    mMat3x3[i][j] = ' ';
        }
        void mDisplay(){

            cout<<"----------------"<<endl;
            for(int i=0; i<3; i++){
                cout<<" | ";
                for(int j=0; j<3; j++)
                    cout<<mMat3x3[i][j]<<" | ";
                cout<<endl;
            }
            cout<<"----------------"<<endl;
        }
        bool mCheckValid(int indexY, int indexX){
            return (indexY >= 0 && indexY <=3 && indexX >= 0 && indexX <=3 &&mMat3x3[indexY][indexX] == ' ');
        }
        bool checkLeftDiag(char ch){
            return ((mMat3x3[(currY+1)%3][(currX+1)%3] == ch)&&(mMat3x3[(currY+2)%3][(currX+2)%3] == ch));
        }
        bool checkRightDiag(char ch){
            return ((mMat3x3[(currY-1)%3][(currX+1)%3] == ch)&&(mMat3x3[(currY-2)%3][(currX+2)%3] == ch));
        }
        bool checkDiag(char ch){
            int tempPos = currY*3+currX;
            switch(tempPos){
                case 0:
                case 2:
                case 4:
                case 6:
                case 8: return checkLeftDiag(ch) || checkRightDiag(ch);
                default: return false;
            }
        }
        bool checkVert(char ch){
            return ((mMat3x3[(currY+1)%3][currX] == ch)&&(mMat3x3[(currY+2)%3][currX] == ch));
        }
        bool checkHor(char ch){
            return ((mMat3x3[currY][(currX+1)%3] == ch)&&(mMat3x3[currY][(currX+2)%3] == ch));
        }
        BoardState mCheckState(char ch){
            //TODO : implement code to check win/draw
            bool state = (checkDiag(ch)||checkVert(ch)||checkHor(ch));
            return (state ? DECIDED : (mMoveCount == 9 ? DRAW : UNDECIDED));
        }

        BoardState mUpdate(int indexY, int indexX, char ch){
            mMoveCount ++;
            mMat3x3[indexY][indexX] = ch;
            currY = indexY;
            currX = indexX;
            return mCheckState(ch);
        }
};

class Player{
    string mPlayername;
    char mSymbol;
    int mWinCount, mLostCount;
    public:
        Player():mWinCount(0), mLostCount(0){
            cout<<"Player Initialization"<<endl;
        };
        void mInit(){
            cout<<"Enter name and symbol : "<<endl;
            cin>>mPlayername>>mSymbol;
        }
        string mGetName(){
            return mPlayername;
        }
        char mGetSymbol(){
            return mSymbol;
        }
        void mUpdateRecord(RecordState r){
            if(r == WON) mWinCount ++;
            else         mLostCount ++;
        }
        void mPrintStats(){
            cout<<"Name : "<<mPlayername<<endl;
            cout<<"Wins : "<<mWinCount<<endl;
            cout<<"Lost : "<<mLostCount<<endl;
        }
};

enum NEWGAMESTATE{
    REPEAT, 
    NEW
};

class GameManager{
    Board b;
    Player *p1, *p2;
    int mTurn;
    int indexX, indexY;
    BoardState mState;
    public:
        GameManager():p1(nullptr), p2(nullptr), mTurn(0), mState(UNDECIDED){}
        Player *mGetTurn(){
            return mTurn%2 ? p1 : p2;
        }
        void mInit(NEWGAMESTATE state){
            
            b.mInit();
            if(state == NEW){
                cout<<"Please input Player1 details : "<<endl;
                p1 = new Player();
                p1->mInit();
                cout<<"Please input Player2 details : "<<endl;
                p2 = new Player();
                p2->mInit();
            }
            mTurn = 0;
            mState = UNDECIDED;
        }
        void mPlay(){
            //play until win/draw/withdraw
            while(1){
                b.mDisplay();
                Player *current = mGetTurn();
                cout<<"move for "<<(current->mGetName())<<endl;
                cin>>indexY>>indexX;
                if(b.mCheckValid(indexY, indexX)){

                    mTurn ++;
                    mState = b.mUpdate(indexY, indexX, current->mGetSymbol());
                    if(mState == UNDECIDED) continue;
                    else if(mState == DRAW)
                        cout<<"GAME DRAW"<<endl;
                    else if(current == p1){
                        p1->mUpdateRecord(WON);
                        p2->mUpdateRecord(LOST);
                        cout<<(p1->mGetName())<<" WINS"<<endl;
                    }
                    else if(current == p2){
                        p2->mUpdateRecord(WON);
                        p1->mUpdateRecord(LOST);
                        cout<<(p2->mGetName())<<" WINS"<<endl;
                    }
                    b.mDisplay();
                    mGameOver();
                }
                else{
                    cout<<"INVALID move, play again"<<endl;
                }
            }
        }
        void mGameOver(){
            //TODO : ask for replay or quit
            int opt;
            cout<<"1. Close Game"<<endl;
            cout<<"2. Play Again"<<endl;
            cin>>opt;
            if(opt == 1){
                cout<<"STATS : "<<endl;
                p1->mPrintStats();
                p2->mPrintStats();
                exit(0);
            }
            else{
                mInit(REPEAT);
                mPlay();
            }
        }
};

int main(){
    GameManager g;
    g.mInit(NEW);
    g.mPlay();
    return 0;
}