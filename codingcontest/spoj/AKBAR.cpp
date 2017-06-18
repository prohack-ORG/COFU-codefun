#include<iostream>
#include<stdio.h>
#include<list>
#include<utility>
using namespace std;

class Graph
{
    private:
        int V;
        int GC;
        int **S;
        int *visited;
        list<pair<int,int> > *adj;
    public:
        Graph(int v)
        {
            this->V=v;
            this->GC=0;
            S=new int*[v];
            visited=new int[v];
             for(int i=0;i<v;i++) 
             {
                 visited[i]=-1;
                 S[i]=new int[2];
                 S[i][0]=0, S[i][1]=-1;
             }
             adj=new list< pair<int,int> > [v];
        }

        void addEdge(int u,int v,int w)
        {
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        void initStrength(int k,int s)
        {
            S[k][0]=1; S[k][1]=s;
        }        
        void print()
        {
            for(int i=0;i<this->V;i++)
            {  
                cout<<"\n"<<i+1<<" -> ";
                list<pair<int,int> >::iterator itr;
                for(itr=adj[i].begin();itr!=adj[i].end();++itr)
                {
                    cout<<"["<<itr->first+1<<", "<<itr->second<<"] ->";
                }
            }
            cout<<endl;
            for(int i=0;i<this->V;i++)
            {
                cout<<i+1<<"-> "<<S[i][0]<<":"<<S[i][1]<<endl;
            }
            cout<<endl;
        }
        
        bool DFS(int source,int count,int &gc)
        {
   //         printf("\n S____________ %s %d %d \n" ,__func__,source+1,count); 
            if(count<0) return true;
         //   if(visited[source]>count-1) return false;
            if(visited[source]==-1) gc++;
            visited[source]=count;
            list<pair<int,int> >::iterator itr;
            bool flag=true;
            for(itr=adj[source].begin(); itr!=adj[source].end(); ++itr)
            {
                if(count>0 && visited[itr->first]<(count-1) )
                {
                    if(S[itr->first][1]!=-1)
                    {
                        flag=false; break;
                    }
                    if(DFS(itr->first,count-1,gc))
                    {
                        
                        flag=true;
                    }
                }
            }
          return flag;  
        }
        bool DFSutils()
        {
            bool flag=true;
            for(int i=0;i<V;i++)
                if(S[i][0])
                {
                   
                    if(!DFS(i,S[i][1],GC))
                    {
                        flag=false;
                        break;                    
                    }
                }
            return flag;
        }

        bool allVisited()
        {
            if(GC==V) return true;
            else return false;
        }
};


int main()
{

    int T;
    freopen("AKBAR.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        int N,R,M;
        cin>>N>>R>>M; 
        Graph G(N);
        for(int i=0;i<R;i++)
        {
            int a,b;
            cin>>a>>b;

            G.addEdge(a-1,b-1,1);
        }
        for(int i=0;i<M;i++)
        {
            int k,st;
            cin>>k>>st;
            G.initStrength(k-1,st);
        }
  //      G.print();
        if(G.DFSutils() && G.allVisited() ) cout<<"Yes\n";
        else cout<<"No\n";
    }
        
return 0;
}
