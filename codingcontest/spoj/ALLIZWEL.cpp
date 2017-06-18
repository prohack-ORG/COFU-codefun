#include<iostream>
#include<stdio.h>
#include<list>
#include<utility>

using namespace std;

class SolverAllIzzWell
{
    private:
        int R;
        int C;
        char **MAT;
        bool **visited;
        char const *arr;
        list<pair<int,int> > indexArray;
    public:
        SolverAllIzzWell(int r,int c)
        {
            R=c;
            C=r;
            MAT=new char*[C];
            visited=new bool*[C];
            arr="ALLIZZWELL";
            for(int i=0;i<C;i++)
            {
                MAT[i]=new char[R];
                visited[i]=new bool[R];
                for(int j=0;j<R;j++)
                { 
                    cin>>MAT[i][j],visited[i][j]=false;
                    if(MAT[i][j]=='A') 
                        indexArray.push_back(make_pair(i,j));
                }
            }
        }        
        void print()
        {
//            cout<<"\nR: "<<R<<" C: "<<C<<endl;
            for(int i=0;i<C;i++)
            { 
                cout<<endl;
                for(int j=0;j<R;j++)
                    cout<<MAT[i][j]<<" ";
            }
            cout<<endl;
            
            for(int i=0;i<10;i++) cout<<arr[i]<<" ";

            cout<<endl;
/*            list<pair<int,int> >::iterator itr;
            for(itr=indexArray.begin(); itr!=indexArray.end(); ++itr)
            cout<<"\n MAT["<<itr->first<<"]["<<itr->second<<"] = "<<MAT[itr->first][itr->second]<<endl;
*/
            
        }
        bool DFSutils()
        {
            bool flag=false;int count;
            list<pair<int,int> >::iterator itr;
            for(itr=indexArray.begin(); itr!=indexArray.end(); ++itr)
            {
                count=0;
                if(DFS(itr->first,itr->second,count))
                {
                    flag=true; break;
                }
            }
            return flag;
        }
        bool safe(int x,int y,int count)
        {
            if(x<C && x>=0 && y<R && y>=0 && !visited[x][y] && (MAT[x][y]==arr[count]) ) return true; return false; 
        }
        
        bool DFS(int x,int y,int count)
        {
            if(count==9) return true;
            
            visited[x][y]=true;
            if(safe(x-1,y-1,count+1) && DFS(x-1,y-1,count+1)) return true;
            if(safe(x-1, y ,count+1) && DFS(x-1,y  ,count+1)) return true;
            if(safe(x-1,y+1,count+1) && DFS(x-1,y+1,count+1)) return true;
            if(safe(x  ,y-1,count+1) && DFS(x,  y-1,count+1)) return true;
            if(safe(x  ,y+1,count+1) && DFS(x,  y+1,count+1)) return true;
            if(safe(x+1,y-1,count+1) && DFS(x+1,y-1,count+1)) return true;
            if(safe(x+1, y ,count+1) && DFS(x+1,y  ,count+1)) return true;
            if(safe(x+1,y+1,count+1) && DFS(x+1,y+1,count+1)) return true;
            visited[x][y]=false; 
            return false;
                
        }      


};

int main()
{
    int T,R,C;
//    freopen("ALLIZWEL.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>R>>C;
        SolverAllIzzWell S(R,C);
    //    S.print();
        if(S.DFSutils()) cout<<"YES\n\n";
        else cout<<"NO\n\n";
    }
return 0;
}
