/*

Author : Siddheshwar P Sharma
Date   : 24th Feb 2016

*/

#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

using namespace std;

void LIS_brute(int *a, int n)
{
	int max = INT_MIN;
	int len;
	int prev_big; 	
	for(int i=0; i<n-2; i++)
	{
		len = 1;
		prev_big = a[i];
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>prev_big)
				len++,prev_big = a[j];
		}
		max = max<len ? len:max;
	}
	cout<<"\nLIS length is : "<<max;
}

int main()
{
	int num;
	freopen("LIS_input.txt","r",stdin);
	cin>>num;
	int *arr = new int[num];
	for(int i=0;i<num;i++)
		cin>>arr[i];
	LIS_brute(arr,num);
	cout<<endl;
	return 0;
}
