/*

	Author  : Siddheshwar P Sharma
	Date    : 18th May 2016
	input   : input_2xn.txt
	
*/

#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int map[500][500];
int visited[500][500];
int T, N;
int minjump;

void print(int a[][500])
{
	for(int i=0; i<N; i++)
	{
		cout<<endl;
		for(int j=0; j<N; j++)
			cout<<a[i][j]<<" ";
	}
	cout<<endl;
}

void find(int i, int j, int jump)
{

	if(i < 0 || i >= N || j < 0 || j >= N)
		return;
	if(jump > minjump)
		return;
	cout<<"\n"<<i<<" "<<j;
	if(map[i][j] == 3)
	{
		visited[i][j] = 0;
		if(jump < minjump)
		{
			minjump = jump;
			print(visited);
			
		}
		return ;
	}	
	if(i > 0 && !visited[i-1][j])
	{
		visited[i-1][j] = 1;
		if(map[i-1][j] == 0)
			find(i-1, j, jump+1);
		else
			find(i-1, j, 0);
		//visited[i-1][j] = 0;
	}

	if(i<N-1 && !visited[i+1][j])
	{
		visited[i+1][j] = 1;
		if(map[i+1][j] == 0)
			find(i+1, j, jump+1);
		else
			find(i+1, j, 0);
		//visited[i+1][j] = 0;
	}
	
	if(j>0 && map[i][j-1] && !visited[i][j-1])
	{
		visited[i][j-1] = 1;
		find(i, j-1, jump);
		//visited[i][j-1] = 0;
	}

	if(j<N-1 && map[i][j+1])
	{
		visited[i][j+1] = 1;
		find(i, j+1, jump);
		//visited[i][j+1] = 0;
	}
	
}

int main()
{
	int posx, posy;
	freopen("input_2xn.txt","r",stdin);
	cin>>T;
	for(int test=1;test<=T;test++)
	{
		cin>>N;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			{
				cin>>map[i][j];
				if(map[i][j] == 2)
					posx = j, posy = i;
			}
		minjump = INT_MAX;
		find(posy, posx,0);
		cout<<"\n# "<<test<<" : "<<minjump;
	}	
	return 0;
}
