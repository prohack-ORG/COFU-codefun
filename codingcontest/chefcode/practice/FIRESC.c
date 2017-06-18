/*
 *    FireEsacpae 

 */

#include<stdio.h>
#include<stdlib.h>

#define MOD 1000000007
long long int numGroup=0,Total=0,count=0;
int S=0;
void DFS(int **graph,int *visited,int i,int N)
{
	if(visited[i]) return;
	visited[i]=1;
	count++;int k;
	for(k=0;k<N;k++)
	{
		if(graph[i][k] && !visited[k] && S!=k)
			DFS(graph,visited,k,N);
	}        
	return;
}

int main()
{
	int T;
	freopen("input.txt","r",stdin);
	scanf("%d" ,&T);
	while(T--)
	{
		int N,M;
		scanf("%d%d",&N,&M);
		int i=0,j=0;
		int **graph=(int**)malloc(sizeof(int*)*N) , *visited=(int*) malloc(sizeof(int)*N);
		for(i=0;i<N;i++) 
			graph[i]=(int*)malloc(sizeof(int)*N);

		for(i=0;i<N;i++){
			visited[i]=0;
			for(j=0;j<N;j++)
				graph[i][j]=0;
		}
		for(i=0;i<M;i++)
		{
			int a=0,b=0;
			scanf("%d%d",&a,&b);
			graph[(a-1)][(b-1)]=1;
			graph[(b-1)][(a-1)]=1;
		}

/*		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				printf("%d ", graph[i][j]); printf("\n");
		}
		printf("%d %d \n",N,M);   
*/		numGroup=0,Total=1,count=0;
		for(i=0;i<N;i++)
		{
			if(!visited[i])
			{   S=i;
				DFS(graph,visited,i,N);
				numGroup++, Total=(Total*count)%MOD;
				count=0;
			}
		}    
		printf("%lld %lld\n",numGroup,Total);    

	
		   for(i=0;i<N;i++) free(graph[i]);
		   free(graph); free(visited);    

	}
	return 0;
}

