#include <iostream>
#include <stdio.h>

using namespace std;
int T, N;
int *rate;

long max(long a, long b)
{
	return a>b ? a: b;
}

long predict(int day, long sum, int stock)
{
	// cout<<"\nday : "<<day<<", sum : "<<sum<<", stock : "<<stock;
	if(day == N)
		return sum;
	long a = predict(day+1, sum, stock);
	long b = 0;
	long c = 0;
	if(rate[day+1] > rate[day])
		b = predict(day+1, sum-rate[day], stock+1);
	if(stock>0)
		c = predict(day+1, sum+rate[day]*stock, 0);
	// cout<<"\nif nothing : "<<a;
	// cout<<"\nif purchase : "<<b;
	// cout<<"\nif sell all : "<<c;
	long maxval =  max(max(a,b),c);
	// cout<<"\nRETURNING : "<<maxval;
	return maxval;
}

long linear()
{
	long sum = 0;
	int pos = N-1;
	
	for(int i=N-2;i>=0;i--)
		if(rate[pos] > rate[i])
			sum += (rate[pos] - rate[i]);
		else
			pos = i;
		
	// cout<<"\nRETURNING : "<<sum;
	return sum;
}

int main()
{
	freopen("input_stock.txt", "r", stdin);
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		rate = new int[N];
		for(int j=0;j<N;j++)
			cin>>rate[j];
		// cout<<predict(0, 0, 0)<<endl;
		cout<<linear()<<endl;
	}
	return 0;
}