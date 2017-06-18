#include<stdio.h>
#include<iostream>
#include<list>

using namespace std;
#define MOD 1000000007
class Solver
{
    private:
        int V;
        list<int> *adj;
        list<int> *edgeIn;
        bool *visited;
        int *inDegree;
        int *MEMO;
    public:
        Solver(int v);
        void addEdge(int u,int v);
        void print();
        int DAGSolve(int source,int target);
        int extractMin();
}; 


int main()
{
    int T;
//    freopen("KFSTB.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        int V,E,S,T;
        scanf("%d%d%d%d",&V,&E,&S,&T);
        Solver Sl(V);
        for(int i=0;i<E;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            Sl.addEdge(a-1,b-1);
        }
//        Sl.print();
        printf("%d\n",Sl.DAGSolve(S,T));        
    }
    return 0;
}

int Solver::DAGSolve(int source,int target)
{
    int count=0;
    list<int>::iterator itr;
    
    while(count<V)
    {
        count++; 
        int index=extractMin();
        visited[index]=true;
        if(index==source-1)
            MEMO[index]+=1;
        for(itr=edgeIn[index].begin(); itr!=edgeIn[index].end();++itr)
            MEMO[index]=(MEMO[index]+MEMO[*itr])%MOD;
        for(itr=adj[index].begin();itr!=adj[index].end();++itr)
            inDegree[*itr]-=1;
    }
    return MEMO[target-1];

}
int Solver::extractMin()
{
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && inDegree[i]==0)
            return i;
    }
    return -1;

}
Solver::Solver(int v)
{
    V=v;
    adj=new list<int>[V];
    edgeIn=new list<int>[V];
    inDegree=new int[V];
    MEMO=new int[V];
    visited=new bool[V];
    for(int i=0;i<V;i++) inDegree[i]=0,MEMO[i]=0,visited[i]=false;

}

void Solver::addEdge(int u,int v)
{
    adj[u].push_back(v);
    edgeIn[v].push_back(u);
    inDegree[v]+=1;
}

void Solver::print()
{
    for(int i=0;i<V;i++)
    {
        printf("\n[%d]: ",i+1);
        list<int>::iterator itr;
        for(itr=adj[i].begin(); itr!=adj[i].end(); ++itr)
        {
            printf(" ->%d",*itr+1);
        }
    }
    printf("\nEdgeIncdence");
    for(int i=0;i<V;i++)
    {
        printf("\n[%d]: ",i+1);
        list<int>::iterator itr;
        for(itr=edgeIn[i].begin(); itr!=edgeIn[i].end(); ++itr)
        {
            printf(" ->%d",*itr+1);
        }
    }
    printf("\n");
    for(int i=0;i<V;i++)
        printf("%d ",inDegree[i]); printf("\n\n");
    for(int i=0;i<V;i++)
        printf("%d ",MEMO[i]); printf("\n\n");
}
