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
        bool DFSutils()
        {
            bool flag=false;
            for(int i=0;i<V;i++)
            {
                if(color[i]==-1 && DFS(i,-1))
                {
                    flag=true; break;
                }
            }
            return flag;
        }

        bool DFS(int x,int prev)
        {
                              
            if(color[x]!=-1 || prev==-1 || prev==1) 
            color[x]=0,prev=0;
            else color[x]=1,prev=1;
            
            list<int>::iterator itr;
            bool flag=false;
            for(itr=adj[x].begin(); itr!=adj[x].end();++itr)
            {
                if(color[*itr]==color[x]) return true; //bug found
                if(color[*itr]==-1 && !DFS(*itr,prev))
                {
                    flag=false;
                }
            }
            return flag;
        }    
};

int main()
{
    int T,N,E;
    freopen("BUGLIFE.txt","r",stdin);
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>N>>E;
        Solver S(N);
        for(int i=0;i<E;i++)
        {
            int a,b;
           // cin>>a>>b;
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
