/*

	Author : Siddheshwar P Sharma
	Date		: 03 March 2017
	Link     : https://www.hackerrank.com/challenges/flipping-the-matrix
	
	Description	:
	Reverse any rows or columns any number of times, and the goal is to maximize 
	the sum of the elements in the  NxN submatrix located in the upper-left corner of the  2Nx2N matrix.

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int max(int a, int b)
{
    return a<b?b:a;
}

int flip(int **a, int n)
{
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
            
			sum += max(max(a[i][j], a[2*n-i-1][j]), max(a[2*n-i-1][2*n-j-1], a[i][2*n - j-1]));
            //cout<<max(max(a[i][j], a[2*n-i-1][j]), max(a[2*n-i-1][2*n-j-1], a[i][2*n - j-1]))<<endl;
		}		
	}
	return sum;
}

int main()
{
	int T;
	int N;
	
	cin>>T;
	
	for(int count = 0; count < T; count++)
	{
		cin>>N;
		int **a = (int **)malloc(sizeof(int *)*2*N);
		for(int i = 0; i < 2*N; i++)
		{
			a[i] = (int *)malloc(sizeof(int)*2*N);
			for(int j = 0; j<2*N; j++)
				cin>>a[i][j];
		}
		cout<<flip(a, N)<<endl;
	}
	return 0;
}