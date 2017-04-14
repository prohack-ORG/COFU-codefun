/*
		Author : Siddheshwar P Sharma
		Date     : 20th Nov 2016
		Purpose : to compare two image files

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define WIDTH 4128
#define HEIGHT 3096
#define NUM_FRAMES 1

#define absolute(a) a<0 ? -a : a

int main(int argc, char **argv)
{
	int file_type = 0;							// 1 : yuv file 
	int width, height;
	if(file_type == 1)
	{
		height = HEIGHT * 3/2;
		width = WIDTH;
	}
	else
	{
		height = HEIGHT;
		width = WIDTH;		
	}
	cout<<"\nBP : 1";
	char path1[] = "image_001.jpg";
	char path2[] = "image_002.jpg";
	char mode[] = "rb";
	cout<<"\nBP : 2";
	char *in_buffer1 = new char[WIDTH];
	char *in_buffer2 = new char[WIDTH];
	int *diff_count = new int[NUM_FRAMES];
	int *max_diff = new int[NUM_FRAMES];
	int total_diff_count = 0;
	memset(diff_count, 0, NUM_FRAMES);
	memset(max_diff, -1, NUM_FRAMES);
	cout<<"\nBP : 3";
	FILE *fp1 = fopen(path1, mode);
	FILE *fp2 = fopen(path2, mode);
	if(fp1 == NULL)
	{
		cout<<"\nUnable to open the mentioned file "<<path1;
		exit(0);
	}
	else if(fp2 == NULL)
	{
		cout<<"\nUnable to open the mentioned file "<<path2;
		exit(0);
	}
	cout<<"\nBP : 4";
	for(int num = 1; num <= NUM_FRAMES; num++)
	{
		cout<<"\nFrame "<<num;
		for(int h = 0; h < height; h++)
		{
			cout<<"\nRow "<<h;
			fread(in_buffer1, sizeof(char), WIDTH, fp1);
			fread(in_buffer2, sizeof(char), WIDTH, fp2);
			for(int w = 0; w < width; w++)
			{
				cout<<"\nColumn "<<w;
				int diff = absolute(in_buffer1[w] - in_buffer2[w]);
				if(diff)
				{
					diff_count[num-1]++;
					max_diff[w] = max_diff[w] < diff ? diff : max_diff[w];
				}
			}
		}
	}
	cout<<"\nBP : 5";
	for(int i=0; i<NUM_FRAMES; i++)
	{
		cout<<"\nFrame[ "<<i<<" ] : DIFFERENCE COUNT : "<<diff_count[i];
		cout<<"\nFrame[ "<<i<<" ] : MAXIMUM DIFFERENCE : "<<diff_count[i];
		total_diff_count += diff_count[i];
	}
	cout<<"\nBP : 6";
	cout<<"\nOverall NUM_DIFFERENCES : "<<total_diff_count;
	fclose(fp1);
	fclose(fp2);
	cout<<endl;
	return 0;
}