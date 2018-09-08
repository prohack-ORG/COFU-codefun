/**
 * Problem  : Dictionary implementation using Trie Data Structure
 * Date     : 08-Sept-2018
 * Status   : completed, build and run success. To be tested thoroughly for memory leaks and Segfaults
 * i/p file : input_Dictionary.txt
 * 
 */


#include <iostream>
#include <stdio.h>

//using to read input efficiently
#include <string>

using namespace std;

//A-Z + a-z + 0-9 + 3(special char)
#define NUM_ELE 65

struct node;
class Trie;

void eraseTrie(node *root);
void printTrie(node *root);

inline int getIndexFromChar(char ch){
    if(ch >= '0' && ch <= '9')
        return int(ch - '0');
    if(ch >= 'A' && ch <= 'Z')
        return int(ch - 'A');
    if(ch >= 'a' && ch <= 'z')
        return int(ch - 'a');
    //a default value if none of above match, to be updated with proper value later
    return 64;
}

enum state{
    NONLEAF = 0,
    LEAF
};

struct node{
    node *branch[NUM_ELE];
    state mState;
    char mVal;
    node(char ch = '.'):mVal(ch){

        for(int i=0; i<NUM_ELE; i++){

            branch[i] = NULL;
        }
        mState = NONLEAF;
    }
    void mAddNode(int index, char ch){

        branch[index] = new node(ch);
    }
    void mSetState(state st){   mState = st;    }
    state mGetState(){   return mState;    }
    node *mGetBranchByIndex(int index){

        // ASSERT(index < NUM_ELE);
        return branch[index];
    }
    node *mGetBranchByIndex(char ch){

        int index = getIndexFromChar(ch);
        // ASSERT(index < NUM_ELE);
        return branch[index];
    }
    void operator<<(node *ptr){

        cout<<(ptr->mVal);
    }
};

class Trie{
    node *head;
    public:

        Trie(){     head = NULL;    }
        void mInit(){

            if(head != NULL){
                //erase existing Dictionary
                eraseTrie(head);
            }
            head = new node;
        }
        //To enable printing in wrapper, only for debugging purpose
        node *mGetHeadNode(){   return head;    }
        void mAddWord(const char *word);
        void mRemoveWord(const char *word);
        bool mSearchWord(const char *word);
};


//Global Dictionary, better alternative will be a singleton class
Trie *dict;

bool Trie::mSearchWord(const char *word){

    int start = 0;
    node *ptr = head;
    while(word[start] != '\0'){

        int index = getIndexFromChar(word[start]);
        //return from character if it doesn't exist already
        if(ptr->mGetBranchByIndex(index) == NULL){
            return false;
        }
        //Traverse the character node if exists
        ptr = ptr->mGetBranchByIndex(index);
        start ++;
    }
    state st = ptr->mGetState();
    return st;
}

void Trie::mRemoveWord(const char *word){

    int start = 0;
    node *ptr = head;
    while(word[start] != '\0'){

        int index = getIndexFromChar(word[start]);
        //return from character if it doesn't exist already
        if(ptr->mGetBranchByIndex(index) == NULL){
            return;
        }
        //Traverse the character node if exists
        ptr = ptr->mGetBranchByIndex(index);
        start ++;
    }
    ptr->mSetState(NONLEAF);
    //TODO : remove all nodes which do not have further branches
}

void Trie::mAddWord(const char *word){

    int start = 0;
    node *ptr = head;
    while(word[start] != '\0'){

        int index = getIndexFromChar(word[start]);
        //Create a node from character if it doesn't exist already
        if(ptr->mGetBranchByIndex(index) == NULL){
            ptr->mAddNode(index, word[start]);
        }
        //Traverse the character node if exists
        ptr = ptr->mGetBranchByIndex(index);
        start ++;
    }
    ptr->mSetState(LEAF);
}

void eraseTrie(node *root){

    if(root == NULL)
        return;
    for(int i=0; i<NUM_ELE; i++){
        eraseTrie(root->mGetBranchByIndex(i));
    }
    delete[] root;
}

void printTrie(node *root, string &word, int pos){

    if(root == NULL)
        return;
    word += root->mVal;
    if(root->mGetState() == LEAF)
        cout<<word.substr(1, word.length())<<endl;
    for(int i=0; i<NUM_ELE; i++){
        printTrie(root->mGetBranchByIndex(i), word, pos+1);
    }
    word.erase(word.length()-1, word.length());
}

void init(){
    //TODO
    if(dict != NULL){
        eraseTrie(dict->mGetHeadNode());
    }
    dict = new Trie();
    dict->mInit();
}

void addWord(const char *ch){
    //TODO
    dict->mAddWord(ch);
}

void removeWord(const char *ch){
    //TODO
    dict->mRemoveWord(ch);
}

bool searchWord(const char *ch){
    //TODO
    bool exists = dict->mSearchWord(ch);
    return exists;
}

int main(){
    cout<<"*********************** DICTIONARY START ***********************"<<endl<<endl;
    freopen("input_Dictionary.txt", "r", stdin);
    init();
    string querry;
    string word;
    cin>>querry;
    while(querry != ""){
        if(querry == "add"){
            cin>>word;
            cout<<"insert "<<word<<endl;
            addWord(word.c_str());
        }
        else if(querry == "del"){
            cin>>word;
            cout<<"delete "<<word<<endl;
            removeWord(word.c_str());
        }
        else if(querry == "chk"){
            cin>>word;
            cout<<word<<" "<<(searchWord(word.c_str()) ? "Found!" : "not Found!")<<endl;
        }
        else if(querry == "print"){

            cout<<"*********************** Printing Dictionary now ***********************"<<endl;    
            string word;
            printTrie(dict->mGetHeadNode(), word, 0);
        }
        else if(querry == "exit")
            break;
        cin>>querry;
        
    }
    cout<<endl<<"*********************** DICTIONARY OVER ***********************"<<endl;
    return 0;
}