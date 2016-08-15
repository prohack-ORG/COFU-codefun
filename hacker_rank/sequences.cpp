#include <iostream>
#include <stdio.h>

using namespace std;

int N;
long count;
int num_pos = 0;

void print(int *a, int n)
{
	cout<<"\n"<<__func__;
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	
}

int check(int *a)
{
	cout<<"\n"<<__func__;
	print(a, N);
	for(int m=0;m<N;m++)
		for(int k=0;k<m; k++)
			if(m%(k+1) == 0 && m<(k) && (a[m]%(k+1) != a[k]))
			{
				cout<<"\nm : "<<m<<"  k: "<<k;
				cout<<endl<<a[m]%k <<" "<< a[k];
				cout<<"\na["<<m<<"] : "<<a[m]<<"\ta["<<k<<"] : "<<a[k];
				return 0;
			}
	return 1;
}

void calc(int *a, int *pos, int loc)
{
	cout<<"\n"<<__func__;
	if(loc == num_pos)
	{
		if(check(a))
			count = (count+1)%1000000007;
		return;
	}
	for(int j=0; j<pos[loc]; j++)
	{
		a[pos[loc]] = j;
		calc(a, pos, loc+1);
	}
}

int main()
{
	freopen("input_sequences.txt","r",stdin);
	cin>>N;
	int *a = new int[N];
	int *pos = new int[N];
	for(int i=0; i<N; i++)
	{
		cin>>a[i];
		if(a[i] == -1)
			pos[num_pos++] = i;
	}
	print(pos, num_pos);
	calc(a, pos, 0);
	cout<<count;
	return 0;
}