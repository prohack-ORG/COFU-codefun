/*

Author : Siddheshwar P Sharma
Date   : 7th Feb 2016

*/

#include <iostream>
#include <stdlib.h>

using namespace std;
struct Node{
	int dest_node;
	Node *next_node;
};

struct Node_list{
	struct Node *head_node;
};

class Graph{
	int num_nodes;
	int num_edges;
	struct Node_list *node_list;
  public :
	Graph(int num){
		num_edges = 0;
		num_nodes = num;
		node_list = (struct Node_list *)malloc(sizeof(struct Node_list )*num);
		for(int i=0;i<num;i++){
			node_list[i].head_node=NULL;
		}
	}
	void details();
	void insert_edges(int src, int dest);
	void print_adj_graph();
};


