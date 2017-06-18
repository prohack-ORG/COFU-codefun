#include<iostream>
#include<stdio.h>
#include<list>
#define MOD 1000000007
using namespace std;


long int dogsArray[1001], passArray[1001];
int N,M,S;
struct xy{
	int x;
	int y;
};

void SoccorBFS(int i,int s)
{
	list<struct xy> queue;
	struct xy pair;
	pair.x=s; pair.y=i;
	queue.push_back(pair);

	while(!queue.empty())
	{
		pair=queue.front();
		queue.pop_front();
		if(pair.y==M)
		{
			dogsArray[pair.x]+=1;
			continue;
		}
		if(pair.x+passArray[pair.y]<N)
		{
			struct xy XY;
			XY.x=pair.x+passArray[pair.y];
			XY.y=pair.y+1;
			queue.push_back(XY);
		}
		if(pair.x-passArray[pair.y]>=0)
		{
			struct xy XY;
			XY.x=pair.x-passArray[pair.y];
			XY.y=pair.y+1;
			queue.push_back(XY);
		}
	}
}

void SoccorBacktracking(int i,int s)
{
	if(i==M-1)
	{
		if(s+passArray[i]<N)
			dogsArray[s+passArray[i]]+=1;
		if(s-passArray[i]>=0)
			dogsArray[s-passArray[i]]+=1;
		return;
	}
	if(s+passArray[i]<N)
		SoccorBacktracking(i+1,s+passArray[i]);
	if(s-passArray[i]>=0)
		SoccorBacktracking(i+1,s-passArray[i]);
}

int main()
{
	int T;
//	freopen("input1.txt","r",stdin);
	cin>>T;
	while(T--)
	{
		cin>>N>>M>>S;
		for(int i=0;i<N;i++) dogsArray[i]=0;
		for(int i=0;i<M;i++) cin>>passArray[i];
		SoccorBFS(0,S-1);
//		SoccorBacktracking(0,S-1);
		for(int i=0;i<N;i++) cout<<dogsArray[i]%MOD<<" "; cout<<endl;
	}
return 0;

}
