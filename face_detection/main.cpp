/*

	Author : Siddheshwar P Sharma
	Date   : 28th June 2016
	Face Detectinon main Wrapper

*/

#include <iostream>
#include <stdio.h>
#include <malloc.h>

#define NUM 10
#define WIDTH 50
#define HEIGHT 50

using namespace std;

class test_image
{
	int width, height;
	unsigned char* src_image;

public:
	test_image()
	{
		width  = WIDTH;
		height = HEIGHT;
		src_image = (unsigned char *)malloc(sizeof(unsigned char )*width*height);
	}	
	bool readImage(char *name);
	void printImage();
};

bool test_image :: readImage(char *name)
{
	FILE *fp = fopen(name,"r");
	if(fp == NULL)
	{
		cout<<"\nError image file reading : "<<name;
		return false;
	}
	fread(src_image, width*height, sizeof(unsigned char), fp);
	return true;
}

void test_image :: printImage()
{
	for(int i=0;i<height;i++)
	{
		cout<<endl;
		for(int j=0;j<width;j++)
			cout<<*(short*)(src_image + i*width + j)<<" ";
	}
}

int main()
{
	test_image t[NUM];
	char name[20] ;
	for(int i=1; i<= NUM; i++)
	{
		sprintf(name,"image%d.png",i);
		int result = t[i].readImage(name);
		if(result)
		{
			cout<<"\nSuccess";
			//t.printImage();
		}
		else
			cout<<"\nFailure";
	}
	cout<<"endl";
	return 0;
}
