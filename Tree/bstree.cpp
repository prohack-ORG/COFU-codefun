//Status : Incomplete
#include <iostream>
#include <stdio.h>

using namespace std;

class Node{
    int val;
    Node *left;
    Node *right;
    public:
        Node():left(NULL), right(NULL){}
        Node(int v):left(NULL), right(NULL), val(v){}
        int getVal(){ return val; }
        Node *getLeft(){   return left;    }
        Node *getRight(){   return right;   }
        void setVal(int v){ val = v; }
        void setLeft(Node *l){   left = l;    }
        void setRight(Node *r){   right = r;   }
};

class BSTree{
    Node *root;
    public:
        BSTree():root(NULL){}
        Node *getRoot(){    return root;    }
        void setRoot(Node *ptr){    root = ptr;    }
        Node *addNode(Node *ptr, int v);
        void inorder(Node *root);
        Node *delNode(Node *ptr, int v);
        Node *inorder_successor(Node *ptr);
        void printRoot();
};

Node *BSTree::addNode(Node *ptr, int v){
    if(ptr == NULL)
        return new Node(v);
    if(ptr->getVal() < v)
        ptr->setRight(addNode(ptr->getRight(), v));
    else
        ptr->setLeft(addNode(ptr->getLeft(), v));
    return ptr;
}

Node *BSTree::inorder_successor(Node *ptr){
    if(ptr == NULL)
        return ptr;
    Node *parent = ptr;
    while(ptr->getLeft() != NULL){
        parent = ptr;
        ptr->setLeft(ptr->getLeft());
    }
    if(parent != ptr)
        parent->setLeft(ptr->getRight());
    return ptr;
}

Node *BSTree::delNode(Node *ptr, int v){
    if(ptr==NULL)
        return ptr;
    if(ptr->getVal() < v){
        ptr->setRight(delNode(ptr->getRight(), v));
    }
    else if(ptr->getVal() > v){
        ptr->setLeft(delNode(ptr->getLeft(), v));   
    }
    else{
        Node *temp = inorder_successor(ptr->getRight());
        if(temp != NULL){
            temp->setLeft(ptr->getLeft());
            if(ptr->getRight() != temp){
                temp->setRight(ptr->getRight());
            }
        }
        if(ptr == root)
            root = temp;
        delete ptr;
        return temp;
    }
    return ptr;
}

void BSTree::inorder(Node *root){
    if(root == NULL)    return;
    inorder(root->getLeft());
    cout<<root->getVal()<<" ";
    inorder(root->getRight());
}

void BSTree::printRoot(){
    cout<<"Root is : "<<root->getVal()<<endl;
}

int main(){
    BSTree *b = new BSTree();
    b->setRoot(b->addNode(b->getRoot(), 50));
    b->setRoot(b->addNode(b->getRoot(), 30));
    b->setRoot(b->addNode(b->getRoot(), 20));
    b->setRoot(b->addNode(b->getRoot(), 40));
    b->setRoot(b->addNode(b->getRoot(), 70));
    b->setRoot(b->addNode(b->getRoot(), 60));
    b->setRoot(b->addNode(b->getRoot(), 80));
    b->setRoot(b->addNode(b->getRoot(), 55));
    b->setRoot(b->addNode(b->getRoot(), 35));
    b->setRoot(b->addNode(b->getRoot(), 25));
    b->setRoot(b->addNode(b->getRoot(), 45));
    b->setRoot(b->addNode(b->getRoot(), 75));
    b->setRoot(b->addNode(b->getRoot(), 65));
    b->setRoot(b->addNode(b->getRoot(), 85));
    b->inorder(b->getRoot());
    cout<<endl;
    b->printRoot();
    b->setRoot(b->delNode(b->getRoot(), 20));
    b->inorder(b->getRoot());
    cout<<endl;
    b->printRoot();
    b->setRoot(b->delNode(b->getRoot(), 45));
    b->inorder(b->getRoot());
    cout<<endl;
    b->printRoot();
    b->setRoot(b->delNode(b->getRoot(), 70));
    b->inorder(b->getRoot());
    cout<<endl;
    return 0;
}   
