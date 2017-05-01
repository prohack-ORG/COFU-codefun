/***

	Author : Siddheshwar P Sharma
	Link   : https://www.hackerrank.com/challenges/bomber-man
	Date   : 1st May 2017
	status : solved

***/
#include <iostream>
#include <stdio.h>

using namespace std;

static int sec = 2;
int fin[12][200][200];
bool flag;
#if 0							
// enable to print output in more meaningful manner 
void print_grid(int mat[][200], int r, int c, int cur_time)
{
    cout<<"\nAfter "<<cur_time<<" seconds\n";
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
// output in required format
void print_grid(int mat[][200], int r, int c, int cur_time)
{
    //cout<<"\nAfter "<<cur_time<<" seconds\n";    
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
// function to store all possible configurations which will be repeated
void copy_grid(int from[][200], int to[][200][200], int time, int r, int c)
    {
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            to[time-1][i][j] = from[i][j];
}

// function to update the grid every second
void move(int mat[][200], int r, int c, int stop_time, int cur_time)
{
    if(cur_time == stop_time+1 || cur_time > 10)
        return;
        
    int temp[200][200];
    
    for(int i=0; i<r; i++)				// if no bomb, plant it
        for(int j=0; j<c; j++)
            if(mat[i][j] == 0)
                temp[i][j] = 1;
    
    for(int i=0; i<r; i++)				// if planted, increase time
        for(int j=0; j<c; j++)
            if(mat[i][j] == 1)
                temp[i][j] = 2;
    
    for(int i=0; i<r; i++)				// if planted, increase time
        for(int j=0; j<c; j++)    
            if(mat[i][j] == 2)
                temp[i][j] = 3;
    
    for(int i=0; i<r; i++)				// if time over, explode it and neighbours
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
            
    if(cur_time < 10)					// save intermediate steps
        copy_grid(temp, fin, cur_time, r, c);
	//print_grid(temp, r, c, cur_time);
    move(temp, r, c, stop_time, cur_time+1);
}

int main()
{
	int r, c, n;
    char temp;
    cin>>r>>c>>n;
	int grid[200][200];
    flag = false;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)	
		{
            cin>>temp;
            if(temp == 'O')
                grid[i][j] = 2;
            else if(temp == '.')
                grid[i][j] = 0;
        }
    copy_grid(grid, fin, 1, r, c);
    //print_grid(grid, r, c, 1);
    move(grid, r, c, n, 2);
    //cout<<"\nsolution\n";
    if(n<4)
        print_grid(fin[n-1], r, c, n);  
    else
        print_grid(fin[4+n%4-1], r, c, n);
	/***
		[4+n%4-1] used because sometimes 1st 4 step's configurations don't repeat. 
		repetition is sure after 4 steps, so for 1st 4 steps calculation is must
		after that grid configuration simply is printed by accessing the saved 
		intermediate configurations from "fin" matrix.
	***/
    //cout<<"\nall grid configurations\n";
	//for(int i=0;i<10;i++)
    //    print_grid(fin[i], r, c, i);
	return 0;
}