#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int N,K;
void print(long long int *karr,int l,int r);

/*QuickSort */
int partition(long long int *arr,int l,int r);
void quickSort(long long int *arr,int l ,int r);

/*Heap Sort Kth largest trick*/
void heapify(long long int *arr,int index);
void buildMaxHeap(long long int *arr,int l);
void heapify(long long int *arr,int index,int len)
{
//	printf("\n %s index :  %d \n ",__func__,index);
	int largest=index;
	int left=2*index;
	int right=2*index+1;
	if(left<len && arr[largest]<arr[left])	
	largest=left;
	if(right<len && arr[largest]<arr[right])
	 largest=right;
//	printf("\n largest = %d  index: %d \n",largest,index);
	if(largest!=index)
	{
//	printf("\n index : %d arr[i] : %lld arr[lar]: %lld\n",index,arr[index],arr[largest]); 
	int temp=arr[index];
	arr[index]=arr[largest];
	arr[largest]=temp;
//	printf("\n index : %d arr[i] : %lld arr[lar]: %lld\n",index,arr[index],arr[largest]); 
	heapify(arr,largest,len);
	}
}

void buildMaxHeap(long long int *arr,int len)
{
//	printf("\n %s  len: %d\n ",__func__,len);
	for(int i=floor(len/2)-1;i>=1;i--)
	{
	heapify(arr,i,len);
//	print(arr,1,len); 
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
//	int N,K;
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
	printf("\n Sorted array \n");
	quickSort(Larr,1,N*(N+1)/2);
	print(Larr,1,N*(N+1)/2);
	
	
	for(i=1;i<=K;i++)
		printf("%lld ",Larr[i]); printf("\n");
	*/
//	printf("\n Build Max Heap\n");
	buildMaxHeap(Larr,N*(N+1)/2+1);
//	print(Larr,1,N*(N+1)/2);
	 
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

int partition(long long int *arr,int l,int r)
{
	int pivot=r;
	int i=l-1;
	for(int j=l;j<r;j++)
	{
	if(arr[j]>=arr[pivot])
	{
	i++;
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	}
	}
	int temp1=arr[pivot];
	arr[pivot]=arr[i+1];
	arr[i+1]=temp1;
	return i+1;
}

void quickSort(long long int *arr,int l ,int r)
{
	if(l<r)
	{
	int p=partition(arr,l,r);
	quickSort(arr,l,p-1);
	quickSort(arr,p+1,r);	
	}

}

