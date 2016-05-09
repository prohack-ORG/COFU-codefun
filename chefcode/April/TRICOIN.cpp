#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
int T;
scanf("%d",&T);
while(T--)
{
int  N;
int i=0;
scanf("%d",&N);
int count=0,sum=0;
for( i=1;i*(i+1)/2<=N ;i++)
{
	count++;
}
printf("%d\n",count);

}
return 0;
}
