/*

	Author : Siddheshwar P Sharma
	Date   : 28th June 2016
	Face Detectinon main Wrapper

*/

#include <iostream>
#include <stdio.h>
#include <malloc.h>

#define NUM_IMAGES 10
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

class Face_train
{
	int width, height;
	int NUM;
	test_image *t;
	unsigned char **training_set;
public :
	Face_train(int w, int h, int num_images)
	{
		NUM = num_images;
		width = w;
		height = h;
		t = (test_image *)malloc(sizeof(test_image)*NUM);
		train_set = (unsigned char *)malloc(sizeof(unsigned char *)*width*height);
	}
	void readDataset(char *path)
	{
		char name[100] ;
		for(int i=1; i<= NUM; i++)
		{
			sprintf(name,"%s/image%d.png",path,i);
			int result = t[i].readImage(name);
			if(result)
				cout<<"\nSuccess";
			else
				cout<<"\nFailure";
		}
	}
	
	void createBaseMatrix()
	{
		for(int i=0;i<width*height;i++)
		{
			train_set[i] = (unsigned char *)malloc(sizeof(unsigned char)*NUM);
			for(int j=0;j<NUM;j++)
				train_set[i][j] = *(t[j].src_image[i/height][i%width];
		}
	}
};

int main()
{
	Face_train fTrain(WIDTH, HEIGHT, NUM_IMAGES);
	fTrain.resdDataset("data/");
	cout<<"endl";
	return 0;
}
