#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int N,K;
void print(long long int *karr,int l,int r);

/*Heap Sort Kth largest trick*/
void heapify(long long int *arr,int index,int len)
{
	int largest=index;
	int left=2*index;
	int right=2*index+1;
	if(left<len && arr[largest]<arr[left])	
	largest=left;
	if(right<len && arr[largest]<arr[right])
	 largest=right;
	if(largest!=index)
	{
	int temp=arr[index];
	arr[index]=arr[largest];
	arr[largest]=temp;
	heapify(arr,largest,len);
	}
}

void buildMaxHeap(long long int *arr,int len)
{
	for(int i=floor(len/2)-1;i>=1;i--)
	{
	heapify(arr,i,len);
	}
}


long long int extractTop(long long int *arr,int len,int i)
	{
	int temp=arr[1];
	arr[1]=arr[len-i];
	arr[len-i]=temp;
	heapify(arr,1,len-i-1);
	return temp;
}

int main()
{
	int i,j;
//	freopen("input.txt","r",stdin);
	long long int sum=0;
	scanf("%d%d",&N,&K);
	long long int *Larr=new long long int[N*(N+1)/2+1];
	for(i=1;i<=N*(N+1)/2;i++)
		Larr[i]=0;	
	for(i=1;i<=N;i++)
	{
		int num;
		scanf("%d",&num);
		Larr[i]=num;
	}
	int index=N+1;
	for(i=2;i<=N+1;i++)
	{
		for(j=N+1-i;j>0;j--)
		{
			if(j==(N+1-i))
			{
				Larr[index]=Larr[j]+Larr[j+1];
				index++;	
			}
			else 
			{
				Larr[index]=Larr[index-1]+Larr[j];
				index++;
			}	
		}
	}	
/*
	printf("\n Print array \n");
	print(Larr,1,N);
	print(Larr,1,N*(N+1)/2);
	*/
	buildMaxHeap(Larr,N*(N+1)/2+1);
	 
	for(int i=0;i<K;i++)
	{
	cout<<extractTop(Larr,N*(N+1)/2,i)<<" ";
	}	
	cout<<endl;
	return 0;
}
void print(long long int *karr,int l,int r)
{
	for(int k=l;k<=r;k++)
	printf(" %lld",karr[k]); printf("\n");
}

