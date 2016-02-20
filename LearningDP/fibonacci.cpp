/*

Author : Siddheshwar P Sharma
Date   : 20th Feb 2016

*/


#include <iostream>
#include <limits.h>
#include <sys/time.h>
using namespace std;
#define MAX 50
long temp[MAX];

// dynamic programming bottom up approach
long fibo_dp_bu(int n)
{
	temp[0]=0;
	temp[1]=1;
	for(int i=2;i<=n;i++)
		temp[i]=temp[i-1]+temp[i-2];
	return temp[n];
}

// dynamic programming top down approach
long fibo_dp_td(int n)
{
	//cout<<"\nTemp : "<<temp[n];
	if(temp[n]==0)
	{
		if(n<=1)
			temp[n] = n;
		else
			temp[n] = fibo_dp_td(n-1) + fibo_dp_td(n-2);
	}
	//cout<<"\nfor n : "<<n<<" val : "<<temp[n];
	return temp[n];
}

// Recursive Approach
long fibo_rec(int n)
{
	if(n<=1)
		return n;
	return fibo_rec(n-1)+fibo_rec(n-2);
}

int main()
{
	cout<<"\nEnter number to get fibonacci value : ";
	long result[MAX];
	for(int i=0;i<MAX;i++)
		temp[i] = 0;

	timeval end, start;
	gettimeofday(&start,0);
	for(int i=0;i<MAX;i++)
		result[i] = fibo_dp_bu(i);
	gettimeofday(&end,0);
	cout<<"\nDynamic bottom up Fibo time taken : "<<(end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000<<" msecs"<<endl;
	cout<<"\n";
	gettimeofday(&start,0);
	for(int i=0;i<MAX;i++)
		result[i] = fibo_dp_td(i);
	gettimeofday(&end,0);
	cout<<"\nDynamic top down Fibo time taken : "<<(end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000<<" msecs"<<endl;
	cout<<"\n";
	gettimeofday(&start,0);
	for(int i=0;i<MAX;i++)
		result[i] = fibo_rec(i);
	gettimeofday(&end,0);
	cout<<"\nRecursive Fibo time taken : "<<(end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000<<" msecs"<<endl;
	cout<<"\n";
	//for(int i=0;i<MAX;i++)
		//cout<<endl<<"fib "<<i<<" : "<<result[i]<<" ";	
	



	return 0;
}
