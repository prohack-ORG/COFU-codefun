/*

	Author : Siddheshwar P Sharma
	Date   : 16th April 2016
	input  : input_bitonicSub.txt
	Link   : http://www.geeksforgeeks.org/dynamic-programming-set-15-longest-bitonic-subsequence/

*/

#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;
int bitoSub(int *a, int n)
{
	int maxval = INT_MIN;
	int *b = new int[n];
	int *c = new int[n];
	for(int i=0;i<n;i++)
		b[i]=1,c[i]=1;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
			if(a[i]>a[j] )
				b[i] = (b[i]<b[j]+1) ? b[j]+1:b[i];
		for(int j=0;j<i;j++)
			if(a[i]<a[j] )
				c[i] = (c[i]<c[j]+1) ? c[j]+1:c[i];
	}
	for(int i=0;i<n;i++)
		maxval = (maxval>b[i]+c[i]-1)?maxval:(b[i]+c[i]-1);
	return maxval;
}

int main()
{
	int cases;
	int n;
	freopen("input_bitonicSub.txt","r",stdin);
	cin>>cases;
	for(int i=0;i<cases;i++)
	{
		cin>>n;
		int * arr = new int[n];
		for(int j=0;j<n;j++)
			cin>>arr[j];
		int ans = bitoSub(arr,n);
		cout<<endl<<i+1<<" : "<<ans;
	}
	cout<<endl;
	return 0;
}
