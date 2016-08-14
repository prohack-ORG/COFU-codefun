#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

using namespace std;
int n;
int a[50];

int sum(int t)
{
	int val = 0;
	for(int i=0;i<=t;i++)
		val+=a[i];
	return val;
}

void print(int *a)
{
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	freopen("input_polygon.txt","r",stdin);
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(n == 1 && a[0])
	{
		cout<<"2";
		return 0;
	}
	if(n == 2 && a[0] && a[1])
	{
		cout<<"1";
		return 0;
	}
	print(a);
	qsort(a, n, sizeof(int), compare);
	print(a);
	int temp  = sum(n-2);
	// cout<<"\ntemp :"<<temp;
	int count = 0;
	while(a[n-1] >= temp)
	{
		cout<<"\nSum upto n-1 : "<<temp;
		int t = a[n-1];
		a[n-1] = temp-1;
		a[n] = t - a[n-1];
		count++;
		temp += a[n-1];
		n++;
		print(a);
	}
	if(count)
		cout<<count;
	else
		cout<<"0";
	return 0;
}