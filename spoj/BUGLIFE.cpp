#include<iostream>
#include<stdio.h>
#include<list>

using namespace std;

class Solver
{
    private:
        int V;
        list<int> *adj;
        int *color;
    public:
        Solver(int v);
        void print();
        void addEdge(int u,int v);
        bool DFSutils();
        bool DFS(int x,int prev);
};

int main()
{
    int T,N,E;
//    freopen("BUGLIFE.txt","r",stdin);
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>N>>E;
        Solver S(N);
        for(int i=0;i<E;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            S.addEdge(a-1,b-1);
        }
        //        S.print();
        if(S.DFSutils()) printf("Scenario #%d:\nSuspicious bugs found!\n",t);
        else   printf("Scenario #%d:\nNo suspicious bugs found!\n",t);
        //        S.print();
    }
    return 0;
}

bool Solver::DFS(int x,int prev)
{
//    printf("\n %s %d %d ",__func__,x+1,prev+1);
    if(color[x]!=-1 && color[x]==color[prev]) return true;
    if(color[x]!=-1 && color[x]!=color[prev]) return false;
    if(color[prev]==-1 || color[prev]==0) 
        color[x]=1;
    else if(color[prev]==1)
        color[x]=0;

//    cout<<endl; for(int k=0;k<V;k++) cout<<color[k]<<" "; cout<<endl;

    list<int>::iterator itr;

    for(itr=adj[x].begin(); itr!=adj[x].end(); ++itr)
    {
  //      cout<<" curr= "<<*itr+1<<" prev: "<<x+1<<endl;
        if(*itr!=prev)
        {
            if(DFS(*itr,x))            
            {
//                cout<<"\n return true at "<<x+1<<endl;
                return true;
            }
        }
    }
//    cout<<"\n return false at "<<x+1<<endl;
    return false;
}
bool Solver::DFSutils()
{
    bool flag=false;
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1 && DFS(i,i))
        {
            return true;
        }
    }
    return false;
}
void Solver::print()
{
    for(int i=0;i<V;i++)
    {
        cout<<"\n["<<i+1<<"] : ";
        list<int>::iterator itr;
        for(itr=adj[i].begin();itr!=adj[i].end();++itr)
            cout<<" ->"<<*itr+1;
    }
    cout<<endl;
    for(int i=0;i<V;i++)
        cout<<color[i]<<" "; cout<<endl;
}
Solver::Solver(int v)
{
    V=v;
    adj=new list<int>[V];
    color=new int[V];
    for(int i=0;i<V;i++)
        color[i]=-1;
}
void Solver::addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
