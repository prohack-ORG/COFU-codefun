/*
 *       @uthor : Raman Jaiswal <vipram91@gmail.com>
 *       Date : July 1st, 2017
 *       Lib : Tree, BST, Red-Black Tree
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>

class Node{
    public:
        int val;
        char color;
        Node* left;
        Node* right;
        Node* parent;
        Node* getParent();
        Node* getLeft();
        Node* getRight();
        int getVal();
        char getColor();
        void setParent(Node*);
        void setLeft(Node*);
        void setRight(Node*);
        void setVal(int);
        void setColor(char);
};
class BinarySearchTree{
    protected:
        Node* root;
        int numNodes;
        Node* getSibling(Node* node);
        bool isLeft(Node* node);
        bool isRoot(Node* node);
        bool isRight(Node* node);
        bool isLeaf(Node* node);
        void printInOrder(Node* node);
        void deleteTree(Node* node);
        void printLevelOrder(Node* node);
        Node* createNewNode(int key, char color);
        Node* createNewNode(int key);
    public:
        int getMin();
        int getMax();
        int getInorderSuccessor(int key);
        int getInorderPredessor(int key);
        void printInOrder();
        BinarySearchTree();
        virtual ~BinarySearchTree();
        virtual void insert(int key) = 0;
        virtual void remove(int key) = 0;
        virtual bool isValidBST() = 0; 
};
class BST : public BinarySearchTree{
    private:
        Node* remove(Node* node, int key);
        bool isValidBST(Node* node,int prev);
    public:
        BST();
        ~BST();
        void insert(int key);
        void remove(int key);
        bool isValidBST(); //assuming Node data positive integer
};
class RedBlackTree : public BinarySearchTree{
    private:
        bool isRightRight(Node* node);
        bool isLeftLeft(Node* node);
        bool isRightLeft(Node* node);
        bool isLeftRight(Node* node);
        void rotateRight(Node* node);      
        void rotateLeft(Node* node);
        void rotateRightLeft(Node* node);
        void rotateLeftRight(Node* node);
        void remove(Node* node, int key);
    public:
        void insert(int key);
        void remove(int key);
        bool isValidBST();
        RedBlackTree();
        ~RedBlackTree();
};
