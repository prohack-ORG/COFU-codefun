#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;

int n,m;

int recur(int **map, int *numC, int *v, int *setI,int index)
{
  cout<<"In["<<index;cout<<"]:: v: ";for(int i=1;i<=n;i++)cout<<v[i]<<" "; cout<<" setI: ";for(int i=1;i<=n;i++)cout<<setI[i]<<" ";cout<<endl;
    v[index]=1;
    int min=-1;
    for(int i=1;i<=n;i++)
    {
        if(map[index][i] && setI[index] && !v[i])
        {
            int a=numC[i]+recur(map,numC,v,setI,i);    
            min=min>a?min:a;  
            setI[i]=1;  
            int b=recur(map,numC,v,setI,i);
            setI[i]=0;
            min=min>b?min:b;  
        }
        else if(map[index][i] && !setI[index] && !v[i])
        {
            setI[i]=1;  
            int b=recur(map,numC,v,setI,i);
            setI[i]=0;
            min=min>b?min:b; 
        }
    }
    cout<<" \n returning max : "<<min<<endl;
    v[index]=0;
    return min;
}
int wrapper(int **map,int *numC,int *v,int *setI)
{
 int max=-1;   
 for(int i=1;i<=n;i++)
    {
        int a=numC[i]+recur(map,numC,v,setI,i);
        setI[i]=1;
        int b=recur(map,numC,v,setI,i);
        setI[i]=0;
        max=max>a?max:a;
        max=max>b?max:b;    
    }
  return max;
}
int main()
{
    freopen("input/inPG.txt","r",stdin);
    cin>>n>>m;
    int *numC=new int[n+1];
    int **map= new int*[n+1];
    int *setI=new int[n+1];
    int *v=new int[n+1];
    for(int i=0;i<=n;i++)
        map[i]=new int[n+1];

    for(int i=1;i<=n;i++)
        cin>>numC[i];

    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            map[i][j]=0;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        map[a][b]=1; map[b][a]=1;     
    }
    cout<<"\n numCitizen : ";for(int i=1;i<=n;i++)cout<<numC[i]<<" ";
    cout<<"\n visited : ";for(int i=1;i<=n;i++)cout<<v[i]<<" ";
    cout<<"\n setIgnored : ";for(int i=1;i<=n;i++)cout<<setI[i]<<" ";cout<<endl;
    cout<<"\nMAP:\n";for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) cout<<map[i][j]<<" ";cout<<endl;}
   
    int min=-1;
    min=wrapper(map,numC,v,setI);
    cout<<min<<endl;
    return 0;
}
