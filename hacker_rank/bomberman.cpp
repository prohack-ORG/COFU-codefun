/***

	Author : Siddheshwar P Sharma
	Link   : https://www.hackerrank.com/challenges/bomber-man
	Date   : 1st May 2017
	status : 12/24 test cases pass successfully, remaining SEG fault

***/

#include <iostream>
#include <stdio.h>

using namespace std;
#if 0
void print_grid(int mat[][200], int r, int c)
{
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
            //if(mat[i][j] == '0')
    		    cout<<mat[i][j];
        cout<<endl;
	}
	cout<<endl;
}
#else
void print_grid(int mat[][200], int r, int c)
{
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
            if(mat[i][j] == 0)
    		    cout<<".";
            else
                cout<<'O';
        cout<<endl;
	}
	cout<<endl;
}
#endif
void move(int mat[][200], int r, int c, int stop_time, int cur_time)
{
    if(cur_time == stop_time)
    {
        //cout<<"\nfinal output\n";
        print_grid(mat, r, c);
        return;
    }
    int temp[200][200];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            if(mat[i][j] == 0)
                temp[i][j] = 1;
        }
    
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(mat[i][j] == 1)
                temp[i][j] = 2;
    
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)    
            if(mat[i][j] == 2)
                temp[i][j] = 3;
    
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)    
            if(mat[i][j] == 3)
            {
                temp[i][j]   = 0;
                if(i>0)
                {
                    temp[i-1][j] = 0;
            	}
                if(i<r-1)
                {
                    temp[i+1][j] = 0;
            	}
                if(j>0)
                {
                    temp[i][j-1] = 0;
            	}
                if(j<c-1)
                {
                    temp[i][j+1] = 0;
            	}
            }
        

	//print_grid(temp, r, c);
    move(temp, r, c, stop_time, cur_time+1);
}

int main()
{
	int r, c, n;
    char temp;
    cin>>r>>c>>n;
	int grid[200][200];
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)	
		{
            cin>>temp;
            if(temp == 'O')
                grid[i][j] = 2;
            else if(temp == '.')
                grid[i][j] = 0;
        }
    //print_grid(grid, r, c);
    move(grid, r, c, n, 1);
	
	return 0;
}