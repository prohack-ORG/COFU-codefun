#include<iostream>
#include<stdio.h>

using namespace std;
int N,W,L;

int main()
{
freopen("input2.txt","r",stdin);
cin>>N>>W>>L;
int **arrayTree=new int*[N];
for(int i=0;i<N;i++)
{
 arrayTree[i]=new int[2];
 cin>>arrayTree[i][0]>>arrayTree[i][1];	
 cout<<"\n"<<arrayTree[i][0]<<" "<<arrayTree[i][1];	
}
cout<<endl;
return 0;
}
