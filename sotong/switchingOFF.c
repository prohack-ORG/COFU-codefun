
#include<stdio.h>


int N,S;
int MEMO[10][10][10];
//int arr[]={0,1,2,3,10,12,16};
int arr[]={0,1,9,10,13,14};
int visited[10]={0};
int answer;
int mini(int a,int b)
{
	return a<b? a:b;

}
int abs(int a)
{
	return a<0 ? a*(-1):a;
}

int findLeftIndex(int k)
{
	int i;
	for(i=k-1;k>0;k--)
		if(!visited[i]) return i;
	return -1;
}

int findRightIndex(int k)
{
	int i;
	for(i=k+1;i<=N;i++)
		if(!visited[i]) return i;
	return -1;
}


int DP(int S,int P,int LR)
{
	if(visited[S]) return 0;
	if(LR==0) return 0;
	
	if(MEMO[P][S][LR]!=-1)
		return MEMO[P][S][LR];
	MEMO[P][S][LR]=abs(arr[P]-arr[S])*LR;

	visited[S]=1;
	int L=findLeftIndex(S);
	int R=findRightIndex(S);
	printf("\n calling for index= %d  prev= %d curr= %d  L= %d  R=%d",S,P,MEMO[P][S][LR],L,R);
	answer+=MEMO[P][S][LR];
	int left=0,right=0;
	if(L>0)
		left=DP(L,S,LR-1);
	if(R>0)
		right=DP(R,S,LR-1);

	printf("\n returning %d %d %d ",MEMO[P][S][LR],left, right);
	if(L==-1 && R==-1)
		return MEMO[P][S][LR];

	if(L==-1 && R!=-1)
		return MEMO[P][S][LR]+right;

	if(R==-1 && L!=-1)
		return MEMO[P][S][LR]+left;

	return MEMO[P][S][LR]+mini(left,right);

}

int main()
{

	N=5;
	S=3;
	int i,j,k;
	for(i=0;i<=N;i++)
	{
		visited[i]=0;
		for(j=0;j<=N;j++)
			for(k=0;k<=N;k++)
				MEMO[i][j][k]=-1;
	}
	answer=0;
	int ans=DP(S,S,N);
	printf("\nans= %d\n\n",answer);

	return 0;
}


