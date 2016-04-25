/*

	Author : Siddheshwar P Sharma
	Date   : 25th April 2016
	Link   : http://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/
	input  : input_partition.txt

*/

#include <iostream>
#include <stdio.h>

using namespace std;

int partition(int *a, int n, int sum)
{
	if(sum==0)
		return 1;
	if(n<0)
		return 0;
	if(sum<a[n-1])
		return partition(a, n-1, sum);
	return partition(a, n-1, sum-a[n-1])||partition(a,n-1,sum);
}

int part(int *a, int n, int sum)
{
	int temp[sum+1][n+1];
	for(int i=0;i<=sum;i++)
		temp[i][0] = 0;
	for(int i=0;i<=n;i++)
		temp[0][i] = 1;
	for(int i=1;i<=sum;i++)
		for(int j=1;j<=n;j++)
		{
			if(sum==temp[i][j])
				return 1;
				temp[i][j] = temp[i][j-1];
			if(sum>=a[j-1])
				temp[i][j] = temp[i][j-1] || temp[i-a[j-1]][j-1];
		}
	return temp[sum][n];
}

int main()
{
	int n,sum=0;
	freopen("input_partition.txt","r",stdin);
	cin>>n;
	int *a  = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i],sum+=a[i];
	if(sum%2 == 1)
		cout<<"\nFalse";
	else
		if(part(a,n,sum/2))
			cout<<"\nTrue";
		else
			cout<<"\nFalse";
	
	return 0;
}
