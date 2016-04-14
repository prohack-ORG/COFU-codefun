#include<iostream>
#include<cmath>

using namespace std;
long long int arr[100000]={0};
long long int func(int Oddn)
{
    long long int sum=0;
    for(int i=1;i<=sqrt(Oddn);i+=2)

    {    if(!(Oddn%i))
        {
	sum+=i;
        if(i!=Oddn/i) sum+=(Oddn/i);
   }
	 }
    return sum;
}

int main()
{
    long long int sum=0;
    int T,l,r;
    cin>>T;
    while(T--)
    {
        cin>>l>>r;
        sum=0;
        for(int i=l;i<=r;i++)
        {
            if(i%2)
                arr[i]=func(i), sum+=arr[i];
            else{
                int in=i;
                while(!(in&1))    in>>=1;
                if(arr[in]) sum+=arr[in], arr[i]=arr[in];
                else arr[in]=func(in), sum+=arr[in];    
            }
        }

        cout<<sum<<"\n";

    }


    return 0;
}


