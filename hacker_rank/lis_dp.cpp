#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int N;
int *arr;
int *len;
int maxval = -1;
void lis_rec(int st, int length)									//  TLE + 1 test case fails 
{
	maxval = maxval < length ? length : maxval;
	for(int i=st+1;i<N;i++)
		if(arr[i] > arr[st])
			lis_rec(i, length+1);
}

void lis_dp()
{
	for(int i=1;i<N;i++)
		for(int j=0;j<i;j++)
			if(arr[j] <= arr[i] && len[j]+1 >= len[i])
				len[i] = len[j] + 1;
	for(int i=0;i<N;i++)
		maxval = maxval < len[i] ? len[i] : maxval;
}

int main()
{
	freopen("input_lis.txt","r",stdin);
	cin>>N;
	arr = (int*)malloc(sizeof(int )*N);
	len = (int*)calloc(N, sizeof(int ));
	for(int i=0;i<N;i++)
		cin>>arr[i];
	// lis_rec(0,1);
	lis_dp();
	cout<<maxval+1<<"\n";
	return 0;
}