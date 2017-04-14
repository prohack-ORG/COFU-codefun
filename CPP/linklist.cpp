#include <iostream>
#include <stdio.h>
using namespace std;

struct node 
{
	int val;
	node *next;
};

class LIST
{
		node *head;
	public:
		LIST()
		{
			head = NULL;
		}
		node *gethead()
		{
			return head;
		}
};

void print_nodes(node *list);
node * addnode(node *head, int val)
{
	node *temp = new node();
	temp->val = val;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		printf("\nHEAD is null");
	}
	else
	{
		printf("\nHEAD is not null");
		temp->next = head;
		head = temp;
	}
	return head;
}

void print_nodes(node *list)
{
	while(list!=NULL)
	{
		printf("\n%d", list->val);
		list = list->next;
	}
	printf("\n");
}

int main()
{
	LIST *list = new LIST();
	node *head = list->gethead();
	head = addnode(head, 1);
	head = addnode(head, 2);
	head = addnode(head, 3);
	head = addnode(head, 4);
	print_nodes(head);
	return 0;
}