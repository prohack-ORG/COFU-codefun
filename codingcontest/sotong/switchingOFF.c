
#include<stdio.h>
#include<limits.h>

int N,S;
int MEMO[10][10][10];
//int arr[]={0,2,7,10};
//int arr[]={0,1,2,3,10,12,16};
int arr[]={0,1,9,10,13,14};
int visited[10]={0};
int answer;
int mini(int a,int b){	return a<b? a:b;}
int abs(int a){	return a<0 ? a*(-1):a;}
int findLeftIndex(int k){ int i;for(i=k-1;i>0;i--) if(!visited[i]) return i; return -1;}
int findRightIndex(int k){int i;for(i=k+1;i<=N;i++) if(!visited[i]) return i;return -1;}

int DP(int S,int P,int LR)
{
	int L,R,i,j;
	printf("\n %s (%d,%d,%d)  ",__func__,S,P,LR);
//	printf("\t { ");for(i=1;i<=N;i++) printf("%d ",visited[i]); printf("}-> { ");
	visited[S]=1;
//      for(i=1;i<=N;i++) printf("%d ",visited[i]); printf("}\n");
	if(LR==0) {return 1;}
	if(MEMO[P][S][LR]!=-1){
	printf("\n\tReuse %s (%d,%d,%d)= %d  ",__func__,S,P,LR,MEMO[P][S][LR]);
	 return MEMO[P][S][LR];
	 }

	 L=findLeftIndex(S);
 	 R=findRightIndex(S);
	printf("\n\t %s (%d,%d,%d)= %d  ",__func__,S,P,LR,abs(arr[P]-arr[S])*LR);
	int left,right;
	MEMO[P][S][LR]=abs(arr[P]-arr[S])*LR; 
	int answer=0;
	if(L!=-1) left=DP(L,S,LR-1);
	if(R!=-1) right=DP(R,S,LR-1);
	visited[S]=0;
	
	if(L!=-1 && R!=-1) 
		return	MEMO[P][S][LR] + mini(left,right) ;
	else if (L!=-1 && R==-1)
		return	MEMO[P][S][LR] +left;
	else if (R!=-1 && L==-1)
		return 	MEMO[P][S][LR]+right;
	else return MEMO[P][S][LR];

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
	int answer= DP(S,S,N);
	printf("\nans= %d  %d \n\n",MEMO[S][S][N],answer);

	return 0;
}


