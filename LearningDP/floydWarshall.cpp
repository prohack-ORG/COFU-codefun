/*

	Author  : Siddheshwar P Sharma
	Date    : 16th April 2016
	Link    : http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/
	input   : input_floyd.txt

*/

#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

void floyd(int **mat, int n)
{
	int **temp = new int*[n];

	for(int i=0;i<n;i++)
		temp[i] = new int[n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			temp[i][j] = mat[i][j];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				if( temp[i][j] > temp[i][k]+temp[k][j])
					temp[i][j] = temp[i][k]+temp[k][j];
	for(int i=0;i<n;i++)
	{
		cout<<endl;
		for(int j=0;j<n;j++)
			cout<<temp[i][j]<<" ";
	}
}

int main()
{
	int cases,n;
	freopen("input_floyd.txt","r",stdin);
	cin>>cases;
	for(int k=1;k<=cases;k++)
	{
		cin>>n;
		int **mat = new int*[n];
		for(int i=0;i<n;i++)
		{
			mat[i] = new int[n];
			for(int j=0;j<n;j++)
				cin>>mat[i][j];
		}
		floyd(mat,n);
	}
	cout<<endl;
	return 0;
}
