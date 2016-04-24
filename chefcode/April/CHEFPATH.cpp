#include<stdio.h>
#include<iostream>


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long N,M;
		scanf("%lld%lld",&M,&N);
		if(M==1 &&N>2 || M>2 && N==1)  	 printf("No\n"); 
		else if((M%2) && (N%2)) 	 printf("No\n"); 
		else printf("Yes\n");
		 


	}
	return 0;
}

