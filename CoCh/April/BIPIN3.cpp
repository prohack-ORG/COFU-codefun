#include<stdio.h>
#include<iostream>
#define MOD 1000000007
long long  mul(long long n,long long k)
{
	long long ans;
	if(n==0) return 1;
	ans=mul(n/2,k);
	ans=ans*ans;
	ans%=MOD;	
	if(n&1) ans=ans*k;
	ans%=MOD;
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n,k,ans;
		scanf("%lld%lld", &n,&k);
		ans=mul(n-1,k-1);
		ans=k*ans;
		ans%=MOD;		
		printf("%lld\n",ans);
	}
	return 0;
}
