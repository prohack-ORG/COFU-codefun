/*

	Author : Siddheshwar P Sharma
	Date    : 12th Dec 2016
	Link    : https://www.hackerrank.com/challenges/sherlock-and-cost
	input  : input_sherlock.txt
	
	Approach :
		1. Brute Force using Recursion [status : TLE as expected with n in range 10^5]
		2. DP [status : passed all test cases, bottom up approach used with space o(n)]
	
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
using namespace std;

int T;
int N;
int maxScore;

void print(int *a, int n)
{
	cout<<endl;
	for(int i=0; i<N; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int absolute(int a)
{
	return a<0 ? -a : a; 
}

int maxi(int a, int b)
{
	return a>b ? a: b;
}

void sherlock(int *a, int st, int prev_val, int score)
{
	if(st == N)
	{
		if(maxScore < score)
			maxScore = score;
		return;
	}		
	sherlock(a, st+1, a[st], score+absolute(prev_val - a[st]));
	sherlock(a, st+1, 1, score+absolute(prev_val - 1));
}

//b[i][0] : used 1 at previous location
//b[i][1] : used a[i] at previous location
int sherlock_dp(int *a, int *b[])
{
	b[1][0] = absolute(a[1] - a[0]);
	b[1][1] = absolute(1 - a[0]);
	for(int i=1;i<N;i++)
	{
		b[i][0] = maxi ( b[i-1][0] + absolute(a[i] - a[i-1]) , b[i-1][1] + absolute(1 - a[i]));
		b[i][1] = maxi ( b[i-1][0] + absolute(1-a[i-1]) , b[i-1][1] + absolute(1 - 1));
	}
	return maxi(b[N-1][0], b[N-1][1]);
}

int main_brute()
{
	freopen("input_sherlock.txt","r",stdin);
	cin>>T;
	
	for(int k = 0; k<T; k++)
	{
		cin>>N;
		int *a = new int[N];
		memset(a, 0, N);
		
		for(int i=0; i<N;i++)
			cin>>a[i];
		
		maxScore = -1;
		
		sherlock(a, 1,  a[0],  0);
		sherlock(a, 1,  1,  0);
		
		cout<<maxScore<<endl;
		delete[] a;
	}
	return 0;
}
int main_dp()
{
	freopen("input_sherlock.txt","r",stdin);
	cin>>T;
	
	for(int k = 0; k<T; k++)
	{
		cin>>N;
		
		int *a = new int[N];
		int **b = new int*[N];
		
		for(int i=0;i<N;i++)
			b[i] = new int[2];
		
		for(int i=0; i<N;i++)
			cin>>a[i], b[i][0] = 0, b[i][1] = 0;
		
		if(N==1){
			cout<<"0"<<endl;
			continue;
		}
		int answer = sherlock_dp(a, b);
		// print(b[0], N);
		// print(b[1], N);
		
		cout<<answer<<endl;

		delete[] a;
		delete[] b[0];
		delete[] b[1];
	}
	return 0;
}

int main()
{
	// main_brute();
	main_dp();
	return 0;
}

/*
o/p: 
-----
1121
642
508
1107
5563
5012
4858
4256
3585
1228
2849
1709
4550
2603
0
3264
3949
0
3242
1888
*/