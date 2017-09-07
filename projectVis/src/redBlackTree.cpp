/*
 *       @uthor : Raman Jaiswal <vipram91@gmail.com>
 *       Date : Sep 8th, 2017
 *       Class  :  Red-Black Tree
 */
#include "tree.h"

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
