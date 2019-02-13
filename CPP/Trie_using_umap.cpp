#include <stdio.h>
#include <unordered_map>
#include <map>
#include <vector>
#include <string.h>
#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::unordered_map;
using std::multimap;

//#define PRINTLOG()  cout<<__LINE__<<" "<<__FUNCTION__<<endl;
#define PRINTLOG()
class Node{
    char mVal;
    bool mLeafStatus;
    unordered_map<char, Node *> mNext1;
    multimap<char, Node *> mNext;
    public:
        Node(char ch):mVal(ch){}
        ~Node(){    }       //to delete all subnodes recursively
        Node *mInsertVal(char ch);
        Node *mGetNext(char ch){
            auto itr = mNext.find(mVal);
            if(itr == mNext.end()){   
                cout<<"reference to "<<ch<<" unavailable in "<<mVal<<endl;   
                return nullptr; //should not happen in general
            }
            cout<<"returning reference to "<<(itr->second->mVal)<<endl;
            return (itr->second);
        }
        int mGetNextCount(){	return mNext.size();	}
        char mGetVal(){ return mVal;   }
        void mSetLeafStatus(bool status){ mLeafStatus = status; }
        bool mGetLeafStatus(){  return mLeafStatus; }
        void mPrint(string s);
};

Node * Node::mInsertVal(char ch){
    PRINTLOG();
    mSetLeafStatus(false);
    Node *node = new Node(ch);
    //if(node == nullptr)
    	//cout<<"Failed\n";
    mNext.insert({mGetVal(), node});
    //cout<<"Added reference to "<<ch<< " in "<<mGetVal()<<endl;
    return node;
}

void Node::mPrint(string s){
	//cout<<"mVal : "<<mVal<<" has "<<mGetNextCount()<<endl;
    if(mLeafStatus == true)
        cout<<s<<endl;
    for(auto &itr : mNext){
    //for(auto &itr = mNext.begin(); itr != mNext.end(); itr++){
    	//cout<<mVal<<"  -> "<<(itr.second->mVal)<<endl;
        s += itr.second->mVal;
        itr.second->mPrint(s);
        //s.erase(s.length()-2, s.length()-1);
        s.pop_back();
    }
    //cout<<"mVal OVER "<<mVal<<endl;
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
        head = head->mInsertVal(ch);
        //head = head->mGetNext(ch);
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