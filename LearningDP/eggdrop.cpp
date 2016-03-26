/*

	Author : Siddheshwar P Sharma
	Date   : 25th March 2016
	Link   : http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/
	
*/


#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int max(int a, int b)
{
	return a>b ? a:b;
}

// GFG solution
int eggDrop(int n, int k)
{
    /* A 2D table where entery eggFloor[i][j] will represent minimum
       number of trials needed for i eggs and j floors. */
    int eggFloor[n+1][k+1];
    int res;
    int i, j, x;
 
    // We need one trial for one floor and0 trials for 0 floors
    for (i = 1; i <= n; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }
 
    // We always need j trials for one egg and j floors.
    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;
 
    // Fill rest of the entries in table using optimal substructure
    // property
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= k; j++)
        {
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; x++)
            {
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }
 
    // eggFloor[n][k] holds the result
    return eggFloor[n][k];
}
// My solution
int numTrial_dp(int n, int k)
{
	int table[n+1][k+1];
	for(int i=1;i<=n;i++)
		table[i][1]=i;
	for(int i=0;i<=k;i++)
		table[1][i]=1, table[0][i]=0;
	for(int i=2;i<=n;i++)			// loop for floors
	{
		for(int j=2;j<=k;j++)		// loop for eggs
		{	
			table[i][j]=INT_MAX;
			for(int x=1;x<=i;x++)	// loop for sub
			{
				int temp = 1 + max(table[x-1][j-1],table[i-x][j]);
				table[i][j] = table[i][j] > temp ? temp : table[i][j];	
			}
		}	
	}
	return table[n][k];
}

int numTrial(int n, int k)
{
	if(n==1 || n==0)
		return 1;
	if(k==1)
		return n;
	int val = INT_MAX;
	int temp;
	for(int i=1;i<=n;i++)
	{
		temp = max(numTrial(i-1,k-1),numTrial(n-i,k));
		val = val > temp ? temp:val; 
	}
	return val+1;
}

int main()
{
	int n,k; // n : number of floors, k : number of available eggs
	n=36;
	k=5;
	cout<<"\n"<<eggDrop(k,n)<<endl;
	cout<<"\n"<<numTrial_dp(n,k)<<endl;
	return 0;
}
