/*
 *       @uthor : Raman Jaiswal <vipram91@gmail.com>
 *       Date : July 1st, 2017
 *       Lib : Tree, BST
 */
#include "tree.h"

//////////////////////////NODE/////////////////////////////
Node* Node::getParent(){
    return parent;
}
Node* Node::getLeft(){
    return left;
}
Node* Node::getRight(){
    return right;
}
int Node::getVal(){
    return val;
}
char Node::getColor(){
    return color;
}
void Node::setParent(Node* p){
    parent = p;
}
void Node::setLeft(Node* l){
    left = l;
}
void Node::setRight(Node* r){
    right = r;
}
void Node::setVal(int key){
    val = key;
}
void Node::setColor(char ch){
    color = ch;
}
///////////////////////BinarySearchTree////////////////////////////////////////
Node* BinarySearchTree::createNewNode(int key){
    Node* node = new Node;
    node->setVal(key);
    node->setColor('b');
    node->setLeft(NULL);
    node->setRight(NULL);
    node->setParent(NULL);
    return node;
}
Node* BinarySearchTree::createNewNode(int key, char color){
    Node* node = new Node;
    node->setVal(key);
    node->setColor(color);
    node->setLeft(NULL);
    node->setRight(NULL);
    node->setParent(NULL);
    return node;
}
Node* BinarySearchTree::getSibling(Node* node){
    if(isRoot(node)) return NULL;
    if(isLeft(node)){
        return node->getParent()->getRight();
    }
    else if(isRight(node)){
        return node->getParent()->getLeft();
    }
    return NULL;
}
bool BinarySearchTree::isLeft(Node* node){
    if(isRoot(node)) return false;
    Node* left = node->getParent()->getLeft();
    if(left == node)
        return true;
    else return false;
}
bool BinarySearchTree::isRoot(Node* node){
    return node->getParent() == NULL;
}
bool BinarySearchTree::isRight(Node* node){
    if(isRoot(node)) return false;
    Node* right = node->getParent()->getRight();
    if(right == node)
        return true;
    else return false;
}
bool BinarySearchTree::isLeaf(Node* node){
    return node->getLeft() == NULL && node->getRight() == NULL;
}
BinarySearchTree::BinarySearchTree(){
    root = NULL;
    numNodes = 0;
}
BinarySearchTree::~BinarySearchTree(){
    std::cout<<"deleting tree : ";
    if(root)
        deleteTree(root);
    root = NULL;
    std::cout<<std::endl;
}
int BinarySearchTree::getMin(){
    Node* node = root;
    while(node->getLeft()){
        node = node->getLeft();
    }
    return node->getVal();    
}
int BinarySearchTree::getMax(){
    Node* node = root;
    while(node->getRight()){
        node = node->getRight();
    }
    return node->getVal();    
}
Node* BinarySearchTree::getRoot(){
    return root;    
}
int BinarySearchTree::getInorderSuccessor(int key){
    return -1; //TODO
}
int BinarySearchTree::getInorderPredessor(int key){
    return -1; //TODO
}
void BinarySearchTree::printInOrder(){
    if(!root) return;
    printInOrder(root);
}
void BinarySearchTree::printInOrder(Node* root){
    if(!root) return;
    printInOrder(root->getLeft());
    std::cout<<root->getVal()<<" ";
    printInOrder(root->getRight());
}
void BinarySearchTree::deleteTree(Node* root){
    if(!root) return;
    deleteTree(root->getLeft());
    deleteTree(root->getRight());
    std::cout<<root->getVal()<<" ";
    delete root;
    numNodes--;
}
void BinarySearchTree::printLevelOrder(Node* root){
    //TODO
}
///////////////////////////BST/////////////////////////
BST::BST(){
    //TODO
}
BST::~BST(){
    //TODO
}    
void BST::insert(int key){
    std::cout<<"inserting : ["<<key<<"] ";
    Node* newNode = createNewNode(key);
    if(!root){
        root =newNode;
        newNode->setParent(NULL);
        return;
    }
    Node* curr = root;
    while(curr){
        if(curr->getVal() > key && curr->getLeft())
            curr = curr->getLeft();
        else if(curr->getVal() < key && curr->getRight())
            curr = curr->getRight();
        else break;
    }
    if(curr->getVal() > key) 
        curr->setLeft(newNode);
    else if(curr->getVal() < key)
        curr->setRight(newNode);
    newNode->setParent(curr);    
    numNodes++;
}
Node* BST::remove(Node* node, int key){
    if(node == NULL) return NULL;
    if(node->val > key)
        node->left = BST::remove(node->left, key);
    else if(node->val < key)
        node->right = BST::remove(node->right,key);
    else{
        // is leaf node
        if(isLeaf(node)){
            delete node;
            return NULL;
        }
        // has single child
        if(node->left && node->right == NULL){
            Node* temp = node->left;
            node->left->parent = node->parent;
            delete node;
            return temp;
        }
        if(node->right && node->left == NULL){
            Node* temp = node->right;
            node->right->parent = node->parent;
            delete node;
            return temp;
        }
        // has both child 
        if(node->left && node->right){
            Node* temp = node->right;
            while(temp->left){
                temp = temp->left;
            }
            node->val = temp->val;
            node->right = BST::remove(node->right,temp->val);
            return node;
        }
        numNodes--;    
    }
    return node;
}
void BST::remove(int key){
    std::cout<<"removing : ["<<key<<"] ";
    if(root == NULL) 
        return;
    root = BST::remove(root, key);
}
bool BST::isValidBST(Node* root, int prev){
    if(root == NULL) return true;
    bool flag = BST::isValidBST(root->left, prev);
    if(flag && prev<root->val){
        prev = root->val;
        flag = BST::isValidBST(root->right,prev);
    }
    return flag;
}
bool BST::isValidBST(){
    if(root == NULL) return true;
    int prev = INT_MIN;
    return BST::isValidBST(root,prev);
}

