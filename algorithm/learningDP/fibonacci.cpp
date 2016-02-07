#include<iostream>
#include<stdio.h>
#include<string.h>
#define DP_SOLUTION 1


int MEMO[100]={-1};

#if DP_SOLUTION
int fibonacci(int n)
{
if(!n) return 0;
if(n==1) return 1;
if(MEMO[n]!=-1) return MEMO[n];
int r=fibonacci(n-1)+fibonacci(n-2);
MEMO[n]=r;
return r;
}
#else
int fibonacci(int n)
{
if(!n) return 0;
if(n==1) return 1;

return fibonacci(n-1) + fibonacci(n-2);
}
#endif

int main()
{
memset(MEMO,-1,sizeof(MEMO));
printf("\n fib of 0 =%d", fibonacci(0));
memset(MEMO,-1,sizeof(MEMO));
printf("\n fib of 1 =%d", fibonacci(1));
memset(MEMO,-1,sizeof(MEMO));
printf("\n fib of 5 =%d", fibonacci(5));
memset(MEMO,-1,sizeof(MEMO));
printf("\n fib of 9 =%d", fibonacci(9));
return 0;
}
