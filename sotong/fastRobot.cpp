#include<iostream>
#include<stdio.h>
#include<list>
#include<limits.h>

using namespace std;
#define XDIR 1
#define YDIR 2
#define MAX 55 

int MAZE[200][200];
int visited[200][200];
int w,h;
int countIndex;
void print(int a[][200])
{
    for(int i=0;i<h;i++)
    {
        cout<<endl;
        for(int j=0;j<w;j++)
            cout<<a[i][j];
    }
    cout<<endl;
}        
int* extractMin(int **arr)
{
    int mini=MAX; 
    int *index=new int[2];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        {
            if(!visited[i][j] && !MAZE[i][j] && mini>arr[i*w+j][0])
               {
		 mini=arr[i*w+j][0];
		 index[0]=i;
		index[1]=j;
		}
        }
    return index;
}

bool safe(int i,int j)
{
    if(i<h && i>=0 && j<w && j>=0 && !MAZE[i][j] && !visited[i][j])
return true;
    return false;
}    

int callDijkstra(int x1,int y1,int x2,int y2)
{
    int **pqArray=new int*[w*h];
    for(int i=0;i<w*h;i++)
    {
        pqArray[i]=new int[2];
        pqArray[i][0]=MAX, pqArray[i][1]=-1;
    }
    pqArray[x1*w+y1][0]=0;
    int count=0;
    while(count!=countIndex-1)
    {
        count++;
        int *in=new int[2];
	in=extractMin(pqArray);
        visited[in[0]][in[1]]=1;
        int dir=pqArray[in[0]*w+in[1]][1];
//	cout<<"\n calling for : "<<in[0]<<" "<<in[1]<<" dir : "<<dir;
        int temp=in[0]*w+in[1];
        if(safe(in[0]-1,in[1]))
        {
            if(dir==-1 || dir==XDIR)
            if((pqArray[(in[0]-1)*w+in[1]][0])>pqArray[temp][0]) 
                pqArray[(in[0]-1)*w+in[1]][0]=pqArray[temp][0], pqArray[(in[0]-1)*w+in[1]][1]=XDIR;
            if(dir==YDIR && pqArray[(in[0]-1)*w+in[1]][0]>pqArray[temp][0]+1) 
                pqArray[(in[0]-1)*w+in[1]][0]=pqArray[temp][0]+1, pqArray[(in[0]-1)*w+in[1]][1]=XDIR;
        }
   
	if(safe(in[0]+1,in[1]))
        {
            if(dir==-1 || dir==XDIR)
            if ((pqArray[(in[0]+1)*w+in[1]][0])>pqArray[temp][0]) 
                pqArray[(in[0]+1)*w+in[1]][0]=pqArray[temp][0], pqArray[(in[0]+1)*w+in[1]][1]=XDIR;
            if(dir==YDIR && pqArray [ (in[0]+1)*w+in[1] ][0]>=(pqArray[temp][0]+1)) 
                pqArray[(in[0]+1)*w+in[1]][0]=pqArray[temp][0]+1;
		 pqArray[(in[0]+1)*w+in[1]][1]=XDIR;
}
        if(safe(in[0],in[1]-1))
        {
            if(dir==-1 || dir==YDIR)
            if((pqArray[in[0]*w+in[1]-1][0])>pqArray[temp][0]) 
                pqArray[in[0]*w+in[1]-1][0]=pqArray[temp][0], pqArray[in[0]*w+in[1]-1][1]=YDIR;
            if(dir==XDIR && pqArray[in[0]*w+in[1]-1][0]>(pqArray[temp][0]+1)) 
                pqArray[in[0]*w+in[1]-1][0]=pqArray[temp][0]+1, pqArray[in[0]*w+in[1]-1][1]=YDIR;
        }

        if(safe(in[0],in[1]+1))
        {
            if(dir==-1 || dir==YDIR)
            if((pqArray[in[0]*w+in[1]+1][0])>pqArray[temp][0]) 
                pqArray[in[0]*w+in[1]+1][0]=pqArray[temp][0], pqArray[in[0]*w+in[1]+1][1]=YDIR;
            if(dir==XDIR && pqArray[in[0]*w+in[1]+1][0]>(pqArray[temp][0]+1)) 
                pqArray[in[0]*w+in[1]+1][0]=pqArray[temp][0]+1, pqArray[in[0]*w+in[1]+1][1]=YDIR;
        }
    
    }
print(visited);
return pqArray[x2*w+y2][0];
}
int main()
{
    int T;
    freopen("input_fastRobot.txt","r",stdin);	
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&w,&h);
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
            { 
                char ch;
                cin>>ch;
                MAZE[i][j]=ch-'0';visited[i][j]=0;
                if(ch=='0') countIndex++;
            }
//        print(MAZE);
        cout<<callDijkstra(y1-1,x1-1,y2-1,x2-1)<<endl; 

    }
return 0;

}

