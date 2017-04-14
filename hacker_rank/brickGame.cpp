/* 

	Author : Siddheshwar P Sharma
	Date     : 29th Oct 2016
	Link     : https://www.hackerrank.com/challenges/play-game
	input   : input_brickGame.txt
	
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int T, N;
int *visited;
int max_score;
int find_max(int a, int b)
{
	return a>b ? a:b;
}


void print()
{
	cout<<endl;
	for(int i=0;i<N;i++)
		cout<<visited[i]<<" ";
	cout<<endl;
}

void solve(int *a, int sum1, int turn, int pos)
{
		cout<<"\nPos : "<<pos <<" sum : "<<sum1<<" turn "<<turn;

		if(pos > N-1)
		{
			print();
			cout<<"\nsum "<<sum1;
		}
		for(int i=pos; i<N; i++)
		{
			if(turn)
			{
				visited[i]=1;
				solve(a, sum1+a[i], !turn, i+1);
				visited[i+1]=1;
				solve(a, sum1+a[i]+a[i+1], !turn, i+2);
				visited[i+2]=1;
				solve(a, sum1+a[i]+a[i+1]+a[i+2], !turn, i+3);
				visited[i]=0;
				visited[i+1]=0;
				visited[i+2]=0;
			}
			else
			{
				solve(a, sum1, !turn, i+1);
				solve(a, sum1, !turn, i+2);
				solve(a, sum1, !turn, i+3);
			}
		}
		max_score = find_max(max_score, sum1);
}

int main()
{
	freopen("input_brickGame.txt","r",stdin);
	cin>>T;
	for(int c=0; c < T; c++)
	{
		cin>>N;
		int *brick = new int[N+3];
		visited = new int[N];
		for(int i=0;i<N;i++){
			cin>>brick[i];
			visited[i]=0;
		}
		brick[N] = 0;
		brick[N+1] = 0;
		brick[N+2] = 0;
		max_score = -1;
		solve(brick, 0, 1, 0);
		cout<<"# "<<c<<" : "<<max_score;
	}
	return 0;
}