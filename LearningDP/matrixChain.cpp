/*

	Author : Siddheshwar P Sharma
	Date   : 22nd March 2016
	Link   : http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
	input  : input_matrix.txt

*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
using namespace std;


long findmultcost(int *a, int s, int e)
{
	cout<<"\nAt "<<s<<" "<<e;
	if(s==e)
		return 0;
	int minval = INT_MAX;
		for(int i=s;i<e;i++)
		{
			long temp = findmultcost(a,s,i)+findmultcost(a,i+1,e)+a[s-1]*a[i]*a[e];
			if(temp < minval)
				minval = temp;
		}
	return minval;
}

long findcost_dp(int *a, int n)
{
	int temp[n][n];
	for(int i=0;i<n;i++)
		temp[i][i]=0;//,temp[0][i] = 0, temp[i][0]=0;
	for(int L=2;L<n;L++)				//For the length of bracket
		for(int i=1;i<n-L+1;i++)		//for start of bracket
		{
			int j=i+L-1;				//for end of bracket
			temp[i][j]=INT_MAX;	
			for(int k=i;k<j;k++)		//for picking best point b/w start and end to fit sub problem
			{
				int val = temp[i][k]+temp[k+1][j]+a[i-1]*a[k]*a[j];
				if(val<temp[i][j])
					temp[i][j] = val;
			}
		}
/*	for(int i=0;i<n;i++){
		cout<<endl;
		for(int j=0;j<n;j++)
			cout<<temp[i][j]<<" ";
	}*/
	return temp[1][n-1];
}

int main()
{
	int T=1;
	freopen("input_matrix.txt","r",stdin);
	cin>>T;
	int n, *sizeArr;
	for(int i=0;i<T;i++)
	{
		cin>>n;
		sizeArr = new int[n+1];
		for(int j=0;j<=n;j++)
			cin>>sizeArr[j];
		cout<<findcost_dp(sizeArr,n+1)<<endl;
	}
	cout<<endl;
	return 0;
}

