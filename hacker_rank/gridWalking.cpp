#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int T, N;
int M;
int D[11];
int x[11];

long travel(long dp[], int dim, int pos, int step)
{
	// cout<<"\n"<<dim<<" "<<pos<<" "<<step;
	if(dp[(dim*101+pos)*301+M-step]>0)
	{
		// cout<<"\t existing value :"<<dp[(dim*101+pos)*301+M-step];
		return dp[(dim*101+pos)*301+M-step];
	}
	// print();
	if(step == M)
	{
		// count = (count+1)%1000000007;
		dp[(dim*101+pos)*301+M-step] = (dp[(dim*101+pos)*301+M-step] + 1);
		// cout<<"\t Success"<<endl;
		// cout<<"\t calcuated value :"<<dp[dim*10+pos][step];
		return dp[(dim*101+pos)*301+M-step];
	}
    int temp1 = 0;
    int temp2 = 0;
	for(int i=1;i<=N;i++)
	{
        //if(x[i]<=D[i] && x[i]>0)
        {
		    x[i] = x[i]+1;
            if(x[i]<=D[i])
			    temp1 += (dp[(dim*101+pos)*301+M-step] + travel(dp, i, x[i], step+1));
		    x[i] = x[i]-1;
       /* }
		
		if(x[i]>0)
        {*/
            x[i] = x[i]-1;
            if(x[i]>0)
			    temp2 += (dp[(dim*101+pos)*301+M-step] + travel(dp, i, x[i], step+1));
		    x[i] = x[i]+1;
        }
	}
    dp[(dim*101+pos)*301+M-step] = temp1 + temp2;
	// cout<<"\t calculating value :"<<dp[dim*10+pos][step];
    return dp[(dim*101+pos)*301+M-step];
}

int main()
{
	freopen("input_gridWalk.txt","r",stdin);
	cin>>T;
	for(int test = 0; test < T; test++)
	{
        // count=0;
		long dp[334410];
		for(int i=0;i<334410;i++)
			   dp[i] = 0;

	   cin>>N>>M;
		for(int i=1;i<=N;i++)
		{
			cin>>x[i];
			//x[i] = x[i];
		}
		for(int i=1;i<=N;i++)
			cin>>D[i];
		// cout<<endl;
		cout<<travel(dp,1,1,0)%1000000007<<endl;
        //cout<<dp[D[0]*10+x[0]][M]<<endl;
		//cout<<count<<endl;

	}
	return 0;
}