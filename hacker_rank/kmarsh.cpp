#include <iostream>
#include <stdio.h>

using namespace std;

int m,n;		// m: rows(y dir counter), n: cols(x dir counter)

int safe(int mat[500][500], int r1, int r2, int c1, int c2)
{
	//cout<<"\nChecking for "<<r1<<" "<<c1<<" "<<r2<<" "<<c2;
	for(int i=0; i<m; i++)
		if(mat[i][c1] == 1 || mat[i][c2] == 1)
			return 0;
	for(int i=0; i<n; i++)
		if(mat[r1][i] == 1 || mat[r2][i] == 1)
			return 0;
	return 1;
}

void print(int a[500][500])
{
	cout<<endl;
	for(int i=0;i<m;i++){
		cout<<endl;
		for(int j=0;j<n;j++)
				cout<<a[i][j]<<" ";
	}
}
int mat[500][500]={0};
int rsum[500][500] , dsum[500][500] ;

int check(int i, int j)
{
	for(int c = 1; c <= rsum[i][j]; c++)
		if(dsum[i][j-c] < dsum[i][j])
			return 0;
	for(int r = 1; r <= dsum[i][i]; r++)
		if(rsum[i-r][j] < rsum[i][j])
			return 0;
	return 1;
}

int maxPeri(int mat[500][500], int sRow, int eRow, int sCol, int eCol)
{
	// col wise max
	for(int i=0;i<m;i++)
	{
		if(mat[i][0] == 1)
			rsum[i][0] = -1;
		else
			rsum[i][0] = 0;
		for(int j=1;j<n;j++)
				if(mat[i][j] == 1)
					rsum[i][j] = -1;
				else
					rsum[i][j] = rsum[i][j-1]+1;
	}
	// row wise max 
	for(int i=0;i<n;i++)
	{
		if(mat[0][i] == 1)
			dsum[0][i] = -1;
		else
			dsum[0][i] = 0;
		for(int j=1;j<m;j++)
				if(mat[j][i] == 1)
					dsum[j][i] = -1;
				else
					dsum[j][i] = dsum[j-1][i]+1;
	}
	
	// print(rsum);
	// print(dsum);
	// int row, col;
	int maxval = 0;
	int val;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(check(i,j))
			{
				val = rsum[i][j]+dsum[i][j] ;
				if (maxval < val && check(i,j))
					maxval = val;
				//row = i, col = j;
			}
		}
	// cout<<endl<<row<<" "<<col;
	return maxval;
}

int main()
{
	freopen("input_kmarsh.txt","r",stdin);
	cin>>m>>n;
	char val;
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			cin>>val;
			if(val == 'x')
				mat[i][j] = 1;
		}
	// print(mat);
	int res = maxPeri(mat, 0, m-1, 0, n-1);
	if(res == 0)
		cout<<"impossible";
	else
		cout<<res*2;
	return 0;
}
