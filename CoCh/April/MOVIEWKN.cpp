#include<iostream>
#include<limits.h>
using namespace std;

int main()
{

int T;
cin>>T;
while(T--)
{
int n;
cin>>n;
int *l=new int[n], *r=new int[n];
for(int i=0;i<n;i++)
	cin>>l[i];
int index=-1;
int max=INT_MIN;
for(int i=0;i<n;i++)
	{
	cin>>r[i];
	if(max<l[i]*r[i])
		max=l[i]*r[i], index=i;
	if(max==l[i]*r[i] && r[i]>r[index])
		max=l[i]*r[i], index=i;
	

}
cout<<index+1<<endl;
}
return 0;
}
