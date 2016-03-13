/*

	Author : Siddheshwar P Sharma
	Date   : 13th March 2016
	Link   : https://www.hackerrank.com/challenges/coin-change
	input  : input_coinChange.txt

*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int count;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void findCombination_forSum(int N, int *arr, int M, int sum, int start,int level)
{
	for(int i=start;i<M;i++)
	{
		//cout<<endl<<"checeking : "<<arr[i];
		sum+=arr[i];
		//cout<<"\nSum new:"<<sum;
		//cout<<"\nsum base : "<<sum;
		//cout<<"\tlevel : "<<level<<" -------------------------------------------";
		if(sum == N){
			//cout<<" pass";
			count++;
			sum-=arr[i];
			//cout<<"\nSum reset:"<<sum;
			return;
		}
		else if(sum<N)
		{
			findCombination_forSum(N,arr,M,sum,i,level+1);
			sum-=arr[i];
		}	
		else
		{
			//cout<<" fail";
			sum-=arr[i];
			//cout<<"\nSum reset:"<<sum;
			return;
		}
	}
}

int main()
{
	int T, M, N;
	freopen("input_coinChange.txt","r",stdin);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		count=0;
		cin>>N>>M;
		int sum=0;
		int *coins = new int[M];
		for(int j=0;j<M;j++)
			cin>>coins[j];//,cout<<coins[j]<<" ";
		//cout<<endl;
		qsort(coins,M,sizeof(int),cmpfunc);
/*		for(int j=0;j<M;j++)
			cout<<coins[j]<" ";
*/		//cout<<endl;
		findCombination_forSum(N, coins, M, sum,0,0);
		cout<<count<<endl;
	}
	//cout<<endl;
	return 0;
}
