/*
 *       @uthor : Raman Jaiswal <vipram91@gmail.com>
 *       Date : July 1st, 2017
 *       Lib : Tree, BST, Red-Black Tree
 */
#include "tree.h"

#define NBBST

int main(){
#ifdef NBBST
    BinarySearchTree *tree = new BST();
    int arrInsert[] = {25,30,19,7,50,35,60,12,1,21,27,29,70,55,49,11,6,13};
    int arrDelete[] = {12,7,30,50,19,1,70,11,35};
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
    len = sizeof(arrDelete)/sizeof(arrDelete[0]);
    i=0;
    std::cout<<" deletion started \n\n";
    while(i<len && tree->isValidBST()){
        tree->remove(arrDelete[i++]);
        //    std::cout<<"Inorder Print : ";
        //    tree->printInOrder();
        //    std::cout<<std::endl;
        std::cout<<"min : "<<tree->getMin()<<" max : "<<tree->getMax()<<std::endl<<std::endl;
    }
#else
    BinarySearchTree *tree = new RedBlackTree();
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
#endif
    delete tree;
    return 0;
}
