/*

Author : Siddheshwar P Sharma
Date   : 14th Feb 2016

*/

// Find Hamiltonian Cycle in graph

#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;

class Graph{
	int V;
	list<int > *adj;
	int *visited;
	int *path;
  public: 
	Graph(int num){
		this->V=num;
		adj = new list<int>[V];
		visited = new int[V];
		path = new int[V];
		for(int i=0;i<V;i++)
			visited[i]=0,path[i]=-1;
		cout<<"\nConstructed Graph ";
	}
	void insert_node(int src, int des);
	void print_graph();
	bool hamiltonian(int pos);
};

void Graph::insert_node(int src, int des){
	adj[src].push_back(des);
	cout<<"\nInserted node "<<des<<" at "<<src;
}

bool Graph::hamiltonian(int pos){
	if(pos == V){
		list<int> ::iterator i;
		for(i=adj[pos].begin();i!=adj[pos].end();i++)
			if(*i == 0)
				return true;
			else 
				return false;
	}
	for(int j=1;j<V;j++){
		list<int >:: iterator i;
		for(i=adj[j].begin();i!=adj[j].end();i++)
			if(*i==pos&&visited[j]==0){
				visited[j]=1;
				return hamiltonian(j);	
				visited[j]=0;
			}
	}
	return false;
}

void Graph::print_graph(){
	cout<<"\nPrinting Graph now : "<<endl;
	list<int >::iterator i;
	for(int j=0; j<V; j++){
		cout<<endl<<"j : "<<j<<"  ->  ";
		for(i=adj[j].begin();i!=adj[j].end();i++)
			cout<<*i<<" ";
	}
}
int main(){
	
	Graph g(5);
	/*
	g.insert_node(0,1);	
	g.insert_node(0,2);	
	g.insert_node(0,3);	
	g.insert_node(2,4);	
	g.insert_node(1,3);	
	g.insert_node(4,4);	
	*/
	g.insert_node(0,1);
	g.insert_node(1,2);
	g.insert_node(1,4);
	g.insert_node(2,4);
	g.insert_node(4,3);
	g.insert_node(3,1);
	g.insert_node(3,0);
	g.print_graph();
	if(g.hamiltonian(0))
		cout<<"\nHamiltonian path exists in the Graph.";
	else
		cout<<"\nNo hamiltonian path in the graph.";
	cout<<endl;
	return 0;
} 
