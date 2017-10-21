#include <stdio.h>
#include <iostream>

using namespace std;

struct node{
    node *next;
    int item;
};

class list{
    node *head;
    public :
        list(){head = NULL;}
        void add_node(int new_val);
        void del_node(int del_val);
        void print_list();
};

void list::add_node(int new_val){
    node *new_node = new node;
    new_node->item = new_val;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
        return;
    }
    node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

void list::del_node(int del_item){
    if(head == NULL){
        printf("\nNo node to delete\n");
        return;
    }
    node *ptr = head;
    if(head->item == del_item){
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    while(ptr->next != NULL){
        if(ptr->next->item == del_item){
            node *temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
            return;    
        }   
        ptr = ptr->next;
    }
    if(ptr->next == NULL && ptr->item == del_item){
        node *temp = ptr->next;
        ptr->next = NULL;
        delete temp;
        return;
    }
    printf("\nNo such element found in the list to be deleted");
}

void list::print_list(){
    node *ptr = head;
    printf("\n+++++++++++++++++++++++++++++++++++++++++++\n");
    if(ptr == NULL){
        printf("\nThere are no elements in the list\n");
        return;
    }
    while(ptr!=NULL){
        printf("%d\t", ptr->item);
        ptr = ptr->next;
    }
    printf("\n-------------------------------------------\n");
}

int main(){
    list *mList;
    mList = new list();
    mList->add_node(1);
    mList->add_node(2);
    mList->add_node(3);
    mList->add_node(4);
    mList->add_node(5);
    mList->print_list();
    mList->del_node(4);
    mList->print_list();
    mList->del_node(1);
    mList->print_list();
    mList->del_node(5);
    mList->print_list();
    mList->del_node(31);
    mList->print_list();
    mList->del_node(2);
    mList->print_list();
    return 0;
}
