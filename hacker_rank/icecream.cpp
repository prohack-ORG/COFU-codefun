#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int T;	// testCase
int M;	//budget
int  N;	//flavours

void swap(int *v, int a, int b)
{
	int temp = v[b];
	v[b] = v[a];
	v[a] = temp;
}
void qsort(int *v, int *loc, int left, int right) {
    int i, last;
    

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    swap(loc, left, (left + right)/2);
	
    last = left;
    for (i = left+1; i <= right; i++)
        if (v[i] - v[left] < 0) /* Here's the function call */
		{
			swap(v, ++last, i);
			swap(loc, last, i);
		}
	
    swap(v, left, last);
    swap(loc, left, last);

    qsort(v, loc, left, last-1);
    qsort(v, loc, last+1, right);
}

void swapping(int **a,int x,int y)
    {
        int t1=a[x][0];
        a[x][0]=a[y][0];
        a[y][0]=t1;
        int t2=a[x][1];
        a[x][1]=a[y][1];
        a[y][1]=t2;
   // print(a,0,N-1);
}

int partition(int *a,int *loc, int l,int r)
    {
        int p=r;//l+rand()%(r-l+1);
        int i=l-1;
        for(int j=l;j<r;j++)
            {
            if(a[j]<=a[p])
                {
                i++;
                swap(a,i,j);
                swap(loc,i,j);
                }
            }
        if(a[i+1]!=a[p]) 
		{
			swap(a,i+1,p);
			swap(loc,i+1,p);
		}
    //print(a,0,N-1);
        return i+1;
}

void qSort(int *a,int *loc, int l,int r)
    {
    if(l<r)
        {
        int p=partition(a,loc,l,r);
        qSort(a,loc,l,p-1);
        qSort(a,loc,p+1,r);
    }
}

int loc1, loc2;

void print(int *a)
{
	cout<<endl;
	for(int i=0; i<N; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void locate(int  *a)
{
	int *loc = new int[N];
	for(int i=0;i<N;i++)
		loc[i] = i;
	print(a);
	// print(loc);
	qSort(a, loc, 0, N-1);
	print(a);
	print(loc);
	for(int i=1;i<N;i++)
	{
		loc1 = loc[0];
		loc2 = loc[i];
		if(a[0] + a[i] >= M)
			break;
		// else if(a[0] + a[i] == M)
			// return;
	}
	for(int i=loc1;i<loc2-1;i++)
		for(int j=loc1+1;j<loc2;j++)
			if(a[i] + a[j] == M && loc[i] != loc[j])
			{
				cout<<endl<<loc[i]<<" "<<loc[j];
				loc1 = (loc1 > loc[i]) ? loc[i] : loc1;
				loc2 = (loc2 > loc[j]) ? loc[j] : loc2;
				// break;
			}
}

int main()
{
	freopen("input_iceCream.txt", "r", stdin);
	cin>>T;
	for(int test = 0; test < T; test++)
	{
		cin>>M>>N;
		int *cost = new int[N];
		
		for(int i=0;i<N;i++)
			cin>>cost[i];
		// print(cost);
		int flag = 0;
		for(int i=0;i<M-1 && !flag;i++)
		{
			loc1 = i;
			for(int j = i+1; j< M; j++)
				if(cost[j] == M-cost[i])
				{
					flag = 1;
					loc2 = j;
					break;
				}
		}
		// if(loc1<loc2)
		cout<<loc1+1<<" "<<loc2+1<<endl;
		// else
			// cout<<loc2<<" "<<loc1<<endl;
		
		delete[] cost;
	}
	return 0;
}