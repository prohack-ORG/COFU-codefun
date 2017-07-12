/*
 *       @uthor : Raman Jaiswal <vipram91@gmail.com>
 *       Date : July 1st, 2017
 *       Lib : Tree, BST, Red-Black Tree
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
////////////////////////RED BLACK TREE///////////////////////////
bool RedBlackTree::isRightRight(Node* node){
    return isRight(node) && isRight(node->getParent());  //TODO Verifiy
}
bool RedBlackTree::isLeftLeft(Node* node){
    return isLeft(node) && isLeft(node->getParent());  //verify 
}
bool RedBlackTree::isRightLeft(Node* node){
    return isRight(node) && isLeft(node->getParent());  //verify
}
bool RedBlackTree::isLeftRight(Node* node){
    return isLeft(node) && isRight(node->getParent());  //verify
}
Node* RedBlackTree::rotateRight(Node* x){
    /*  
     *         |                 | 
     *         X                 Y
     *        / \    Rot(X)     / \
     *       Y   a   ----->    b   X
     *      / \                   / \
     *     b   c                 c   a
     */
    Node* y = x->left;
    if(y == NULL) return NULL;  //TODO remove
    x->left = y->right;
    if(y->right)
        y->right->parent = x;
    y->parent = x->parent;
    if(x->parent == NULL)
        root = y;
    else if(x->parent->left == x)
        x->parent->left = y;
    else 
        x->parent->right = y;
    y->right = x;
    x->parent = y;
    return y;
}
Node* RedBlackTree::rotateLeft(Node* y){
    /*  
     *         |                 | 
     *         X                 Y
     *        / \    Rot(Y)     / \
     *       Y   a   <-----    b   X
     *      / \                   / \
     *     b   c                 c   a
     */
    Node* x = y->right;
    if(x == NULL) return NULL; //TODO remove
    y->right = x->left;
    if(x->left)
        x->left->parent = y;
    x->parent = y->parent;
    if(y->parent == NULL)
        root = x;
    else if(y->parent->left == y)
        y->parent->left = x;
    else 
        y->parent->right = x;
    x->left = y;
    y->parent = x;
    return x;
}
void RedBlackTree::insert(int key){
    // basic BST insert
    std::cout<<"inserting : ["<<key<<"] ";
    Node* newNode = createNewNode(key,'r');
    if(!root){
        root = newNode;
        newNode->setParent(NULL);
        root->setColor('b');
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
    //TODO 
    //balancing tree
    //1. root then set black :DONE at LINE:303 
    //2. parent is black
    //3. parent is red
    //   3.A uncle is red too
    //   3.B no uncle or uncle is black
    curr = newNode;
    std::cout<<"Node added ["<<curr->val<<"]\n";
    if(curr->parent->color == 'b')
        return;
    while(curr->color == 'r' && curr->getParent() && curr->parent->color=='r'){
        Node* uncle = getSibling(curr->parent);
        if(uncle != NULL && uncle->color == 'r'){
            uncle->setColor('b');
            curr->parent->setColor('b');
            if(curr->parent->parent == root){
                curr->parent->parent->setColor('b');
                break;
            }
            curr->parent->parent->setColor('r');
            curr = curr->parent->parent;
        }
        else if((uncle != NULL && uncle->color == 'b') || !uncle){
            if(isRightRight(curr)){
                char tempColor = curr->parent->getColor();
                curr->parent->setColor(curr->parent->parent->getColor());
                curr->parent->parent->setColor(tempColor);
                curr = rotateLeft(curr->parent->parent);
            }
            else if(isLeftLeft(curr)){
                char tempColor = curr->parent->getColor();
                curr->parent->setColor(curr->parent->parent->getColor());
                curr->parent->parent->setColor(tempColor);
                curr = rotateRight(curr->parent->parent);
            }
            else if(isRightLeft(curr)){
                curr = rotateLeft(curr->parent);
                char tempColor = curr->getColor();
                curr->setColor(curr->parent->getColor());
                curr->parent->setColor(tempColor);
                curr = rotateRight(curr->parent);
            }
            else if(isLeftRight(curr)){
                curr = rotateRight(curr->parent);
                char tempColor = curr->getColor();
                curr->setColor(curr->parent->getColor());
                curr->parent->setColor(tempColor);
                curr = rotateLeft(curr->parent);
            }
        }
    }
}
void RedBlackTree::remove(Node* node, int key){
    //TODO
}
void RedBlackTree::remove(int key){
    //TODO
}
bool RedBlackTree::hasRedRelationship(Node* node){
    if(node && node->getColor()== 'r'){
        if((node->right && node->right->getColor() == 'r') || (node->left && node->left->getColor() == 'r'))
            return true;
    }
    return false;
}
bool RedBlackTree::isValidBST(Node* node,int blackHeight,int &maxBH, bool isfirstLeafFound){
//    printf("%s +++++++\n",__func__);
    if(!node) return true;
    if(hasRedRelationship(node))
        return false;
    if(node->getColor()=='b')
        blackHeight += 1;
    if(isLeaf(node)){
        if(!isfirstLeafFound){
            isfirstLeafFound = true;
            maxBH = blackHeight;
            return true;
        }
        else if(isfirstLeafFound && maxBH != blackHeight){
            return false;
        }
        else if(isfirstLeafFound && maxBH == blackHeight){
            return true;
        }
    }
    bool flagL = true;
    if(node->left)
        flagL = isValidBST(node->left,blackHeight,maxBH,isfirstLeafFound);
    if(flagL && node->right)
        return isValidBST(node->right,blackHeight,maxBH,isfirstLeafFound);
    return true;
//    printf("%s --------\n",__func__);
}
bool RedBlackTree::isValidBST(){
    int maxiBH = -1;
    if(root == NULL)
        return true;
    return root->getColor()=='b' && isValidBST(root,0,maxiBH,false);
}
RedBlackTree::RedBlackTree(){
    //TODO
}
RedBlackTree::~RedBlackTree(){
    //TODO
}
///////////////////////////////////////////////////////
//Wrapper Function
int main(){
    //BinarySearchTree *tree = new BST();
    BinarySearchTree *tree = new RedBlackTree();
    // int arrInsert[] = {25,30,19,7,50,35,60,12,1,21,27,29,70,55,49,11,6,13};
    // int arrDelete[] = {12,7,30,50,19,1,70,11,35};
    //int arrInsert[] = {5,9,-1,10,20,30,60,17,19,11,14,35};
    int arrInsert[] = {5,9,-1,10,20,17,30,19,60,14,35,11};
    int len = sizeof(arrInsert)/sizeof(arrInsert[0]);
    int i=0;
    while(i<len && tree->isValidBST()){
        tree->insert(arrInsert[i++]);
        std::cout<<"Inorder Print : ";
        tree->printInOrder(); 
        std::cout<<std::endl;
        if(tree->getRoot()==NULL){
            std::cout<<"No Root !\n";
        }
        else{
            std::cout<<"Root: ["<<tree->getRoot()->getVal()<<"]\t";
        }
        std::cout<<"min : "<<tree->getMin()<<" max : "<<tree->getMax()<<"\n\n";
    }
    /*    len = sizeof(arrDelete)/sizeof(arrDelete[0]);
          i=0;
          std::cout<<" deletion started \n\n";
          while(i<len && tree->isValidBST()){
          tree->remove(arrDelete[i++]);
    //    std::cout<<"Inorder Print : ";
    //    tree->printInOrder(); 
    //    std::cout<<std::endl;
    std::cout<<"min : "<<tree->getMin()<<" max : "<<tree->getMax()<<std::endl<<std::endl;
    }
     */
    delete tree;
    return 0;
}
