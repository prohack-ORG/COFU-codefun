/*

	Author : Siddheshwar P Sharma
	Date    : 31st Oct 2016
	Link    : https://www.hackerrank.com/challenges/fair-cut/
	input   : input_faircut.txt
	
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int N,K;
long long int MIN(long long int a, long long int b)
{
	return a<b ? a:b;
}
long ABS(long a)
{
	return a<0 ? -a:a;
}

void print(long a[])
{
	cout<<endl;
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
}

void print(int a[])
{
	cout<<endl;
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
}

long long int count_fairness(long temp[], int taken[])
{
	long long int sum=0;
	for(int i=0;i<N;i++)
	{
		if(taken[i])
			for(int j=0;j<N;j++)
				if(!taken[j]){
					sum += ABS(temp[i]-temp[j]);
					// cout<<"\nsum : "<<sum<<" "<<temp[i]<<" - "<<temp[j];
				}
	}
	return sum;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(long*)a - *(long*)b );
}

long long int physics(long temp[], int taken[])
{
		qsort(temp, N, sizeof(long ), cmpfunc);
		// print(temp);
		int count = 0;
		int st;
		for(int i=0;i<N;i++)
			taken[i] = 0;
		if(K%2)
			st = N/2-K+1;
		else
			st = N/2-K;
		for(int i=st;count<K ;i+=2)
			taken[i] = 1, count++;
		// print(taken);
		long long temp1 = count_fairness(temp, taken);
		count = 0;
		for(int i=0;i<N;i++)
			taken[i] = 0;
		for(int i=st+1;count<K ;i+=2)
			taken[i] = 1, count++;
		// print(taken);
		long long temp2 = count_fairness(temp, taken);
		return MIN(temp1, temp2);
}

int main()
{
	long temp[3000];
	int taken[3000]={0};
	freopen("input_faircut.txt","r",stdin);
	cin>>N>>K;
	K = MIN(K, N-K);
	for(int i=0;i<N;i++)
		cin>>temp[i];
	long long int val = physics(temp, taken);
	cout<<val<<endl;
	return 0;
}