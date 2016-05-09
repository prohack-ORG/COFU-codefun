/*

	Author : Siddheshwar P Sharma
	Date   : 10 May 2016
	input  : input_fastRobot.txt

*/

#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

int maze[200][200];
int visited[200][200];
int turn[200][200];
int T, N, M;
int Ex, Ey;
// M : number of rows	 : height
// N : number of columns : width

void print(int a[][200], int m, int n)
{
	for(int i=0;i<m;i++)
	{
		cout<<endl;
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
	}
	cout<<endl;
}


void fast(int sx, int sy, int prv, int turn_count)
{
	if(sx<0 || sy<0 || sx>N-1 || sy> N-1)
		return;
	if(visited[sx][sy] || maze[sx][sy])
		return;
	cout<<"\nAt "<<sy<<" "<<sx<<" "<<" "<<prv<<" "<<turn_count;
	turn[sx][sy] == turn[sx][sy] > turn_count ? turn_count : turn[sx][sy];
	visited[sx][sy]=1;
	if(sx == Ey-1 && sy == Ex-1)
	{
		print(visited,M,N);
		visited[sx][sy]=0;
		return;
	}
	if(prv == 0)
	{
		fast(sx-1,sy,1,0);
		fast(sx+1,sy,1,0);
		fast(sx,sy-1,2,0);
		fast(sx,sy+1,2,0);
	}
	else if(prv==1)
	{
		fast(sx-1,sy,1,turn_count);
		fast(sx+1,sy,1,turn_count);
		fast(sx,sy-1,2,turn_count+1);
		fast(sx,sy+1,2,turn_count+1);
	}
	else if(prv==2)
	{
		fast(sx-1,sy,1,turn_count+1);
		fast(sx+1,sy,1,turn_count+1);
		fast(sx,sy-1,2,turn_count);
		fast(sx,sy+1,2,turn_count);
	}
	visited[sx][sy]=0;
}

int main()
{
	char ch;
	freopen("input_fastRobot.txt","r",stdin);
	cin>>T;
	int sx,sy;
	for(int test=1;  test<=T; test++)
	{
		cin>>N>>M;
		cin>>sx>>sy>>Ex>>Ey;
		cout<<"\n"<<N<<" "<<M<<" "<<sx<<" "<<sy<<" "<<Ex<<" "<<Ey;
		cout<<"\nInput matrix :\n";
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
			{
				cin>>ch;
				maze[i][j] = ch - '0';
				turn[i][j] = INT_MAX;
			}
		print(maze,M,N);
		fast(sy-1, sx-1, 0, 0);
		print(turn,M,N);
		cout<<"\n#"<<test<<" : "<<turn[Ey-1][Ex-1]<<endl;
	}
	return 0;
}
