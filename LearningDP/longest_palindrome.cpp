/*

	Author : Siddheshwar P Sharma
	Date   : 26th March 2016
	Link   : http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/
	
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}

// Using DP tabulation
int calc_dp(char *str, int start, int end)
{
	int n = end-start;
	int table[n+1][n+1];
	for(int i=0;i<=n;i++)
		table[i][i] = 1;
	for(int L=2;L<=n;L++)
		for(int i=0;i<n-L+1; i++)
		{
			int j = i+L-1;
			if(str[i]==str[j])
				if(i==j-1)
					table[i][j]=2;
				else	
					table[i][j] = table[i+1][j-1]+2;
			else
				table[i][j] = max(table[i][j-1],table[i+1][j]);
		}
	return table[start][end-1];
}

// Using Simple Recursion
int calc(char *str, int start, int end)
{
	if(start==end)
		return 1;
	else if(str[start] == str[end] && start == end-1)
		return 2;
	else if(str[start]==str[end])	
		return calc(str, start+1, end-1)+2;
	else 
		return max(calc(str,start+1,end),calc(str, start, end-1));
}

int main()
{
	int T;
	
	int n;
	freopen("input_longest_palindrome.txt","r",stdin);
	cin>>T;
	for(int serial = 1;serial<=T;serial++)
	{
		cout<<"\nIteration : "<<serial<<endl;
		cin>>n;
		char *str = new char[n];
		for(int i=0;i<n;i++)
			cin>>str[i];
		cout <<"\n# "<<serial<<" : "<<calc(str,0,n)<<" recursion";
		cout <<"\n# "<<serial<<" : "<<calc_dp(str,0,n)<<" tabulation";
		delete str;
	}
	cout<<endl;
	return 0;
} 
