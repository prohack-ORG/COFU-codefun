/* REDUNDANT CODE SNIPPET */

#include <iostream>
#include <stdio.h>

using namespace std;

/* ACTUAL CODE SNIPPET */

#define MAX_ELEMENTS 50000
#define MAX_FEATURES 5
#define MAX_LEN 20

inline bool strCompare(char *a, char *b){
    int i=0;
    while(a[i]!='\0' && b[i]!='\0')
        if(a[i]!=b[i])   return false;
        else             i++;
    if(a[i]!='\0' || b[i]!= '\0')
        return false;
    return true;
}

inline void strCopy(char *a, char *b){
    int i=0;
    while(b[i]!='\0'){
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';
}

struct Hash{
    int val[MAX_ELEMENTS];
};

struct RECORD{
    int count;
    char val[MAX_LEN];
};

class DataBase{
    char name[MAX_LEN];
    char number[MAX_LEN];
    char bday[MAX_LEN];
    char email[MAX_LEN];
    char memo[MAX_LEN];
    public:
        void update(char *a, char *b, char *c, char *d, char *e){
            strCopy(name, a);
            strCopy(number, b);
            strCopy(bday, c);
            strCopy(email, d);
            strCopy(memo, e);
        }
        void removeRecord(){
            name[0] = '\0';
            number[0] = '\0';
            bday[0] = '\0';
            email[0] = '\0';
            memo[0] = '\0';
        }
        char *getFeature(int index){
            switch(index){
                case 0: return name;
                case 1: return number;
                case 2: return bday;
                case 3: return email;
                case 4: return memo;
            }
            return NULL;
        }
        void update(int featID, char *val){
            switch(featID){
                case 0: strCopy(name, val); break;
                case 1: strCopy(number, val); break;
                case 2: strCopy(bday, val); break;
                case 3: strCopy(email, val); break;
                case 4: strCopy(memo, val); break;
            }
        }
};

Hash hashmap[MAX_FEATURES];
DataBase db[MAX_ELEMENTS];
int num_elements;

int getKey(char *val){
    //TODO : update a suitable key generation mechanism
    return (num_elements*1234567)%MAX_ELEMENTS;
}

void updateHash(int hashID, char *val, int index){
    int key = getKey(val);
    while(hashmap[hashID].val[key] != -1)
        key++;
    hashmap[hashID].val[key] = index;
}

void initDatabase(){
    for(int id=0; id<MAX_FEATURES; id++)
        for(int i=0; i<MAX_ELEMENTS; i++)
            hashmap[id].val[i] = -1;
    num_elements = 0;
}

void addRecord(char *name, char *number, char *bday, char *email, char *memo){
    updateHash(0, name, num_elements);
    updateHash(1, number, num_elements);
    updateHash(2, bday, num_elements);
    updateHash(3, email, num_elements);
    updateHash(4, memo, num_elements);
    db[num_elements++].update(name, number, bday, email, memo);
}

int delRecord(int feature, char *strval){
    int delCount = 0;
    int key = getKey(strval);
    while(strCompare(strval, db[hashmap[feature].val[key]].getFeature(feature))){
        for(int i=0; i<MAX_FEATURES; i++)
            hashmap[i].val[getKey(db[hashmap[feature].val[key]].getFeature(i))] = -1;
        db[hashmap[feature].val[key]].removeRecord();
        key++;
        delCount++;
    }
    return delCount;
}

int changeRecord(int feature, char *strval, int chngFeature, char *chngVal){
    int chngCount = 0;
    int key = getKey(strval);
    while(strCompare(strval, db[hashmap[feature].val[key]].getFeature(feature))){
        db[hashmap[feature].val[key]].update(chngFeature, chngVal);
        key++;
        chngCount++;
    }
    return chngCount;
}

RECORD searchRecord(int featID, char *strval, int searchFeatID){
    RECORD r;
    r.count = 0;
    r.val[0] = '\0'; 
    int searchCount = 0;
    int key = getKey(strval);
    while(strCompare(strval, db[hashmap[featID].val[key]].getFeature(featID))){
        if(searchCount == 0){
            strCopy(r.val, db[hashmap[featID].val[key]].getFeature(searchFeatID));
        }
        key++;
        searchCount ++;
    }
    return r;
}

int main(){
    return 0;
}
