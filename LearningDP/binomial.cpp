/*

	Author : Siddheshwar P Sharma
	Date   : 25th March 2016
	Link   : http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/
	input  : input_binomial.txt

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ITERATION 10
using namespace std;

// Binomial Coefficient C(n,r) = C(n-1,r-1) + C(n-1,r)

// Using DP Tablulation
int calc_dp(int n, int r)
{
	int table[n+1][r+1];

	for(int i=0;i<=n;i++)
		table[i][0]=1;//,table[0][i]=0;
	for(int j=1;j<=n;j++)
		for(int i=1;i<=r;i++)
		{
			if (i == j) table[j][i] = 1;
			else
				table[j][i] = table[j-1][i-1]+table[j-1][i];
		}
	/*
	for(int i=0;i<n+1;i++)
	{
		cout<<endl;
		for(int j=0;j<r+1;j++)
			cout<<table[i][j]<<" ";
	}
	cout<<endl;
	*/
	return table[n][r];
}

// Using simmple recursion
int calc(int n, int r)
{
	if(r==0||n==r)
		return 1;
	return calc(n-1,r-1)+calc(n-1,r);	
}
/*
int main()
{
	int T;
	int n,r;
	freopen("input_binomial.txt","r",stdin);
	cin>>T;
	for(int iter = 0;iter < ITERATION; iter++)
		for(int i=0;i<T;i++)
		{
			cin>>n>>r;
			if(r>n || n<=0)
			{
				cout<<"\nFaulty input, try again";
				continue;
			}
			
			cout<<"\n# "<<i+1<<" "<<calc_dp(n,r);
			cout<<"\n# "<<i+1<<" "<<calc(n,r);
		}
	cout<<endl;
	return 0;
}*/
// For profiling recursion vs DP Tabulation
int main()
{
	int n=25, r=12;
	long val;
	
	timeval t1,t2;
	long time_val_dp,time_val_rec;
	
	gettimeofday(&t1,0);
	for(int i=0;i<ITERATION;i++)
		val = calc(n,r);
	gettimeofday(&t2,0);
	time_val_rec = (t2.tv_sec-t1.tv_sec)/1000+(t2.tv_usec-t1.tv_usec)*1000;
	cout<<"\nTime taken by recursion : "<<time_val_rec<<" sec.";
	cout<<"\tValue : "<<val;
	
	gettimeofday(&t1,0);
	for(int i=0;i<ITERATION;i++)
		val = calc_dp(n,r);
	gettimeofday(&t2,0);
	time_val_dp = (t2.tv_sec-t1.tv_sec)/1000+(t2.tv_usec-t1.tv_usec)*1000;
	cout<<"\nTime taken by tabulation : "<<time_val_dp<<" sec.";
	cout<<"\tValue : "<<val;
	cout<<"\nGain : "<<float(time_val_rec/time_val_dp)<<" x";
	cout<<endl;
	return 0;
}
