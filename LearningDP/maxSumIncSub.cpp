/*

	Author : Siddheshwar P Sharma
	Date   : 16th April 2016
	input  : input_msis.txt
	Link   : http://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/

*/

#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;
int msis(int *a, int n)
{
	int maxval = INT_MIN;
	int *b = new int[n];
	for(int i=0;i<n;i++)
		b[i]=a[i];
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(a[i]>a[j] )
				b[i] = (b[i]<b[j]+a[i]) ? b[j]+a[i]:b[i];
	for(int i=0;i<n;i++)
		maxval = maxval>b[i]?maxval:b[i];
	return maxval;
}

int main()
{
	int cases;
	int n;
	freopen("input_msis.txt","r",stdin);
	cin>>cases;
	for(int i=0;i<cases;i++)
	{
		cin>>n;
		int * arr = new int[n];
		for(int j=0;j<n;j++)
			cin>>arr[j];
		int ans = msis(arr,n);
		cout<<endl<<i+1<<" : "<<ans;
	}
	cout<<endl;
	return 0;
}
