/*

Author : Siddheshwar P Sharma
Date   : 20th Feb 2016

*/


#include <iostream>
#include <limits.h>
using namespace std;
#define MAX 100
int temp[MAX];

long fibo_dp(int n)
{
	//cout<<"\nTemp : "<<temp[n];
	
	if(temp[n]==0)
	{
		if(n<=1)
			temp[n] = 1;
		
		else
			temp[n] = fibo_dp(n-1) + fibo_dp(n-2);
	
	}
	//cout<<"\nfor n : "<<n<<" val : "<<temp[n];
	return temp[n];
}

long fibo_rec(int n)
{
	if(n<=1)
		return 1;
	return fibo_rec(n-1)+fibo_rec(n-2);
}

int main()
{
	int n;
	cout<<"\nEnter number to get fibonacci value : ";
	cin>>n;

	for(int i=0;i<n;i++)
		temp[i] = 0;

	cout<<"\nCalculating now";
	cout<<"\nDynamic Fibo["<<n<<"] : "<<fibo_dp(n)<<endl;
	cout<<"\nRecursive Fibo["<<n<<"] : "<<fibo_rec(n)<<endl;
	return 0;
}
