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
	struct Node *ref_node;
	while(counter!=g.get_numNodes()){
		int src = s.top();
		s.pop();
		cout<<src<<"\t";
		ref_node = g.node_list[src].head_node;
		cout<<"\n**1 : "<<ref_node->dest_node;
		if(ref_node->visited){
			cout<<"\nLoop detected in Graph at node : "<<src;
			break;
		}
		ref_node->visited = 1;
		
		counter++;
		cout<<"\n**2";
		if(ref_node==NULL && s.empty() && counter!=g.get_numEdges()){
			cout<<"\nDisconnected Graph";
			break;
		}
		
		cout<<"\n**3";
			while(ref_node!=NULL){
				s.push(ref_node->dest_node);
				cout<<"\nIn loop pushing "<<ref_node->dest_node<<" now";
				ref_node = ref_node->next_node;
			}
		
		cout<<"\n**4";
	}
}
