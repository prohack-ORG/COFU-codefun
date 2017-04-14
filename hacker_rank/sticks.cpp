/*

	not solved, copied from discussions 
	solution accepted but matmetical background work is not clear to me yet
	link : https://www.hackerrank.com/challenges/vertical-sticks
	input : input_sticks.txt

*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;

int T, N;
int per; 
int total;
void print(int *a, int n)
{
	cout<<endl;
	for(int i=1; i<=n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void print(long int *a, int n)
{
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int findprev(int *store, int val, int n)
{
	for(int i=n-1; i>=1; i--)
	{
		// cout<<endl<<store[i]<<" vs "<<val;
		if(store[i] >= val)
		{
			// cout<<"\n1 adding temp : "<<n-i;
			return n - i;
		}
	}
	// cout<<"\n2 adding temp : "<<n;
	return n;	
}

void permute(int *a, int *v, int pos, int score, int count, int *store)
{
	if(count == N)
	{
		total += score;
		per++;
		// print(store, N);
		// cout<<"\nscore : "<<score<<" *********\n";
		return;
	}
	for(int i=1; i<=N; i++)
		if(!v[i])
		{
			v[i] = 1;
			store[count+1] = a[i]; 
			// print(store, N);
			int temp = findprev(store, a[i], count+1);
			permute(a, v, i, score + temp, count+1, store);
			store[count+1] = 0; 
			v[i] = 0;
		}
}

int main1()
{
	freopen("input_sticks.txt","r",stdin);
	cin>>T;
	for(int k = 1; k <= T; k++)
	{
		cin>>N;
		int stick[51];
		int visited[51];		
		int store[51];		
		per = 0;
		total = 0;
		for(int i=1; i<=N; i++)
			cin>>stick[i];
		for(int i=1; i<=N; i++)
			visited[i] = 0, store[i] = 0;
		for(int i=1; i<=N; i++)
		{
			visited[i] = 1;
			store[1] = stick[i];
			permute(stick, visited, i, 1, 1, store);
			visited[i] = 0;
			store[1] = 0;
		}
		// cout<<"\n--------------------------------------------\n";
		printf("%0.2f\n",(float)(total)/(float)per);
		// cout<<"\n--------------------------------------------\n";
	}
	cout<<endl;
	return 0;
}
int main() {
    long int t,n,ar[50],i;
    long double ans=0;
	freopen("input_sticks.txt","r",stdin);
    cin>>t;
    while(t--)
        { cin>>n;
           for(i=0;i<n;i++)
               { cin>>ar[i];
               }
          sort(ar,ar+n);
		  print(ar, n);
         ans=(long double)1/(n+1);
         long int tmp=n;
         for(i=1;i<n;i++)
             { if(ar[i]==ar[i-1])
                 { ans+=(long double)1/(tmp+1);
                 }
              else
                  { tmp=n-i;
                    ans+=(long double)1/(tmp+1);
                  }
             }
         cout<<fixed<<setprecision(2)<<(n+1)*ans<<"\n";
        }
}