/*

	Author : Siddheshwar P Sharma
	Date   : 31st July 2016
	Link   : https://www.hackerrank.com/challenges/array-splitting
	input  : input_nikita.txt

*/

#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <limits.h>

long  max(int a, int b)
{
	return a>b ? a:b;
}

using namespace std;

long sum(int *arr, int st, int en)
{
	int sum = 0;
	for(int i=st;i<=en;i++)
		sum+=arr[i];
	return sum;
}

int findEqPoint(int *arr, int st, int en)
{	
	for(int i = st; i<=en; i++)
		if(sum(arr, st, i)==sum(arr, i+1, en))
			return i;
	return -1;
}

int scoreCalc(int *arr, int st, int en)
{
	if(st>en)
		return 0;
	//cout<<"\n"<<st<<" -> "<<en;
	int val;
	if(st==en)
		return 0;
	int eqPt = findEqPoint(arr, st, en);
	if(eqPt == -1)
		return 0;
	
	val =  1 + max(scoreCalc(arr, st, eqPt), scoreCalc(arr, eqPt+1, en));
	//cout<<"\n"<<"returning "<<val;
	
	return val;
}

int main()
{
	int T,N;
	int *arr;
	freopen("input_nikita.txt","rb",stdin);
	cin>>T;
	for(int test_case = 1; test_case<=T; test_case++)
	{
		cin>>N;
		arr = (int *)malloc(sizeof(int )*N);
		for(int i=0;i<N;i++)
			cin>>arr[i];
		cout<<scoreCalc(arr, 0, N-1)<<endl;
	}
	return 0;
}
