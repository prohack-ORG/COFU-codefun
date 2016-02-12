/*

Author : Siddheshwar P Sharma
Date   : 6th Feb 2016

*/

#include "graph_func.h"

// Function to take input, drive the graph and give output
int main(){
	Graph g(9);
	
	/* input 1 : loops present
	g.insert_edges(0,1);		
	g.insert_edges(0,2);		
	g.insert_edges(1,3);		
	g.insert_edges(1,4);		
	g.insert_edges(2,2);		
	g.insert_edges(4,3);		
	g.insert_edges(3,0);		
	g.insert_edges(2,0);		
	g.insert_edges(1,4);
	*/

	/* input 2 : loops present
	g.insert_edges(0,4);		
	g.insert_edges(1,3);		
	g.insert_edges(2,1);		
	g.insert_edges(3,3);		
	g.insert_edges(3,2);		
	g.insert_edges(4,3);		
	g.insert_edges(3,0);		
	g.insert_edges(2,0);		
	g.insert_edges(1,4);
	g.print_adj_graph();
	*/

	/* input 3 : normal tree input*/
	g.insert_edges(0, 1);
    g.insert_edges(0, 2);
    g.insert_edges(1, 3);
    g.insert_edges(1, 4);
    g.insert_edges(2, 5);
    g.insert_edges(2, 6);
	g.insert_edges(6, 0);
	g.insert_edges(6, 8);

	dfs(g,0);	// function to calculate dfs[fails for disconnected graphs]

	cout<<endl;
	return 0;
}
