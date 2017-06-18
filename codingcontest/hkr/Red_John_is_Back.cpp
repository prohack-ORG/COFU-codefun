/*
 *
 *Section: DP
 *
 * */

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int arr[45];
int TilingDP(int N)
{
    if(N<5) return arr[N];
    for(int i=5;i<=N;i++)
        arr[i]=arr[i-1]+arr[i-4];
    return arr[N];
}

bool isPrime(int N)
{
    if(N==2) return true;
    for(int i=3;i<=sqrt((double)N);i+=2)
        if(N%i==0) return false;
    return true;
}

int numberOfPrime(int N)
{
    int count=0;
    if(N<2) return count;
    if(N>=2)  count++;
    for(int i=3;i<=N;i+=2)
        if(isPrime(i))
            count++;
    return count;
}
int main()
{
    int T;
    freopen("inputs/red_john_back.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
       // N=40;
        int A[41]={0,1,1,1,2,3,4,5,7,10,14,19,26,36,50,69,95,131,181,250,345,476,657,907,1252,1728,2385,3292,4544,6272,8657,11949,16493,22765,31422,43371,59864,82629,114051,157422,217286};

        int B[41]={ 0,0,0,0,1,2,2,3,4,4,6,8,9,11,15,19,24,32,42,53,68,91,119,155,204,269,354,462,615,816,1077,1432,1912,2543,3385,4522,6048,8078,10794,14475,19385};
        /*
         * for(int i=0;i<=N;i++)
            B[i]=numberOfPrime(A[i]);
         N=40;
           arr[0]=0,arr[1]=1,arr[2]=1,arr[3]=1,arr[4]=2;
           for(int i=5;i<=N;i++)
           arr[i]=0;
           int M=TilingDP(N);
           }
           
        cout<<"\n{ ";
        for(int i=0;i<=N;i++) cout<<A[i]<<","; cout<<"}\n\n";

        cout<<"\n{ ";
        for(int i=0;i<=N;i++) cout<<B[i]<<","; cout<<"}\n\n";
        */
        cout<<B[N]<<endl;
    }
return 0;
}
