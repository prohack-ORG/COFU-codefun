/*

Author : Siddheshwar P Sharma
Date   : 18th Feb 2016

*/

/// Prims Algorithm using matrix representation of graph

#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

int getMinDist(int *dist, int N, int *visited){
	int min = INT_MAX, pos=0;
	for(int i=0;i<N;i++)
		if(dist[i]<min && !visited[i])
			min = dist[i], pos = i;
	return pos;
}

void prims(int **map, int N){

	int *dist = new int[N];
	int *parent = new int[N];
	int *visited = new int[N];

	for(int i=0;i<N;i++)
		visited[i]=0,dist[i]=INT_MAX,parent[i]=-1;
	
	dist[0]=0;

	for(int i=0;i<N-1;i++){
		
		int src = getMinDist(dist,N,visited);
		visited[src]=1;
		
		for(int v=0;v<N;v++)
			if(map[src][v] && !visited[v] && dist[v]>map[src][v])
				dist[v] = map[src][v], parent[v]=src;
	}
	cout<<"\nPrinting prims MST : ";
	for(int i=1;i<N;i++)
		cout<<"\nEdge "<<parent[i]<<" -> "<<i<<" weight :  "<<map[parent[i]][i];
}

int main(){
	freopen("input_prims.txt","r",stdin);
	int N;
	cin>>N;
	int **graph = new int*[N];
	for(int i=0;i<N;i++){
		graph[i] = new int[N];
		for(int j=0;j<N;j++)
			cin>>graph[i][j];
	}
	cout<<"\nInput taken, going for processsing";
	prims(graph,N);
	cout<<endl;
	return 0;
}
