#include<iostream>
#include<stdio.h>


int main()
{
	int N,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		//	char *Room= new char[N];
		char C;
		int i,R,G,B;
		R=0,G=0,B=0;
		for(i=0;i<=N;i++)
		{
			scanf("%c",&C);
			if(C=='R') ++R;
			else if(C=='G') ++G;
			else if(C=='B') ++B;	
		}
//		printf("\n\t%d %d %d\n ",R,G,B);
		int max1= R>G? R:G;
		max1=max1>B?max1:B;	
		printf("%d\n",N-max1);

	}
	return 0;
}
