/*

	Author : Siddheshwar P Sharma
	Date   : 26th March 2016
	Link   : http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>

int max(int a, int b)
{
	return a>b?a:b;
}

using namespace std;

// Dynamic Programming Approach : Tablulation
int knap_dp(int W, int *wt, int *val, int n)
{
	int table[n+1][W+1];
	
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{	
			if(i==0||j==0)
				table[i][j] = 0;
			else if(wt[i]<=W)
				table[i][j] = max((val[i]+table[i-1][j-wt[i]]),table[i-1][j]);
			else
				table[i][j] = table[i-1][j];
		}
	}
	return table[n][W];
}

// Normal Recursive Solution
int knapsack(int W, int *wt, int *val, int n)
{
	if(W==0||n==0)
		return 0;
	else if(wt[n-1]>W)
		return knapsack(W, wt, val, n-1);
	return max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
}

int main()
{
    int val[] = {60, 120, 100};
    int wt[] = {10, 30, 20};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    //printf("%d", knapsack(W, wt, val, n));
    printf("%d", knap_dp(W, wt, val, n));
	cout<<"\n";
    return 0;
}
