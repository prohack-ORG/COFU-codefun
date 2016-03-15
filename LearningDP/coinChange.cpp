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

int dp_coin(int N, int *arr, int M)
{
	int table[N+1];
	for(int i=0;i<=N;i++)
		table[i]=0;
	table[0]=1;
	for(int i=0;i<M;i++)
		for(int j=arr[i];j<=N;j++)
			table[j]+=table[j-arr[i]];
	return table[N];
}
int countDP(int n, int S[], int m )
{
    int i, j, x, y;
 
    // We need n+1 rows as the table is consturcted in bottom up manner using 
    // the base case 0 value case (n = 0)
    int table[n+1][m];
    
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table enteries in bottom up manner  
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}
 

int coinDP(int N, int *arr, int M)
{
	int t[N+1][M];
	
/*	for(int i=0;i<M;i++)
		for(int j=0;j<=N;j++)
			t[i][j]=0;
*/	
	for(int i=0;i<M;i++)
		t[0][i]=1;

	for(int i=1;i<=N;i++)
		for(int j=0;j<M;j++)
		{
			int y = (i-arr[j])>=0 ? t[i-arr[j]][j] : 0;
			int x = j>0 ? t[i][j-1] : 0;
			t[i][j] = x+y ;		
		}
	return t[N][M-1];
}

// Beautiful recursion
int coin(int N, int *arr, int M)
{
	if(N==0)
		return 1;
	if(N<0)
		return 0;
	if(N>0&&M==0)
		return 0;
	return coin(N,arr,M-1)+coin(N-arr[M-1],arr,M);
}

// Ugly recursion by Me
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
		//findCombination_forSum(N, coins, M, sum,0,0);
		cout<<coinDP(N,coins,M)<<endl;
	}
	cout<<endl;
	return 0;
}
