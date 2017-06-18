#include<iostream>
#include<stdio.h>
using namespace std;


int main()
{
    int T;
// freopen("input.txt","r",stdin);	   
 cin>>T;
    while(T--)
    {
        int N,sum=0; string s;
        cin>>N>>s;
        for(int i=0;i<N;i++)
        {
            string s1; int num;
            cin>>s1;
            if(s1=="CONTEST_WON")
            {
                cin>>num;if(num>20) num=20; sum+=300+(20-num);
            }
            else if(s1=="TOP_CONTRIBUTOR")
            {
                sum+=300;
            }
            else if(s1=="BUG_FOUND") 
            {
                cin>>num; sum+=num;
            }
            else if(s1=="CONTEST_HOSTED")
            {
                sum+=50;
            }

        }
        int ans=0;
        if(s=="INDIAN") ans=sum/200; 
        else if(s=="NON_INDIAN") ans=sum/400;
        cout<<ans<<endl;
    }

    return 0;
}
