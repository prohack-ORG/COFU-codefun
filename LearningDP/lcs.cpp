/*

Author : Siddheshwar P Sharma
Date   : 24th Feb 2016

*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int max(int a, int b)
{
	return a<b ? b:a;
}

int LCS(char *a, char *b, int x, int y)
{
	if(x==0||y==0)
		return 0;
	if(a[x-1]==b[y-1])
		return 1+LCS(a,b,x-1,y-1);
	else
		return max(LCS(a,b,x-1,y),LCS(a,b,x,y-1));
}

int main()
{
	int x,y;
	freopen("LCS_input.txt","r",stdin);
	cin>>x>>y;
	char *a = (char *)malloc(sizeof(char )*x);
	char *b = (char *)malloc(sizeof(char )*y);
	for(int i=0; i<x; i++)
		cin>>a[i];
	for(int i=0; i<y; i++)
		cin>>b[i];
	cout<<LCS(a,b,x,y)<<endl;
	return 0;
}
