/*

	Author : Siddheshwar P Sharma
	Date   : 14th April 2016
	input  : input_skymap.txt

*/

#include <iostream>
#include <limits.h>
#include <stdio.h>
using namespace std;

#define DEBUG_LOG 0


int num_con, max_star=INT_MIN, count;
int **visited;
void spread(int **map, int **visited, int n, int i, int j)
{
    if(i<0||j<0||i>n-1||j>n-1)	
		return;
	if(map[i][j]==0||visited[i][j])
		return;
	//cout<<endl<<i<<" "<<j;
	visited[i][j]=1;
	count++;
	//cout<<"incrementing count : "<<count;
	if(i>0 && map[i-1][j] && !visited[i-1][j])
		spread(map, visited, n, i-1, j);
	if(i<n-1 && map[i+1][j] && !visited[i+1][j])
		spread(map, visited, n, i+1, j);
	if(j>0 && map[i][j-1] && !visited[i][j-1])
		spread(map, visited, n, i, j-1);
	if(j<n-1 && map[i][j+1] && !visited[i][j+1]);
		spread(map, visited, n, i, j+1);
	return;
}

void findmap(int **map, int **visited, int n)
{
	//cout<<"\n In findmap "<<n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			//cout<<"\n***************************************************************"<<i<<" "<<j;
			if(map[i][j] && !visited[i][j])
			{
				//cout<<"\n---------------------------------------------------------------"<<i<<" "<<j;
				count=0;
				spread(map, visited, n, i, j);
				num_con++;
				//cout<<"\nprev max_star = "<<max_star;
				max_star = max_star > count ? max_star : count;
				//cout<<"\nNow max_star = "<<max_star<<" count : "<<count;
			}
		}
}

int main()
{
	int cases,n;
	freopen("input_skymap.txt","r",stdin);
	cin>>cases;
	for(int i=0;i<cases;i++)
	{
		cin>>n;
		int **map = new int*[n];
		visited = new int*[n];
		max_star=0;
		num_con=0;
		for(int j=0;j<n;j++)
		{
			map[j] = new int[n];
			visited[j] = new int[n];
			for(int k=0;k<n;k++)
				cin>>map[j][k], visited[j][k]=0;
		}
#if DEBUG_LOG
		for(int j=0;j<n;j++)
		{
			cout<<endl;
			for(int k=0;k<n;k++)
				cout<<map[j][k]<<" ";
		}
#endif
		findmap(map,visited,n);
		cout<<endl<<num_con<<" "<<max_star;
	}
	cout<<endl;
	return 0;
}

