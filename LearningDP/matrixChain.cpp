/*

	Author : Siddheshwar P Sharma
	Date   : 15th March 2016
	Link   : http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
	input  : input_matrix.txt

*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int findmincost(int *a, int s, int n)
{
	if(s==n)
		return 0;
	if(s==n-1)
		return a[s-1]*a[s]*a[n];
	//findmincost(a,s,) + findmincost(a,s+1,n);  inplement main logic here
}

int main()
{
	int T=1;
	freopen("input_matrix.txt","r",stdin);
	int n, *sizeArr;
	for(int i=0;i<T;i++)
	{
		cin>>n;
		sizeArr = new int[n+1];
		for(int j=0;j<=n;j++)
			cin>>sizeArr[j];
		cout<<findmincost(sizeArr,1,n-1)<<endl;
	}
	cout<<endl;
	return 0;
}

