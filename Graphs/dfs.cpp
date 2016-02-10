/*

Author : Siddheshwar P Sharma
Date   : 7th Feb 2016

*/

#include "graph_func.h"
#include "stack"

void dfs(Graph g, int start_vertex){
	int data[g.get_numNodes()];
	cout<<"\nTotal ";
	g.details();
	cout<<"\nDFS traversal from vertex :\t"<<start_vertex<<endl;
	int counter = 0;
	stack<int> s;
	s.push(start_vertex);
	struct Node *ref_node;
	while(counter!=g.get_numNodes()){
		int src = s.top();
		s.pop();
		data[counter] = src;
		//cout<<"\nDFS : \t\t\t\t"<<src;
		ref_node = g.node_list[src].head_node;
		counter++;				
		if(ref_node==NULL){
			continue;
		}

		if(ref_node->visited){
			cout<<"\nLoop detected in Graph at node : "<<src;
			break;
		}
		ref_node->visited = 1;
		
		if(ref_node==NULL && s.empty() && counter!=g.get_numEdges()){
			cout<<"\nDisconnected Graph";
			break;
		}
		
		while(ref_node!=NULL){
			s.push(ref_node->dest_node);
			ref_node = ref_node->next_node;
		}
		
	}
	cout<<"\nDFS :\t";
	for(int i = 0;i<g.get_numNodes();i++)
		cout<<data[i]<<"\t";
}
