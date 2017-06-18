/*
*	@uthor: raman
*       Funtionality: Count total number of paths in directed acyclic graph 
*
*/
#include<iostream>
#include<stdio.h>

using namespace std;

#define DEBUG 1

int graph[5000][5000],visited[5000],indegree[5000],outdegree[5000];
int MEMO[5000];
int count;

void Debug(int N)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            cout<<" "<<graph[i][j]; cout<<endl;
    }
    cout<<"\n INDEGREE\n";   
    for(i=0;i<N;i++)
        cout<<" "<<indegree[i];
    cout<<"\n OUTDEGREE\n";
    for(i=0;i<N;i++)
        cout<<" "<<outdegree[i];

    cout<<"\n Visited\n";       
    for(i=0;i<N;i++)
        cout<<" "<<visited[i];

    cout<<"\n MEMO \n";
    for(i=0;i<N;i++)
        cout<<" "<<MEMO[i];
}

int findIndexDegree(int N)
{
    int i;
    for(i=0;i<N;i++)
        if(!indegree[i]) {
            indegree[i]=-1;
            return i;
        }
    return -1;   
}

int callDFS(int start,int N)
{
    int i,count1=0;
#if DEBUG
    cout<<"\ncalling for index:"<<start+1<<"\tcount : "<<count1; 
#endif
    if(visited[start])
    {
        return 0;
    }
    if(MEMO[start]!=-1) 
    {
#if DEBUG
        cout<<"\nusing val from index:"<<start+1<<"\tcount : "<<count1<<"\tMEMO["<<start+1<<"] :"<<MEMO[start]; 
#endif
        return MEMO[start];    
    }
    if(!outdegree[start]) 
    {
               MEMO[start]=1;
#if DEBUG
        cout<<"\nreturn from index:"<<start+1<<"\tcount : "<<count1<<"\tMEMO["<<start+1<<"] :"<<MEMO[start]; 
#endif
        return MEMO[start];
    }

    visited[start]=1,count1=0;
    for(i=0;i<N;i++)
    {
        if(graph[start][i]  && !visited[i])
        {
           count1+=callDFS(i,N);
           
        }
    }   
    MEMO[start]=count1;
#if DEBUG
        cout<<"\n\tstoring val for index:"<<start+1<<"\t\tMEMO["<<start+1<<"] :"<<count1; 
#endif
    visited[start]=0,count1=0;
    return MEMO[start];
}

int main()
{
    int T;
    freopen("input_BusRoute.txt", "r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        int N,M;
        int i,j;
        scanf("%d%d",&N,&M);
        for(i=0;i<N;i++)
        {
            visited[i]=0,indegree[i]=0,outdegree[i]=0,MEMO[i]=-1;
            for(j=0;j<N;j++)
                graph[i][j]=0;
        }
        for(i=0;i<M;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            graph[a-1][b-1]=1; indegree[b-1]+=1; outdegree[a-1]+=1;    
        }
        //        Debug(N);
        count=0;
        int answer=0;
        while(true)
        {
            int index=findIndexDegree(N);
            if(index==-1) 
                break;
           answer+=callDFS(index,N);

        }        
        printf("\n%d\n",answer);
    }
    return 0;
}


