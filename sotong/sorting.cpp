#include<iostream>
#include<stdio.h>
#include<limits.h>

using namespace std;

void print(int *arr,int l,int r)
{
    for(int i=l;i<=r;i++)
        cout<<" "<<arr[i]; cout<<endl;
}


int partition(int *arr,int l,int r)
{
    int pivot=r;
    int i=l-1;
    int j;
    while(j<r)
    {
        while(arr[j]<=arr[pivot])	
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        
        }
        while(arr[j]>arr[pivot])
        j++;
    }
    int temp=arr[i+1];
    arr[i+1]=arr[pivot];
    arr[pivot]=temp;
    return i+1;
}

void quickSort(int *arr, int l,int r)
{
    // if(l==r) return;
    if(l<r)
    {
        int pivot_index=partition(arr,l,r);
        print(arr,l,r);
        quickSort(arr,l,pivot_index-1);
        quickSort(arr,pivot_index+1,r);
    }
}

int main()
{
    int arr[]= {6,5,1,3,8,4,7,9,2};
    print(arr,0,8);
    quickSort(arr,0,8);
    print(arr,0,8);
    return 0;
}
