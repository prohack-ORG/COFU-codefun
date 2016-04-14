#include<iostream>
#include<stdio.h>
using namespace std;
int numC,maxS,count;

void DFS(int **SkyMap, int **visited, int sx,int sy,int N)
{
	if(visited[sx][sy] ) return;
	visited[sx][sy]=1;
	count++;
	if(maxS<count) maxS=count;
	
	 cout<<"DFS "<<numC<<" "<<maxS<<" "<<count<<endl;
	if(sx-1>=0 && SkyMap[sx-1][sy]) DFS(SkyMap,visited,sx-1,sy,N);
	if(sx+1<N && SkyMap[sx+1][sy]) DFS(SkyMap,visited,sx+1,sy,N);
	if(sy-1>=0 && SkyMap[sx][sy-1]) DFS(SkyMap,visited,sx,sy-1,N);
	if(sy+1<N && SkyMap[sx][sy+1]) DFS(SkyMap,visited,sx,sy+1,N);
//	count=0;
}

int main()
{
	int T;
	freopen("input.txt","r",stdin);
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int **SkyMap=new int*[N], **visited=new int*[N];
		for(int i=0;i<N;i++)
			SkyMap[i]=new int[N], visited[i]=new int[N];
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				cin>>SkyMap[i][j],visited[i][j]=0;


		numC=0,maxS=0,count=0;

		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			{
				if(SkyMap[i][j] && !visited[i][j]) 
				{	
				//count++;
					DFS(SkyMap,visited,i,j,N);
					numC++;	count=0;	
				}	
			}
	 cout<<numC<<" "<<maxS<<endl;
	}	
return 0;
}

