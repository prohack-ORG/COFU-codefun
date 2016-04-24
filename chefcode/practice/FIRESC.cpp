/*
 *    FireEsacpae 

 */

#include<iostream>
#include<cstdio>
#define MOD 1000000007
long long int numGroup,Total,count;
int S;
using namespace std;
void DFS(int **graph,int *visited,int i,int N)
{
    if(visited[i]) return;
    visited[i]=1;
    count++;
    for(int k=0;k<N;k++)
    {
        if(graph[i][k] && !visited[k] && S!=k)
            DFS(graph,visited,k,N);
    }        
  return;
}

int main()
{
    int T;
//     freopen("input.txt","r",stdin);
    scanf("%d" ,&T);
    while(T--)
    {
        int N,M;
        scanf("%d%d",&N,&M);
        int i,j;
        int **graph=new int*[N], *visited=new int[N];
        for(i=0;i<N;i++) 
            graph[i]=new int[N];
        for(i=0;i<N;i++){
            visited[i]=0;
            for(j=0;j<N;j++)
                graph[i][j]=0;
        }
        for(i=0;i<M;i++)
        {
        int a,b;
            scanf("%d%d",&a,&b);
            graph[(a-1)][(b-1)]=1;
            graph[(b-1)][(a-1)]=1;
        }
        /* 
           for(i=0;i<N;i++){
           for(j=0;j<N;j++)
           printf("%d ", graph[i][j]); printf("\n");
           }
         */  
        numGroup=0,Total=1,count=0;
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
        delete(graph); delete(visited);    
    }
    return 0;
}

