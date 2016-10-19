/*

	Problem : Equals
	Author : Siddheshwar P Sharma
	input : input_equal.txt
	Date : 19 Oct 2016
	Link : https://www.hackerrank.com/challenges/equal

*/

#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;

// #define MIN(a,b) a<b ? a:b

int MIN(int a, int b)
{
	return a<b ? a:b;
}

int calc(int a[], int diff[], int n, int min)
{
	int moves1=0;
	int moves2=0;
	int moves3=0;
	int moves4=0;
	for(int i=0;i<n;i++){
		int temp = diff[i];
		moves1 += temp/5+(temp%5)/2+((temp%5)%2);
		temp = diff[i]+1;
		moves2 += temp/5+(temp%5)/2+((temp%5)%2);
		temp = diff[i]+2;
		moves3 += temp/5+(temp%5)/2+((temp%5)%2);
		temp = diff[i]+5;
		moves4 += temp/5+(temp%5)/2+((temp%5)%2);
		cout<<"\n\n"<<diff[i]<<" "<<diff[i]+1<<" "<<diff[i]+2<<" "<<diff[i]+5;
		cout<<"\n"<<moves1<<" "<<moves2<<" "<<moves3<<" "<<moves4;
	}
	
	return MIN(MIN(moves1, moves2),MIN(moves3, moves4));
}

int main()
{
	int T;
	int N;
	freopen("input_equal.txt","r",stdin);
	cin>>T;
	int choco[10000];
	int diff[10000]={0};
	for(int i=0;i<T;i++)
	{
		cin>>N;
		int minVal = INT_MAX;
		for(int j=0;j<N;j++)
		{
			cin>>choco[j];
			minVal = minVal > choco[j] ? choco[j] : minVal;
		}
		for(int i=0;i<N;i++)
			diff[i] = choco[i]-minVal;
		
		cout<<endl<<calc(choco, diff, N, minVal)<<endl;
	}
	return 0;
}