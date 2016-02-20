/*

Author : Siddheshwar P Sharma
Date   : 20th Feb 2016

*/

//for i/p 6,10,14,18 etc. gives wrong output don't know why

#include <iostream>
using namespace std;

long fibo_dp(int n, int *temp)
{
	cout<<"\nTemp : "<<temp[n];
	
	if(temp[n]==0)
	{
		if(n<=1)
			temp[n] = n;
		
		else
			temp[n] = fibo_dp(n-1, temp) + fibo_dp(n-2, temp);
	
	}
	//cout<<"\nfor n : "<<n<<" val : "<<temp[n];
	return temp[n];
}

long fibo_rec(int n)
{
	if(n<=1)
		return n;
	return fibo_rec(n-1)+fibo_rec(n-2);
}

int main()
{
	int n;
	cout<<"\nEnter number to get fibonacci value : ";
	cin>>n;
	int *temp = new int[n];
	for(int i=0;i<n;i++)
		temp[i] = 0;

	cout<<"\nCalculating now";
	cout<<"\nDynamic Fibo["<<n<<"] : "<<fibo_dp(n, temp)<<endl;
	cout<<"\nRecursive Fibo["<<n<<"] : "<<fibo_rec(n)<<endl;
	return 0;
}
