#include<stdio.h>
#include<iostream>


int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		long long R,G,B,K;
		scanf("%lld%lld%lld%lld",&R,&G,&B,&K);
		long long answer=0;
		answer+=(K-1)<R? K-1:R; 
		answer+=(K-1)<G? K-1:G; 
		answer+=(K-1)<B? K-1:B;
		answer+=1;
		printf("%lld\n",answer); 
	}
	return 0;
}
