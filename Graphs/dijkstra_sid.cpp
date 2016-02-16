/* 

Author : Siddheshwar P Sharma
Date   : 16th Feb 2016

*/

/// code for single pair shortest path [Dijkstra Algorithm]

#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int getMinDist(int *temp, int *visited, int N){
	int pos=0;
	int min = INT_MAX;
	for(int i=0; i<N; i++)
		if(!visited[i] && temp[i]>min)
			min=temp[i], pos=i;
	return pos;
}

void dijkstra(int **g, int N){
	int temp[N];
	int visited[N];
	for(int i=0; i<N; i++)
		temp[i]=INT_MAX,visited[i]=0;
	temp[0]=0;
	for(int i=0;i<N-1;i++){
		int u = getMinDist(temp, visited, N);
		visited[u]=1;
		for(int v=0;v<N;v++){
			if(!visited[v] && g[u][v]!=0 && temp[u]!=INT_MAX && temp[v]>temp[u]+g[u][v])
				temp[v]=temp[u]+g[u][v];
		}
	}
	cout<<endl;
	for(int i=0;i<N;i++)
		cout<<((temp[i]!=INT_MAX)?temp[i]:-1)<<" ";
}

int main(){
	freopen("input_dijkstra.txt","r",stdin);
	int N;
	cin>>N;
	int **graph = new int*[N];
	for(int i=0; i<N; i++){
		graph[i] = new int[N];
		for(int j=0; j<N; j++)
			cin>>graph[i][j];
	}
	dijkstra(graph,N);
	cout<<endl;
	return 0;
}
