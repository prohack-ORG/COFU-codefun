#include<iostream>
#include<stdio.h>
#include<list>

using namespace std;

struct pair{
    int ver;
    int wieght;
};
class Graph
{
    private:
        int V;
        int **S;
        list<struct pair> *adj;
    public:
        Graph(int v)
        {
       
            V=v;
            int **S=new int*[v];
             for(int i=0;i<v;i++) 
             {
                 S[i]=new int[2];
                 S[i][0]=0, S[i][1]=-1;
             }
             adj=new list<struct pair>[v];
        }

        void addEdge(int u,int v,int w)
        {
            struct pair p;
            p.ver=v; p.wieght=w;
            adj[u].push_back(p);
            p.ver=u; 
            adj[v].push_back(p);
        }
        
        void print()
        {
            for(int i=0;i<V;i++)
            {   cout<<i<<" -> ";
                list<struct pair>::iterator itr;
                for(itr=adj[i].begin();itr!=adj[i].end();++itr)
                {
                    cout<<"["<<itr->ver<<", "<<itr->wieght<<"] ->";
                }
            }
            cout<<endl;
            for(int i=0;i<V;i++)
            {
                cout<<S[i][0]<<" : "<<S[i][1];
            }
            cout<<endl;
        }
        
        bool DFS()
        {
        
        
        }

};


int main()
{

    int T;
    freopen("input.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        int N,R,M;
       
        Graph G(N);
        for(int i=0;i<R;i++)
        {
            int a,b;
            cin>>a>>b;
            addEdge(a,b,1);
        }
        for(int i=0;i<M;i++)
        {
            int k,st;
            cin>>k>>st;
            S[k-1][0]=1; S[k-1][1]=st;
        }


        G.print();
    }

return 0;
}
