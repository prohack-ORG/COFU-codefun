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

using namespace std;

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
	int find_combination();
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
	cout<<"\n\nSub-Graph "<<num_dis_graphs<<" DFS: ";
	int count=0;
	s.push(start);
	while(!s.empty()){
		int node = s.top();
		cout<<"\t "<<node;
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
}

int Graph::find_combination(){
	int sum = 0;
	cout<<endl;
	for(int i=0;i<num_dis_graphs;i++)
		cout<<node_count[i]<<" ";
	cout<<endl;
	for(int i=0;i<num_dis_graphs;i++)
		for(int j=i+1;j<num_dis_graphs;j++)
			sum+=node_count[i]*node_count[j];
	return sum;
}

int main()
{
	int N,I;
	int st_pt,en_pt;
	int mul=1;
	cin>>N>>I;
	Graph g(N);
	for(int i=0;i<I;i++){
		cin>>st_pt>>en_pt;
		g.insert_node(st_pt,en_pt);
	}
	for(int i=0;i<N;i++)
		g.dfs(i);
	cout<<endl<<g.find_combination()<<endl<<endl;
	return 0;
}
