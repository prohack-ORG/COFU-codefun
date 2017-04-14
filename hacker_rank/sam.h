#include <iostream>
#include <stdio.h>

using namespace std;

void print(int *a, int n)
{
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int T;
	int N;
	freopen("input_sam.txt","r", stdin);
	cin>>T;
	for(int k=1; k<=T; k++)
	{
		cin>>N;
		int temp = N;
		int *arr = new int[N];
		int i = 0;
		while(temp)
		{
			arr[i++] = temp%10;
			temp = temp/10;
		}
		print(temp, i);
	}
	cout<<endl;
	return 0;
}