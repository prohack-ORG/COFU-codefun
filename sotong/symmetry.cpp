/*

	Author : Siddheshwar P Sharma
	Date   : 23rd May 2016
	input  : input_symmetry.txt

*/

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int T, N;

char temp[50][50];

void print()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void fill(int y1, int x1, int y2, int x2)
{
	for(int i=0;i<y2-y1;i++)
		for(int j=0;j<x2-x1;j++)
		{
			temp[y2+i][x1+j] = temp[y1+i][x2+j];
			temp[y2+i][x2+j] = temp[y1+i][x1+j];
		}
}

void make()
{
	int len = 1;
	for(;len<=N/2;)
	{
		//cout<<"\nLen------------------------------------> "<<len-1;
		for(double j=0;j<N;j+=2*len)
		{
			//cout<<"\n0 "<<j<<" 0 "<<j+len;
			fill(0,j,len,j+((len)));
		}
		len=len*2;
	}
}

int main()
{
	freopen("input_symmetry.txt","r",stdin);
	cin>>T;
	for(int test=1;test<=T;test++)
	{
		cin>>N;
		//print();
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				temp[i][j]=0;
		for(int i=0;i<N;i++)
			cin>>temp[0][i];
		//print();
		make();
		print();
	}
	return 0;
}

