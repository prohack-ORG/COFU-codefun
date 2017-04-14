#include <iostream>
#include <cassert>
#include <cstdio>
using namespace std;

int main()
{
	char str[] = "this is cool";
	FILE *fp = fopen("a.txt","wb");
	if(fp == NULL)
		cout<<"\nOpen Fail";
	
	assert(NULL != fp);
	
	fwrite(str, sizeof(char), sizeof(str), fp);
	fclose(fp);
	return 0;
}