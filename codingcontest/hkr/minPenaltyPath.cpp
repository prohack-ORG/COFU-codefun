#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <limits.h>
#include <utility>

using namespace std;
int N,M;
int MinimumPenality;

class Graph{

    int V;
    int *path;
    vector<int> *Q;
    vector<pair<int,int> > *adj;

    public:
    Graph(int v);
    void addEdge(int u,int v,int w);
    void printPathLen();
    void printG();
    void printQ();
    int ExtractMinIndex();
    void Solver(int s);
    int getAnswer(int d);
};

int main()
{
    freopen("input/inMinPenalty1.txt","r",stdin);
    int T; cin>>T; 
    while(T--){
        cin>>N>>M;

        Graph g(N);

        int u,v,w;

        for(int i=0;i<M;i++)
        {
            cin>>u>>v>>w;
            g.addEdge(u-1,v-1,w);
        }

        int A,B;
        cin>>A>>B;
        g.printG();
        g.Solver(A);
        cout<<g.getAnswer(B)<<"\n\n";
    } 
    return 0;
}

Graph::Graph(int v)
{
    V=v;
    path=new int[V];

    for(int i=0;i<V;i++)
    {
        path[i]=INT_MAX;
    }

    Q = new vector<int> [V];

    adj=new vector< pair<int,int> > [V];
}    

void  Graph::addEdge(int u,int v,int w)
{
    adj[v].push_back(make_pair(u,w));                
    adj[u].push_back(make_pair(v,w));                
}

void Graph::printPathLen()
{
    for(int i=0;i<V;i++)
        std::cout<<path[i]<<" ";
    std::cout<<"\n\n";
}

void Graph::printQ()
{
    for(int i=0;i<V;i++)
    {
        std::cout<<"["<<i+1<<"] ::-> { ";
        for(vector<int >::iterator itr=Q[i].begin(); itr != Q[i].end(); ++itr)
        {
            std::cout<<*itr<<" ,";
        } 
        std::cout<<" }\n"; 
    }   
    cout<<"\n------------------------------------------------------------------------\n";
}

void Graph::printG()
{
    for(int i=0;i<V;i++)
    {
        std::cout<<"["<<i+1<<"] ::";
        for(vector<pair<int ,int > >::iterator itr=adj[i].begin(); itr != adj[i].end(); ++itr)
        {
            std::cout<<"-> "<<itr->first+1<<"("<<itr->second<<")";
        } 
        std::cout<<"\n"; 
    }
    cout<<"\n";   
}

int Graph::ExtractMinIndex()
{
    int mini=INT_MAX;
    int in=-1;
    for(int i=0;i<V;i++)
    {
        for(std::vector<int>::iterator itr=Q[i].begin(); itr!=Q[i].end(); ++itr)
        {
            if(mini>*itr)
                mini=*itr, in=i;
        }
    }
    return in;
}

void Graph::Solver(int s)
{
    path[s-1]=0;
    Q[s-1].push_back(0);
    int count=1;
    while(count>0)
    {
        printQ();
        printPathLen();
        int index= ExtractMinIndex();
        if (index==-1) break;
        for(vector<int>::iterator it1=Q[index].begin(); it1 !=Q[index].end(); ++it1)
        {

            for(vector<pair<int,int> >::iterator it2=adj[index].begin(); it2!=adj[index].end(); ++it2)
            {
                int or1= *it1 | it2->second;

                count++;
                if(path[it2->first] > or1)
                {
                    path[it2->first]=or1;
                    Q[it2->first].push_back(or1);
                }   
            }         
        }
        count-=Q[index].size();
        Q[index].clear();
    }


}

int Graph::getAnswer(int d)
{
    return path[d-1];
}


