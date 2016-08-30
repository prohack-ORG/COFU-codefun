#include <iostream> 
#include <stdio.h>

using namespace std;

int T, N;
int M;
int D[10];
int x[10];
long count;

void print()
{
	for(int i=0;i<N;i++)
		cout<<x[i]<<" ";
	cout<<" -> ";
}

void travel(int step)
{
	if(step == M)
	{
		count = (count+1)%1000000007;
		return;
	}
	
	for(int i=0;i<N;i++)
	{
		x[i] = x[i]+1;
		if(x[i]<=D[i])
			travel(step+1);

		x[i] = x[i]-2;

		if(x[i]>0)
			travel(step+1);
		x[i] = x[i]+1;
	}
}

int main() 
{
	freopen("input_gridWalk.txt","r",stdin);
	cin>>T;
	for(int test = 0; test < T; test++)
	{
        count=0;
		cin>>N>>M;
		for(int i=0;i<N;i++)
			cin>>x[i];
		for(int i=0;i<N;i++)
			cin>>D[i];
		travel(0);
		cout<<count<<endl;
	}
	return 0;
}