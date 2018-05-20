#include <iostream>
#include <stdio.h>

#define MAX_LEN 20
#define MAX_ELEMENTS 50000
#define MAX_FEATURES 5
#define PRINTLOG() cout<<__func__<<" "<<__LINE__<<endl

using namespace std;

enum FIELD{ name, number, birthday, email, memo };

int num_elements;
int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, \
				71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, \
				151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199 } ;

unsigned int getKey(char *str){
    PRINTLOG();
    //TODO : put good hashKey generation algo
    int i = 0;
    int key = 1;
    while(str[i] != '\0'){
        key = (key + (str[i]*prime[i])%MAX_ELEMENTS)%MAX_ELEMENTS;
        i++;
    }
    return key;
}

void strCopy(char *to, char *from){
    PRINTLOG();
    for(int i=0; i<MAX_LEN; i++)
        to[i] = from[i];
}

bool strCompare(char *a, char *b){
    PRINTLOG();
    int i=0;
    while(i<MAX_LEN && a[i] != '\0' && b[i] != '\0'){
        if(a[i] != b[i])    return false;
        i++;
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
        void print(){
            cout<<mName<<" "<<mNumber<<" "<<mBirthday<<" "<<mEmail<<" "<<mMemo<<endl;
        }
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
        void print(int key);
        void mRemove(FIELD fieldID, char *sdtr);
        void removeNode(Node *parent, Node *cur, int key);
};

void Hash :: removeNode(Node *parent, Node *current, int key){
    PRINTLOG();
    
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
void Hash :: print(int key){
    Node *ptr = mHead[key].next;
    Node *parentNode = ptr;
    cout<<"hash indexes : "<<endl;
    while( ptr != NULL ){
    	cout<<ptr->mVal<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void Hash :: mAddNode(int val, int index){
    PRINTLOG();
    Node *ptr = mHead[val].next;
    Node *temp = new Node(index);
    temp->next = ptr;
    mHead[val].next = temp;
    PRINTLOG();
}

void Hash :: mRemove(FIELD fieldID, char *str){
    PRINTLOG();
    int key = getKey(str);
    Node *ptr = mHead[key].next;
    Node *parentNode = ptr;
    if(ptr != NULL && strCompare( dBase[ptr->mVal].getVal(fieldID), str )){
        delete ptr;
        mHead[key].next = NULL;
        return;
    }
    ptr = ptr->next;
    while( ptr != NULL ){

        parentNode = ptr;
        if( strCompare( dBase[ptr->mVal].getVal(fieldID), str ) )
            removeNode(parentNode, ptr, key);

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

void printRecords( int num ){
    PRINTLOG();
    cout<<endl;
    for(int i=0; i<num; i++)
        dBase[i].print();
    cout<<endl;
}

Hash indexHash[MAX_FEATURES];

void Database :: mUpdate(char *nameBuf, char *numberBuf, char *birthdayBuf, char *emailBuf, char *memoBuf){
    PRINTLOG();

    strCopy(mName, nameBuf);
    strCopy(mNumber, numberBuf);
    strCopy(mBirthday, birthdayBuf);
    strCopy(mEmail, emailBuf);
    strCopy(mMemo, memoBuf);
}
char* Database :: getVal(FIELD fieldID){
    PRINTLOG();
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
    PRINTLOG();
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
    PRINTLOG();
    //this is necessary to prevent memory leak, indexHash is statically allocated
    //but its collision nodes are allocated dynamically
    for(int i=0; i<MAX_FEATURES; i++)
        indexHash[i].mFreeNodes();
    //this is optional as buffers will be overwritten and will end with '\0'
    for(int i=0; i<MAX_ELEMENTS; i++)
        dBase[i].mResetBuffers();
    num_elements = 0;
    PRINTLOG();
}

void addRecord(char *nameBuf, char *numberBuf, char *birthdayBuf, char *emailBuf, char *memoBuf){
    PRINTLOG();
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
    PRINTLOG();
}

int delRecord(FIELD fieldID, char *str){
    PRINTLOG();

    int delCount=0;
    int key = getKey( str );

    //traverse hash and for all dBase[indexHash[key].val] fieldID matches, clean that record
    Node *ptr = indexHash[fieldID].mHead[key].next;
    Node *parentNode = ptr;
    
    indexHash[fieldID].print(key);
    while( ptr != NULL ){

        parentNode = ptr;
        if( strCompare( dBase[ptr->mVal].getVal(fieldID), str ) ){
            /*for( int i=0; i<MAX_FEATURES; i++ ){
                if( i!=fieldID ){
                	cout<<"index to delete : "<<ptr->mVal<<endl;
                    char *tempStr = dBase[ptr->mVal].getVal( (FIELD)i );
                    cout<<tempStr<<endl;
                    int newkey = getKey( tempStr );
                    indexHash[i].print(newkey);
                    //TODO : this will delete from hash all the occurrences of tempStr
                    //but only current index is to be removed from hash
                    indexHash[i].mRemove( fieldID, tempStr);
                    //indexHash[i].print(newkey);
                }
            }*/
            dBase[ptr->mVal].mResetBuffers();
            //indexHash[fieldID].removeNode(parentNode, ptr, key);
            //indexHash[fieldID].print(key);
            delCount ++;
        }
        //else
        ptr = ptr->next;
    }
    PRINTLOG();

    return delCount;
}

int changeRecord(FIELD fieldID, char *findStr, FIELD changeFieldID, char *replaceStr){
    PRINTLOG();

    int changeCount=0;
    int key = getKey( findStr );
    Node *ptr = indexHash[fieldID].mHead[key].next;
    Node *parentNode = ptr;
    while( ptr != NULL ){

        parentNode = ptr;
        if( strCompare( dBase[ptr->mVal].getVal( fieldID ), findStr ) ){

            dBase[ ptr->mVal ].mUpdate(changeFieldID, replaceStr);
            int newKey = getKey(replaceStr);
            indexHash[changeFieldID].print(newKey);
            indexHash[changeFieldID].mAddNode(newKey, ptr->mVal);
            indexHash[changeFieldID].print(newKey);
            //indexHash[fieldID].removeNode(parentNode, ptr, key);
            changeCount ++;
        }
        //else
            ptr = ptr->next;
    }

    PRINTLOG();
    return changeCount;
}

Result searchRecord(FIELD fieldID, char *str, FIELD getFieldID){
    PRINTLOG();

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
    PRINTLOG();
    return res;
}

int main(){
    PRINTLOG();
    int val = 0;
    init();
    addRecord("a1", "b1", "c1", "d1", "e1");
    printRecords( num_elements);
    addRecord("a2", "b2", "c2", "d2", "e2");
    printRecords( num_elements);
    addRecord("a3", "b3", "c3", "d3", "e3");
    printRecords( num_elements);
    addRecord("a4", "b4", "c4", "d4", "e4");
    printRecords( num_elements);
    addRecord("a5", "b5", "c5", "d5", "e5");
    printRecords( num_elements);
    addRecord("a6", "b6", "c6", "d6", "e6");
    printRecords( num_elements);
    addRecord("A2", "a6", "c6", "d6", "e6");
    printRecords( num_elements);
    addRecord("A2", "b6", "c6", "d6", "e6");
    printRecords( num_elements);

    cout<< delRecord(name, "a4") <<" deletions performed"<<endl;
    printRecords( num_elements);
    
    cout<< changeRecord(memo, "e2", name, "A2")<<" changes done"<<endl;
    printRecords( num_elements);

    Result r = searchRecord(email, "d3", name);
    cout<<r.count<<" records found and result is : "<<r.str<<endl;
    
    cout<< delRecord(name, "A2") <<" deletions performed"<<endl;
    printRecords( num_elements);
    
    cout<<endl;
    return 0;
}
