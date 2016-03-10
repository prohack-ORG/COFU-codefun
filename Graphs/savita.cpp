/*

	Author : Siddheshwar P Sharma
	Date   : 10th March 2016
	Link   : https://www.hackerrank.com/contests/w7/challenges/savita-and-friends
	i/p file : input_savita.txt

*/

#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int getMinDist(int *temp, int *visited, int N){
	int pos=0;
	int min = INT_MAX;
	for(int i=0; i<N; i++)
		if(!visited[i] && temp[i]<min)
			min=temp[i], pos=i;
	return pos;
}
void dijkstra(int **g, int *temp, int start_pos, int N){
	int visited[N];
	for(int i=0; i<N; i++)
		temp[i]=INT_MAX,visited[i]=0;
	temp[start_pos]=0;
	for(int i=0;i<N-1;i++){
		int u = getMinDist(temp, visited, N);
		visited[u]=1;
		for(int v=0;v<N;v++){
			if(!visited[v] && g[u][v]!=0 && temp[u]!=INT_MAX && temp[v]>temp[u]+g[u][v])
				temp[v]=temp[u]+g[u][v];
		}
	}
	//cout<<endl;
	for(int i=0;i<N;i++)
	{
		temp[i] = (temp[i]!=INT_MAX)?temp[i]:-1;
		//cout<<temp[i]<<" ";
	}
}

void findP(int **mat, int num_node, int A, int B)
{
	int tempA[num_node], tempB[num_node];
	float fromA, maxLen, temp;
	int maxA=INT_MIN, maxB=INT_MIN;
	dijkstra(mat, tempA, A, num_node);
	dijkstra(mat, tempB, B, num_node);
	for(int i=0; i<num_node ;i++)
	{
		//cout<<endl<<maxA<<" "<<maxB<<endl;
		//if(i == A)// || i == B)
		//	continue;
		if(tempA[i]<tempB[i])
			maxA = (maxA < tempA[i])? tempA[i]:maxA;
		else
			maxB = (maxB < tempB[i])? tempB[i]:maxB;
	}
	//cout<<endl<<maxA<<" "<<maxB<<endl;
	if(mat[A][B]!=tempA[B])
		maxLen = maxA>maxB ? maxA:maxB, temp = maxA>maxB ? 0.0f : maxA+tempA[B];
	else
   		temp = (float(maxA)+float(maxB)+tempA[B])/2.0f - (float)maxA, maxLen = temp + (maxA>maxB ? maxA:maxB);
	fromA = temp < 0 ? 0:temp;
	printf("\n%.5f %.5f",fromA,maxLen);
}

int main()
{
	int T;
	int A,B,C,N,M,K;
	int endA,endB;
	freopen("input_savita.txt","r",stdin);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>N>>M>>K;
		int **graph = new int*[N];
		//cout<<"\n1";
		for(int j=0;j<N;j++)
		{
			graph[j]=new int[N];
			for(int k=0;k<N;k++)
				graph[j][k]=0;
		}
		//cout<<"\n2";
		for(int j=0;j<M;j++)	
		{
			cin>>A>>B>>C;
			graph[A-1][B-1] = C;
			graph[B-1][A-1] = C;	
			if(j == K-1)
				endA = A-1, endB = B-1;
		}
		//cout<<"\n3";
		//cout<<"\n# "<<i<<" ";
		findP(graph,N,endA,endB);
		delete graph;
	}
	cout<<endl;
	return 0;
}
