#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int n;
int count = 0;
int abs(int a)
{
	return a<0 ? -a : a;
}

void  print(int *a)
{
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int check(int *x, int *y, int *vy, int *p)
{
	int flag = 1;
	int *temp = new int[n];
	for(int i=0; i<n; i++)
		temp[i] = x[i];
	qsort(temp, n, sizeof(n), compare);
	for(int i=0; i<n; i++)
		if(temp[i] != y[i])
		{
			if(flag)
				*p = i;
			vy[i] = 0;
			flag = 0;
			//break;
		}
		else
			vy[i] = 1;
		
	// print(temp);
	// print(y);
	// print(vy);
	// cout<<"\n Pivot : "<<*p<<endl;
	delete[] temp;
	return flag;
}

int move(int *x, int *y, int *pivot)
{
	int *vx = new int[n];
	int *vy = new int[n];
	for(int  j=0; j<n; j++)
		vx[j] = 0, vy[j] = 0;
	
	// print(vx);
	// print(vy);
	int status = 0;
	for(int i=*pivot;i<n && !status;i++)
		for(int  j=*pivot; j<n; j++)
			if(x[i]-y[j] && x[i] != y[j]  && !vx[i]  && !vy[j])
			{
				int flag = 0;
				
				for(int k=*pivot+1;k<n && !flag; k++)
					for(int  l=*pivot+1; l<n; l++)
						// if(data[k][l] == -1*data[i][j])
						if(!vx[k] && !vy[l] && (x[k]-y[l]) == -1*(x[i]-y[j]))
						{
							flag = 1;
							count += abs(x[i]-y[j]);
							// print(x);
							// print(y);
							// cout<<"\ni :"<<x[i]<<" k :"<<x[k];
							// cout<<"\nj : "<<y[j]<<" l: "<<y[l];
							x[i] = y[j];
							x[k] = y[l];
							vx[i]  = 1;
							vx[k] = 1;
							//vy[j]  = 1;
							//vy[l] = 1;
							// print(x);
							// print(y);
							// cout<<"\n";
							break;
						}
						
				//qsort(x, n, sizeof(n), compare);
				//qsort(y, n, sizeof(n), compare);
				status = check(x, y, vy, pivot);
				// print(vx);
				i = *pivot;
				if(status)
					break;
			}
		delete[] vx;
		delete[] vy;
		return status;
}

int main()
{
	int val;
	freopen("input_boxMoving.txt","r",stdin);
	cin>>n;
	int *x = new int[n];
	int *y = new int[n];
	int *t = new int[n];

	for(int i=0; i<n; i++)
		cin>>x[i];

	for(int i=0; i<n; i++)
		cin>>y[i];

	qsort(x, n, sizeof(n), compare);
	qsort(y, n, sizeof(n), compare);
	// print(x);
	// print(y);
	int pivot;
	if(check(x, y, t, &pivot)) // last parameter dummy
	{
		cout<<"0";
		return 0;
	}
	delete[] t;
	val = move(x,  y, &pivot);
	
	if(!val)
		cout<<"-1";
	else
		cout<<count;
	delete[] x;
	delete[] y;
	return 0;
}