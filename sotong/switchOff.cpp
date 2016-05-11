/*

	Author : Siddheshwar P Sharma
	Date   : 13th May 2016
	input  : input_switchOff.txt

*/


#include <iostream>
#include<stdio.h>
#include<limits.h>

using namespace std;

int T,R,N;
int position[1001];
int visited[1001][1001][100];
int cost[1001][1001][100];

int absolute(int a)
{
    return a<0 ? (-1)*a : a;
}

int chkvisited(int k, int i, int j, int l)
{
	for(int x=0;x<l;x++)
	{
		if(visited[i][j][x]==k)
			return 0;
	}
	return 1;
}

void switchoff()
{
    int temp;
    int pos;
    int level=1;
    while(level!=N)
    {
	
	for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
		cost[i][j][level] = INT_MAX;
		if(i!=j)
		{	
			int val = INT_MAX;
			for(int k=0;k<N;k++)
			{
                		if(k!=j && k!=i && chkvisited(k,i,j,level))// && cost[k][j][0]!=INT_MAX )//&& cost[i][k][level-1]!=INT_MAX)
				{
//					cout<<"\nlevel : "<<level<<" "<<cost[i][k][level-1]<<" + "<<absolute(position[k]-position[j])<<" * "<<N-level-1;
                			temp = cost[i][k][level-1]+absolute(position[k]-position[j])*(N-level-1);    
                			if(val > temp)
                			{
                			    val = temp;
                			    pos = k;
                			}
				}
			}
			cost[i][j][level] = val;
//			cout<<"\ncost["<<i<<"]["<<j<<"]["<<level<<"] : "<<val;
			visited[i][j][level]=pos;
		}
            }
        }
	level++;
    }	
}

int main()
{
	freopen("input_switchOff.txt","r",stdin);
	cin>>T;
	for(int test=0;test<T;test++)
	{
		cin>>N>>R;
		for(int i=0;i<N;i++)
			cin>>position[i];
        //position[N]=R;
       		for(int i=0;i<N;i++) 
		{
			for(int j=0;j<N;j++)
				cost[i][j][0] = absolute(position[i]-position[j])*(N-1);
			cost[i][i][0]=INT_MAX;
		}
	
        	for(int level = 0;level<N;level++)
			for(int i=0;i<N;i++)
			        for(int j=0;j<N;j++)
					visited[i][j][level]=-1;
		switchoff();
	
	        int maxVal = INT_MAX;
	
		for(int i=0;i<N;i++)
		{
			int temp = INT_MAX;
			for(int j=0;j<N;j++)
				if(cost[i][j][N-2] < temp && i!=j)
					temp = cost[i][j][N-2];
			maxVal = maxVal > temp+absolute(R-position[i])*N? temp+absolute(R-position[i])*N : maxVal;
		}
        
		cout<<"\n#"<<test+1<<" "<<maxVal;
/*	
		cout<<"\n\n----------------------------\n\n";
        	for(int level = 0;level<N;level++)
        	{
			cout<<"\n______ level :"<<level<<" ______";
			for(int i=0;i<N;i++)
        		{
				cout<<"\n";
			        for(int j=0;j<N;j++)
				{
					cout<<cost[i][j][level]<<" ";
				}
			}
    		}
		cout<<endl;
		for(int i=0;i<N;i++)
			cout<<absolute(R-position[i])*N<<" ";
*/	}	
	cout<<endl;
	return 0;
}

