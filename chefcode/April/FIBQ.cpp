#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{

	int N,M;
	freopen("input.txt","r",stdin);
	scanf("%d%d",&N,&M);
	int *arr=new int[N];
//	for(int i=0;i<N;i++) 	cout<<arr[i]<<" "; cout<<endl;
	int a,b; char ch;
	for(int j=0;j<N;j++) 	 scanf(" %d" ,&arr[j]);
//	for(int i=0;i<N;i++)	 printf("%d " ,arr[i]);printf("\n");
	for(int i=0;i<M;i++) 
	{
		scanf(" %c%d%d\n" ,&ch,&a,&b);
		if(ch=='Q')
		{
			printf("\nquery %c %d %d \n",ch,a,b);		
		}
		else if(ch=='C')
		{
			printf("\nchange %c %d %d\n" ,ch,a,b);
		}
	}
	return 0;
}
