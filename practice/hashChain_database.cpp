#include <iostream>
#include <stdio.h>

#define MAX_LEN 20
#define MAX_ELEMENTS 50000
#define MAX_FEATURES 5

using namespace std;

enum FIELD{ name, number, birthday, email, memo };

int num_elements;

unsigned int getKey(char *str){
    //TODO : put good hashKey generation algo
}

void strCopy(char *to, char *from){
    for(int i=0; i<MAX_LEN; i++)
        to[i] = from[i];
}

bool strCompare(char *a, char *b){
    int i=0;
    while(i<MAX_LEN && a[i] != '\0' && b[i] != '\0'){
        if(a[i] != b[i])    return false;
    }
    if(a[i] != '\0' || b[i] != '\0')    return false;
    return true;
}

struct Result{
    int count;
    char str[20];
};

struct Node{
    int mVal;
    Node *next;
    public:
        Node():next(NULL){}
        Node(int v):mVal(v),next(NULL){}
};

void removeNode(Node *parent, Node *current){
    if(current->next == NULL){
        parent = current->next;
        delete current;
        current = NULL;    //TODO : can cause crash, check validity
        return;
    }
    Node *temp = current;
    parent->next = current->next;
    delete temp;
}

class Database{
    char mName[MAX_LEN];
    char mNumber[MAX_LEN];
    char mBirthday[MAX_LEN];
    char mEmail[MAX_LEN];
    char mMemo[MAX_LEN];
    public:
        /*
        //Let the default constructer work as we are not creating dynamic database
        Database(char *name, char *number, char *birthday, char *email, char *memo){
            strCopy(mName, name);
            strCopy(mNumber, number);
            strCopy(mBirthday, birthday);
            strCopy(mEmail, email);
            strCopy(mMemo, memo);
        }
        */
        void mUpdate(char *name, char *number, char *birthday, char *email, char *memo);
        void mResetBuffers();
        char *getVal(FIELD fieldID);
        void mUpdate(FIELD fieldID, char *str);
};

Database dBase[MAX_ELEMENTS];

class Hash{
    public:
    Node mHead[MAX_ELEMENTS];
        Hash(){
            for(int i=0; i<MAX_ELEMENTS; i++){
                mHead[i].next = NULL;
            }
        }
        void mAddNode(int val, int index);
        void mFreeNodes();
        void mRemove(FIELD fieldID, char *sdtr);
};

void Hash :: mAddNode(int val, int index){
    Node *ptr = mHead[val].next;
    Node *temp = new Node(num_elements);
    temp->next = ptr;
    mHead[val].next = temp;
}

void Hash :: mRemove(FIELD fieldID, char *str){

    Node *ptr = mHead[getKey(str)].next;
    Node *parentNode = ptr;
    while( ptr != NULL ){

        parentNode = ptr;
        if( strCompare( dBase[ptr->mVal].getVal(fieldID), str ) )
            removeNode(parentNode, ptr);

        else
            ptr = ptr->next;
    }
}

void Hash :: mFreeNodes(){
    for(int i=0; i<MAX_ELEMENTS; i++)
    {
        Node *ptr = mHead[i].next;
        while(ptr != NULL){
            Node *temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        mHead[i].next = NULL;
    }
}

Hash indexHash[MAX_FEATURES];

void Database :: mUpdate(char *nameBuf, char *numberBuf, char *birthdayBuf, char *emailBuf, char *memoBuf){

    strCopy(mName, nameBuf);
    strCopy(mNumber, numberBuf);
    strCopy(mBirthday, birthdayBuf);
    strCopy(mEmail, emailBuf);
    strCopy(mMemo, memoBuf);
}
char* Database :: getVal(FIELD fieldID){
    //values are not going to be changed directly outside
    //thus returning address for saving strCopy() time.
    switch(fieldID){

        case 0: return mName;
        case 1: return mNumber;
        case 2: return mBirthday;
        case 3: return mEmail;
        case 4: return mMemo;
    }
    return NULL;
}

void Database :: mUpdate(FIELD fieldID, char *str){
    //exploiting getVal to overwrite feature
    strCopy(getVal(fieldID), str);
}

void Database :: mResetBuffers(){

    mName[0]     = '\0';
    mNumber[0]   = '\0';
    mBirthday[0] = '\0';
    mEmail[0]    = '\0';
    mMemo[0]     = '\0';
}

void init(){
    //this is necessary to prevent memory leak, indexHash is statically allocated
    //but its collision nodes are allocated dynamically
    for(int i=0; i<MAX_FEATURES; i++)
        indexHash[i].mFreeNodes();
    //this is optional as buffers will be overwritten and will end with '\0'
    for(int i=0; i<MAX_ELEMENTS; i++)
        dBase[i].mResetBuffers();
    num_elements = 0;
}

void addRecord(char *nameBuf, char *numberBuf, char *birthdayBuf, char *emailBuf, char *memoBuf){
    //Update Database and Hash here
    dBase[num_elements].mUpdate( nameBuf, numberBuf, birthdayBuf, emailBuf, memoBuf );
    int namekey     = getKey( nameBuf     );
    int numberKey   = getKey( numberBuf   );
    int birthdayKey = getKey( birthdayBuf );
    int emailKey    = getKey( emailBuf    );
    int memoKey     = getKey( memoBuf     );
    indexHash[0].mAddNode( namekey    , num_elements);
    indexHash[1].mAddNode( numberKey  , num_elements);
    indexHash[2].mAddNode( birthdayKey, num_elements);
    indexHash[3].mAddNode( emailKey   , num_elements);
    indexHash[4].mAddNode( memoKey    , num_elements);
    num_elements ++;
}

int delRecord(FIELD fieldID, char *str){

    int delCount=0;
    int key = getKey( str );

    //traverse hash and for all dBase[indexHash[key].val] fieldID matches, clean that record
    Node *ptr = indexHash[fieldID].mHead[key].next;
    Node *parentNode = ptr;
    while( ptr != NULL ){

        parentNode = ptr;
        if( strCompare( dBase[ptr->mVal].getVal(fieldID), str ) ){
            for( int i=0; i<MAX_FEATURES; i++ ){
                if( i!=fieldID ){
                    char *tempStr = dBase[ptr->mVal].getVal( (FIELD)i );
                    int key = getKey( tempStr );
                    indexHash[i].mRemove( fieldID, tempStr);
                }
            }
            dBase[ptr->mVal].mResetBuffers();
            removeNode(parentNode, ptr);
            delCount ++;
        }
        else
            ptr = ptr->next;
    }

    return delCount;
}

int changeRecord(FIELD fieldID, char *findStr, FIELD changeFieldID, char *replaceStr){

    int changeCount=0;
    int key = getKey( findStr );
    Node *ptr = indexHash[fieldID].mHead[key].next;
    Node *parentNode = ptr;
    while( ptr != NULL ){

        parentNode = ptr;
        if( strCompare( dBase[ptr->mVal].getVal( fieldID ), findStr ) ){

            dBase[ ptr->mVal ].mUpdate(changeFieldID, replaceStr);
            int newKey = getKey(replaceStr);
            indexHash[changeFieldID].mAddNode(newKey, ptr->mVal);
            removeNode(parentNode, ptr);
            changeCount ++;
        }
        else
            ptr = ptr->next;
    }

    return changeCount;
}

Result searchRecord(FIELD fieldID, char *str, FIELD getFieldID){

    Result res;
    res.count = 0;
    res.str[0] = '\0';
    int key = getKey( str );
    Node *ptr = indexHash[fieldID].mHead[key].next;
    Node *parentNode = ptr;
    while( ptr != NULL ){

        parentNode = ptr;
        if( strCompare( dBase[ptr->mVal].getVal( fieldID ), str ) ){

            if(res.count == 0)
                strCopy(res.str, dBase[ptr->mVal].getVal( getFieldID ));
            res.count ++;
        }
        ptr = ptr->next;
    }
    return res;
}

int main(){
    return 0;
}


