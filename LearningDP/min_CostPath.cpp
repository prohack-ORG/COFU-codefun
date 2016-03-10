/*

	Author : Siddheshwar P Sharma
	Date   : 10th March 2016
	LINK   : http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/
	input file : input_minCost.txt

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int min(int a, int b)
{
	return a<b?a:b;
}

int findminCost(int **mat, int sx, int sy, int ex, int ey)
{
	//cout<<"\nat "<<sy<<" "<<sx<<" "<<mat[sx][sy];
	if(sx==sy && sy==ey)
		return mat[sx][sy];
	else if(sx==ex && sy!=ey)
		return  mat[sx][sy]+findminCost(mat,sx,sy+1,ex,ey);
	else if(sx!=ex && sy==ey)
		return  mat[sx][sy]+findminCost(mat,sx+1,sy,ex,ey);
	else
		return mat[sx][sy]+min(min(findminCost(mat,sx+1,sy,ex,ey),findminCost(mat,sx,sy+1,ex,ey)),findminCost(mat,sx+1,sy+1,ex,ey));		
}

int main()
{
	int num_tests;
	freopen("input_minCost.txt","r",stdin);
	cin>>num_tests;

	int width, height, startx, starty, endx, endy;

	for(int i=0; i<num_tests;i++ )
	{
		cin>>width>>height>>startx>>starty>>endx>>endy;
		int **mat = new int*[height];	
	
		for(int j = 0;j<height; j++){
			mat[j] = new int[width];
			for(int k = 0;k<width;k++)
				cin>>mat[j][k];
		}

		cout<<"\n#test_case : "<<i<<" min path cost : "<<findminCost(mat, startx, starty, endx, endy);
	}
	cout<<endl<<endl;
	return 0;
}

