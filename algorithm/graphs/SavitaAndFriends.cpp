/*!

https://www.hackerrank.com/challenges/savita-and-friends

 */


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX_INT ~(1<<31)
int getMinimum(int *dist,bool *visited,int N)
{
	int min=MAX_INT,idx;
	for(int i=0;i<N;i++)
		if(!visited[i] && min>dist[i])
			min=dist[i],idx=i;
	return idx;
}

bool AllVisited(bool* visited,int N)
{
	for(int i=0;i<N;i++) 
		if(!visited[i]) return false;
	return true;   
}


void DijkstraAlgo(int **Graph, int sA,int sB,float *output, int N)
{
	printf("\n2  %s",__func__);
	bool *visitedA= new bool [N];
	bool *visitedB= new bool [N];
	int *distA = new int[N];
	int *distB = new int[N];

	printf("\n3  %s",__func__);
	for(int i=0;i<N;i++) 
	{
		visitedA[i]=false,distA[i]=MAX_INT;//,MaximumVia[i]=-1;
		visitedB[i]=false,distB[i]=MAX_INT;//,MaximumVia[i]=-1;
	}
	printf("\n4  %s",__func__);
	distA[sA]=0;
	distB[sB]=0;
	printf("\n4  %s",__func__);
	while(!AllVisited(visitedA,N))
	{
		int indx= getMinimum(distA,visitedA,N);
		visitedA[indx]=true;
		for(int i=0;i<N;i++)
		{
			if(!visitedA[i] && Graph[indx][i] && distA[i]>distA[indx]+Graph[indx][i])
			{
				distA[i]=distA[indx]+Graph[indx][i];
			}
		}

	}
	printf("\n5  %s",__func__);
	while(!AllVisited(visitedB,N))
	{
		int indx= getMinimum(distB,visitedB,N);
		visitedB[indx]=true;
		for(int i=0;i<N;i++)
		{
			if(!visitedB[i] && Graph[indx][i] && distB[i]>distB[indx]+Graph[indx][i])
			{
				distB[i]=distB[indx]+Graph[indx][i];
			}
		}

	}
	printf("\n6  %s",__func__);
	int maxA=0,maxB=0;
	for(int i=0;i<N;i++)
	{
		
		if(i!=sA  || i!=sB)
		{
			if(distA[i]>distB[i]) 
			{
				maxB=maxB>=distB[i]? maxB: distB[i];
			}	
			else if(distA[i]<=distB[i])
			{
				maxA=maxA>=distA[i]? maxA:distA[i];
			}	
		}
	}
	output[0]= (maxA+maxB+Graph[sA][sB])/2-maxA;
	output[1]= Graph[sA][sB]-output[0];
}


int main()
{   
	freopen("input_savita.txt","r",stdin);
	int N,M,K,i,j,sA,sB,A=0,B=0,C=0;
	scanf(" %d %d %d",&N,&M,&K);
	int **Graph=new int*[N];

	for(i=0;i<N;i++) {
		Graph[i]=new int[N];
		memset(Graph[i], 0, sizeof(int)*N);
	}
	//printf("\n0  %s\n",__func__);
	for(i=0;i<M;i++)
	{
		scanf(" %d %d %d",&A,&B,&C);
		printf("\n011  %s  A=%d B=%d C=%d \n",__func__, A,B,C);
		Graph[B-1][A-1]=C;
		Graph[A-1][B-1]=C;
		printf("\n012  %s\n",__func__);
		if(i+1==K) 
		{
			sA=A-1,sB=B-1;
		}	      
	printf("\n02  %s\n",__func__);
	}

	printf("\n1  %s",__func__);

	float *output= new float[2];		
	DijkstraAlgo(Graph, sA, sB,output, N);
	printf("\n%f %f\n",output[0],output[1]);
	return 0;
}





