/*

Author : Siddheshwar P Sharma
Date   : 16th Feb 2016

*/

///  Floyd Warshall Algorithm using matrix representation of graph

#include <iostream>
#include <stdio.h>

#include <limits.h>

using namespace std;

void print_solution(int **g,int N){

	for(int i=0;i<N;i++){
		cout<<endl;
		for(int j=0;j<N;j++)
			cout<<((g[i][j]!=INT_MAX)?g[i][j]:-1)<<" ";
	}
}

void floyd(int **g, int N){
	int **temp;
	temp = new int*[N];
	for(int i=0;i<N;i++){
		temp[i] = new int[N];	
		for(int j=0;j<N;j++)
			temp[i][j] = (g[i][j]==-1)? INT_MAX:g[i][j];
	}
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(temp[i][k]!=INT_MAX && temp[k][j]!=INT_MAX && temp[i][k]+temp[k][j]<temp[i][j])
					temp[i][j]=temp[i][k]+temp[k][j];

	print_solution(temp,N);
}


int main(){
	freopen("input_floyd_warshall.txt","r",stdin);
	int N;
	//cout<<"\nEnter the Number of nodes : ";
	cin>>N;
	int **graph = new int*[N];
	for(int i=0;i<N;i++){
		graph[i] = new int[N];
		for(int j=0;j<N;j++)
			cin>>graph[i][j];
	}
	floyd(graph,N);
	cout<<endl;
	return 0;

}
