/**
 * @uthor : Raman Jaiswal (vipram91@gmail.com)
 * Date: July 11,2016
 * Problem: Stock Maximize (DP) 
 * Problem Source: https://www.hackerrank.com/challenges/stockmax 
 */

#include<iostream>
#include<stdio.h>

int MAX(int a,int b){ return a<b?b:a;}

using namespace std;

int FUNC(int P, int SC, int *A, int i,int N)
{
    if(i==N) return P;

    int pf=FUNC(P-A[i],SC+1,A,i+1,N);
    int maxi=MAX(-1,pf);
    for(int j=0;j<=SC;j++)
    {
        maxi=MAX(maxi,FUNC(P+A[i]*j,SC-j,A,i+1,N)); 
    }
    return maxi;
}

int main()
{
    int T;
    freopen("stockmax.txt","r",stdin);
    scanf("%d",&T);

    while(T--)
    {
        int N,num=0;
        scanf("%d",&N);
        int *A=new int[N];
        for(int i=0;i<N;i++) {
            A[i]=0; 
            scanf("%d",&num);
            A[i]=num;
        }

        for(int i=0;i<N;i++) cout<<A[i]<<" "; cout<<endl;

        cout<<FUNC(0,0,A,0,N)<<endl;
        
    
    }
return 0;

}



