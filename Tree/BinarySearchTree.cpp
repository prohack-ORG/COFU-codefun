/*
*   Author : Siddheshwar P Sharma
*   Date   : 12 July 2017
*   Status : Not Working, Debugging in progress
*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
};

node *newNode(int newVal)
{
    node *t = new node;
    if(t == NULL)
        cout<<"\nFailed to create a new node";
    t->val = newVal;
    t->left = NULL;
    t->right = NULL;
    return t;
}

class BST
{
    public:
        node *root;
        BST()
        {
            root = NULL;
        }
        node *add_node(node *root, int newVal);
        node *get_root();
        void delete_node(int delVal);
        void inorder(node *root);
};

node *BST::get_root()
{
    return root;
}

node *BST::add_node(node *root, int newVal)
{
    if(root == NULL)
    {
        cout<<"\nRoot was null, assiging now";
        root = newNode(newVal);
        cout<<"\nAssigned value : "<<root->val;
        return root;
    }
    else
    {
        cout<<"\nat element "<<root->val;
        
        if(root->val < newVal)
            root->right = add_node(root->right, newVal);
        else
            root->left = add_node(root->left, newVal);
    }             
    return root;
}

void BST::inorder(node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<" "<<(root->val)<<" ";
    inorder(root->right);
}

int main()
{
    cout<<"\nThis is binary search tree, input node values 1 by 1 : \n";
    int val;
    BST bst;
    //cin>>val;
    //while(val != -1)
    for(int i=0; i<5; i++)
    {
        bst.root = bst.add_node(bst.root, (i+1)*19%23);
        //cin>>val;
        cout<<"\nInorder : \n";    
        bst.inorder(bst.root);
    }
    cout<<endl;
    return 0;
}
