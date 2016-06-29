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

void printMatrix(unsigned char *src_image, int width, int height)
{
	for(int i=0;i<height;i++)
	{
		cout<<endl;
		for(int j=0;j<width;j++)
			cout<<(*(src_image + i*width + j)-'0')<<" ";
	}
}

class test_image
{
	int width, height;

public:
	unsigned char* src_image;
	test_image()
	{
		width  = WIDTH;
		height = HEIGHT;
		src_image = (unsigned char *)malloc(sizeof(unsigned char )*width*height);
	}	
	bool readImage(char *name);
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


class Face_train
{
	int width, height;
	int NUM;
	test_image *t;
	unsigned char *training_set;
public :
	Face_train(int w, int h, int num_images)
	{
		NUM = num_images;
		width = w;
		height = h;
		t = (test_image *)malloc(sizeof(test_image)*NUM);
		training_set = (unsigned char *)malloc(sizeof(unsigned char )*width*height*NUM);
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
			//training_set[i] = (unsigned char *)malloc(sizeof(unsigned char)*NUM);
			for(int j=0;j<NUM;j++)
				*(training_set+i*NUM+j) = *(t[j].src_image + (i/height) *width + (i%width));
		}
	}
	
	void printTest_Images()
	{
		for(int i=0;i< NUM; i++)
			printMatrix(t[i].src_image, width, height);
		printMatrix(training_set, NUM, width*height);
	}
};

int main(int argc, char **argv)
{
	Face_train fTrain(WIDTH, HEIGHT, NUM_IMAGES);
	char path[100];
	sprintf(path,"data/");
	fTrain.readDataset(path);
	fTrain.printTest_Images();
	cout<<"endl";
	return 0;
}
