/*

	Author : Siddheshwar P Sharma
	Date   : 12th May 2016
	input  : input_vision.txt

*/

#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int T,N;

int main()
{
	freopen("input_vision.txt","r",stdin);
	cin>>T;
	//T=5;
	for(int test=2;test<=T;test++)
	{
		//cin>>N;
		N=test;
		int **map = new int*[N];
		int count=0;
		for(int i=0;i<N;i++)
		{
			map[i] = new int[N];
			for(int j=0;j<N;j++)
				map[i][j] = 0;
		}
		for(int i=2;i<N;i++)
			map[0][i]=1,map[i][0]=1;
		for(int i=1;i<N;i++)
			for(int j=i;j<N;j++)
				if(map[i][j]==0)
				{
					for(int k=2;k<=(N-1)/j;k++)
					{
						map[i*k][j*k]=1;
						//map[j*k][i*k]=1;
					}
					count++;
				}
	/*
		for(int i=0;i<N;i++)
		{
			cout<<endl;
			for(int j=0;j<N;j++)
				cout<<map[i][j]<<" ";
		}
	*/
		cout<<"\n"<<(count-1)*2+3<<endl;
				
	}
	return 0;
}
