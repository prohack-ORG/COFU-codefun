/*

	Author : Siddheshwar P Sharma
	Date   : 28th June 2016
	Face Detectinon main Wrapper

*/

#include <iostream>
#include <stdio.h>
#include <malloc.h>

#define NUM_IMAGES 5 
#define WIDTH 5 
#define HEIGHT 5

//#define MANUAL_TEST_INPUT 0  // to enable manual inputs

using namespace std;

static int count=1;

char absolute_val(char val)
{
	return val<0 ? -val : val;
}

void printMatrix(unsigned char *src_image, int width, int height)
{
	cout<<endl;
	//cout<<"in "<<__func__<<" "<<width<<" "<<height;
	for(int i=0;i<height;i++)
	{
		printf("\n");	
		for(int j=0;j<width;j++)
			printf("%x ",*(src_image + i*width + j));
	}
}

class test_image
{
	int width, height;

public:
	unsigned char* src_image;
	void init(int w, int h)
	{
		width  = w;
		height = h;
		src_image = (unsigned char *)malloc(sizeof(unsigned char )*width*height);
	}	
	bool readImage(char *name);
};

bool test_image :: readImage(char *name)
{
#ifdef MANUAL_TEST_INPUT
	count++;
	for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
			*(src_image + i*width +j) = (((i+j+1)*7*count)%10); 
#else

	FILE *fp = fopen(name,"r");
	if(fp == NULL)
	{
		cout<<"\nError image file reading : "<<name;
		return false;
	}
	
	fread(src_image, width*height, sizeof(unsigned char), fp);
	cout<<"\nSuccess : "<<name;
	fclose(fp);
#endif
	//printMatrix(src_image, width, height);
	return true;
}


class Face_train
{
	int width, height;
	int NUM;
	test_image *t;
	unsigned char *training_set;
	unsigned char *covMatrix;
public :
	Face_train(int w, int h, int num_images)
	{
		NUM = num_images;
		width = w;
		height = h;
		t = (test_image *)malloc(sizeof(test_image)*NUM);
		training_set = (unsigned char *)malloc(sizeof(unsigned char )*width*height*NUM);
		covMatrix = (unsigned char *)malloc(sizeof(unsigned char )*NUM*width*height);
		for(int i=0;i<NUM*width*height;i++)
			covMatrix[i] = 0;
	}
	void readDataset(char *path)
	{
		char name[100] ;
		for(int i=1; i<= NUM; i++)
		{
			sprintf(name,"%simage%d.bw",path,i);
			t[i].init(width, height);
			int result = t[i].readImage(name);
			if(!result)
				cout<<"\nFailure";
		}
	}
	
	void createBaseMatrix()
	{
		for(int i=0;i<width*height;i++)
			for(int j=1;j<=NUM;j++)
				*(training_set+i*NUM+j-1) = *(t[j].src_image + i);//(i/height) *width + (i%width));
	}
	
	void printTest_Images()
	{
		for(int i=1;i<= NUM; i++)
			printMatrix(t[i].src_image, width, height);
		printMatrix(training_set, NUM, width*height);
	}
	
	void calculateDeviation()
	{
		int tempVal=0;
		for(int i=0;i<width*height;i++)
		{
			tempVal = 0;
			for(int j=0;j<NUM;j++)
				tempVal+=*(training_set+i*NUM+j);
			tempVal = tempVal/NUM;
			for(int j=0;j<NUM;j++)
				*(training_set+i*NUM+j) = absolute_val(tempVal-*(training_set+i*NUM+j)) ;
		}
		printMatrix(training_set, NUM, width*height);
	}
	
	void covarianceMatrix()
	{
		unsigned char *temp = (unsigned char *)malloc(sizeof(unsigned char )*width*height*NUM);
		for(int i=0;i<width*height;i++)
		{
			for(int j=0;j<NUM;j++)
				*(temp+j*width*height+i) = *(training_set+i*NUM+j);
		}
		printMatrix(temp, width*height, NUM);
		for(int i=0;i<NUM;i++)
			for(int j=0;j<NUM;j++)
				for(int k=0;k<width*height;k++)
					*(covMatrix+i*NUM+j) += *(temp+i*width*height+k)*(*training_set+k*width*height+j);
		printMatrix(covMatrix, NUM, NUM);
	}
};

int main(int argc, char **argv)
{
	Face_train fTrain(WIDTH, HEIGHT, NUM_IMAGES);
	char path[100];
	sprintf(path,"data/");
	fTrain.readDataset(path);
	fTrain.createBaseMatrix();
	fTrain.printTest_Images();
	fTrain.calculateDeviation();
	fTrain.covarianceMatrix();
	cout<<endl;
	return 0;
}