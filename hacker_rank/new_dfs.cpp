/*

Author : Siddheshwar P Sharma
Date   : 12th Feb 2016

*/

/// Moon problem from hackerrank
/// LINK : https://www.hackerrank.com/challenges/journey-to-the-moon

/*

test i/p :
_________

4 2
0 1
2 3

*/

#include <iostream>
#include <list>
#include <stack>
#include <stdlib.h>

using namespace std;

long comb(long val){
	if(val==1)
		return 0;
	long cal = (val%2==0)?((val-1)*(val/2)):(val*(val-1)/2);
	//cout<<"\n"<<val<<" comb : "<<cal<<endl;
	return cal;
}

class Graph{
	int V,E;
	int num_dis_graphs;
	int *node_count;
	bool *visited;
	list<int > *adj;
	stack<int> s;
  public : 
	Graph(int num){
		this->V = num;
		E=0;
		num_dis_graphs=0;
		adj = new list<int>[num];
		node_count = new int[num];
		visited = new bool[num];
		for(int i=0;i<V;i++)
			visited[i]=false;
	}
	void insert_node(int start, int end);
	void dfs(int start);
	long find_combination();
};

void Graph::insert_node(int start, int end){
	
	adj[start].push_back(end);	
	adj[end].push_back(start);
	E++;
}

void Graph::dfs(int start){
	if(visited[start]==true)
		return;
	num_dis_graphs++;
	//cout<<"\n\nSub-Graph "<<num_dis_graphs<<" DFS: ";
	int count=0;
	s.push(start);
	while(!s.empty()){
		int node = s.top();
		//cout<<"\t "<<node;
		s.pop();
		count++;
		visited[node]=true;
		list<int >:: iterator i;
		for(i = adj[node].begin();i!=adj[node].end();i++){
			if(visited[*i]==false)
				s.push(*i);
		}
	}
	node_count[num_dis_graphs-1] = count;
	//cout<<"\nNo of nodes in graph : "<<num_dis_graphs-1<<" : "<<count; 
}

long Graph::find_combination(){
	long sum = 0;
	//cout<<endl<<"No of Subgraphs : "<<num_dis_graphs<<endl;
	/*
	long temp[num_dis_graphs];
	temp[0]=node_count[0];
	//cout<<node_count[0]<<" ";
	for(long i=1;i<num_dis_graphs;i++){
		//cout<<node_count[i]<<" ";
		temp[i]=temp[i-1]+node_count[i];
		cout<<" "<<temp[i];
	}
	cout<<endl;
	sum=temp[num_dis_graphs-1]*(num_dis_graphs-1);
	cout<<sum<<" ";
	for(long i=1;i<num_dis_graphs;i++){
		sum+=(V-temp[i-1])*(num_dis_graphs-i-1);
		cout<<" "<<sum;
	} 
	*/
	//cout<<endl;
	for(int i=0;i<num_dis_graphs;i++){
		//cout<<" "<<node_count[i];
		sum+=comb(node_count[i]);
	}
	return (comb(V)-sum);
}

int main()
{
	int N,I;
	int st_pt,en_pt;
	
	cin>>N>>I;
	int *temp=(int *)malloc(sizeof(int)*N);
	Graph g(N);
	for(int i=0;i<I;i++){
		cin>>st_pt>>en_pt;
		temp[st_pt]=1;
		temp[en_pt]=1;
		g.insert_node(st_pt,en_pt);
	}
	for(int i=0;i<N;i++)
		//if(temp[i]==1){
			//cout<<"\nDFS on node : "<<i;
			g.dfs(i);
		//}
	cout<<endl<<g.find_combination()<<endl;
	return 0;
}
