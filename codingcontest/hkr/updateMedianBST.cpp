/*
*       @uthor : Raman Jaiswal <vipram91@gmail.com>
*       Date : Jun 18th, 2017
*       Problem : Median Update using BST
*       Source : Hackerrank->DS->Balanced Trees
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct _node{
    int val;
    char color;
    _node* left;
    _node* right;
    _node* parent;
}Node;

class _binarySearchTree{
    private:
        Node* root;
	    int numNode;
        Node* createNewNode(int key, char color);
        Node* getParent(Node* temp);
        Node* getleftChild(Node* temp);
        Node* getRightChild(Node* temp);
        Node* getSibling(Node* temp);
        char getColor(Node* temp);
        bool isLeft(Node* temp);
        bool isRight(Node* temp);
        bool isRightRight(Node* temp);
        bool isLeftLeft(Node* temp);
        bool isRightLeft(Node* temp);
        bool isLeftRight(Node* temp);
        void rotateRight(Node* temp);      
        void rotateLeft(Node* temp);
        void rotateRightLeft(Node* temp);
        void rotateLeftRight(Node* temp);
        void bstInsert(Node* root, int key);
        void balanceBSTafterInsert(Node* temp);
    public:
        _binarySearchTree(){
            root = NULL;
	    numNode = 0;
        }
        Node* insertNode(int key);
        Node* deleteNode(int key);
};
void median(vector<char> s,vector<int> X) {
    
    
}
int main(void){
   int N;
   cin >> N;
   
   vector<char> s;
   vector<int> X;
   char temp;
    int tempint;
   for(int i = 0; i < N; i++){
      cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
   }
   
   median(s,X);
   return 0;
}


