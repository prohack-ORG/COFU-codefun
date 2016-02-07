/*

Author : Siddheshwar P Sharma
Date   : 7th Feb 2016

*/

#include "graph_func.h"
#include "stack"

void dfs(Graph g, int start_vertex){
	cout<<"\nTotal ";
	g.details();
	cout<<"\nDFS traversal from vertex : "<<start_vertex<<endl;
	int counter = 0;
	stack<int> s;
	s.push(start_vertex);
	int src = s.top();
	s.pop();
	while(counter!=g.get_numEdges()){
		cout<<src<<"\t";
		struct Node *ref_node = g.node_list[src].head_node;
		if(ref_node->visited){
			cout<<"\nLoop detected in Graph at node : "<<src;
			exit(-1);
		}
		ref_node->visited = 1;
		if(ref_node==NULL && s.empty() && counter!=g.get_numEdges()){
			cout<<"\nDisconnected Graph";
			exit(-1);
		}
		else if(ref_node==NULL && !s.empty());
		else{
			while(!ref_node){
				ref_node = ref_node->next_node;
				s.push(ref_node->dest_node);
			}
		}
		src = s.top();
		s.pop();
		counter++;
	}
}
