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

int minimum(int a, int b)
{
	return a> b ? b : a;
}

void fast(int sx, int sy, int prv, int turn_count)
{
	if(visited[sx][sy] || !maze[sx][sy])
		return;
	turn[sx][sy] == minimum(turn[sx][sy],turn_count);
	cout<<"\nAt "<<sy<<" "<<sx;
	visited[sx][sy]=1;
	if(sx == Ex-1 && sy == Ey-1)
	{
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
	freopen("intput_fastRobot.txt","r",stdin);
	cin>>T;
	int sx,sy;
	for(int test=0;  test<=T; test++)
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
			}
		print(maze,M,N);
		fast(sy-1, sx-1, 0, 0);
		cout<<"\n#"<<test<<" : "<<turn[Ey-1][Ex-1]<<endl;
	}
	return 0;
}
