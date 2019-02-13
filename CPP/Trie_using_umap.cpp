#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::unordered_map;

#define PRINTLOG()  cout<<__LINE__<<" "<<__FUNCTION__<<endl;

class Node{
    char mVal;
    bool mLeafStatus;
    unordered_map<char, Node *> mNext;
    public:
        Node(char ch):mVal(ch){}
        ~Node(){    }       //to delete all subnodes recursively
        void mInsertVal(char ch);
        Node *mGetNext(char ch){
            auto itr = mNext.find(ch);
            if(mNext.find(ch) == mNext.end()){   
                cout<<"reference to "<<ch<<" unavailable in "<<mVal<<endl;   
                return nullptr; //should not happen in general
            }
            cout<<"returning reference to "<<(itr->second->mVal)<<endl;
            return (itr->second);
        }
        char mGetVal(){ return mVal;   }
        void mSetLeafStatus(bool status){ mLeafStatus = status; }
        bool mGetLeafStatus(){  return mLeafStatus; }
        void mPrint(string s);
};

void Node::mInsertVal(char ch){
    PRINTLOG();
    mSetLeafStatus(false);
    mNext.insert({mGetVal(), new Node(ch)});
    cout<<"Added reference to "<<ch<< " in "<<mGetVal()<<endl;
}

void Node::mPrint(string s){
    if(mLeafStatus == true)
        cout<<s<<endl;
    for(auto &itr : mNext){
        s += itr.second->mVal;
        itr.second->mPrint(s);
        s.erase(s.length()-2, s.length());
    }
}

class Trie{
    Node *root;
    public:
        Trie(){
            root = new Node('.');
        }
        ~Trie(){
            delete root;
        }
        void mInsertWord(string word);
        void mPrintAll();
};

void Trie::mInsertWord(string word){
    PRINTLOG();
    Node *head = root;
    for(auto &ch : word){
        head->mInsertVal(ch);
        head = head->mGetNext(ch);
    }
    head->mSetLeafStatus(true);
}

void Trie::mPrintAll(){
    PRINTLOG();
    Node *head = root;
    string s="";
    head->mPrint(s);
}

int main(){
    Trie t;
    t.mInsertWord("Trie");
    t.mInsertWord("implementation");
    t.mInsertWord("using");
    t.mInsertWord("unordered");
    t.mInsertWord("map");
    t.mPrintAll();
    return 0;
}
