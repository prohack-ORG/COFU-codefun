/* https://www.hackerrank.com/challenges/savita-and-friends */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX_INT ~(1<<31)
int getMinimum(int *dist,bool *visited,int N){
	int min=MAX_INT,idx;
	for(int i=0;i<N;i++)
		if(!visited[i] && min>dist[i])
			min=dist[i],idx=i;
	return idx;
}
bool AllVisited(bool* visited,int N){
	for(int i=0;i<N;i++) 
		if(!visited[i]) return false;
	return true;   
}
void DijkstraAlgo(int **Graph, int sA,int sB,float *output, int N){
	bool *visitedA= new bool [N];
	bool *visitedB= new bool [N];
	int *distA = new int[N];
	int *distB = new int[N];

	for(int i=0;i<N;i++){
		visitedA[i]=false,distA[i]=MAX_INT;//,MaximumVia[i]=-1;
		visitedB[i]=false,distB[i]=MAX_INT;//,MaximumVia[i]=-1;
	}
	distA[sA]=0;
	distB[sB]=0;
	while(!AllVisited(visitedA,N) || !AllVisited(visitedB,N)){
		int indA= getMinimum(distA,visitedA,N);
		int indB= getMinimum(distB,visitedB,N);
		visitedA[indA]=true;
		visitedB[indB]=true;
		for(int i=0;i<N;i++){
			if(!visitedA[i] && Graph[indA][i] && distA[i]>distA[indA]+Graph[indA][i]){
				distA[i]=distA[indA]+Graph[indA][i];
			}
			if(!visitedB[i] && Graph[indB][i] && distB[i]>distB[indB]+Graph[indB][i]){
				distB[i]=distB[indB]+Graph[indB][i];
			}
		}

	}
	int maxA=0,maxB=0;
	if(distA[sB]<Graph[sA][sB]){
		maxA=0;maxB=0; 
		for(int i=0;i<N;i++){
			if( distB[i]>=maxB) 
				maxB=distB[i];
			if(maxA<=distA[i])
				maxA=distA[i];
		}
		printf("\n6  %s  maxA=%d maxB=%d OldDist=%d NewDist=%d \n",__func__,maxA,maxB,Graph[sA][sB],distA[sB]);
		if(maxA<= maxB)
			output[0]=0, output[1]= maxA;
		else if(maxB< maxA)
			output[0]=Graph[sA][sB], output[1]=maxB;
	}  
	else if (distA[sB]>=Graph[sA][sB]){
		maxA=0;maxB=0; 
		for(int i=0;i<N;i++){
			if(i!=sB || i!=sA)
				if( distA[i]>=distB[i]) 
					maxB=maxB>distB[i]? maxB: distB[i];
				else if(distA[i]<distB[i])
					maxA=maxA>distA[i]? maxA:distA[i];

		}  
		printf("\n6  %s  maxA=%d maxB=%d OldDist=%d NewDist=%d \n",__func__,maxA,maxB,Graph[sA][sB],distA[sB]);
		if(maxA>= maxB+Graph[sA][sB])
			output[0]=0, output[1]= maxA;
		else if(maxB> maxA+Graph[sA][sB])
			output[0]=Graph[sA][sB], output[1]=maxB;
		else{
			float temp =(float) (maxA+maxB+Graph[sA][sB])/2.0;
			output[0]= temp-(float)maxA;
			output[1]=temp;
		}
	}
	/*	else
		{
		maxA=0;maxB=0; 
		for(int i=0;i<N;i++)
		{
		if(i!=sB || i!=sA)
		if( distA[i]>=distB[i]) 
		maxB=maxB>distB[i]? maxB: distB[i];
		else if(distA[i]<distB[i])
		maxA=maxA>distA[i]? maxA:distA[i];

		}  
		printf("\n6  %s  maxA=%d maxB=%d OldDist=%d NewDist=%d \n",__func__,maxA,maxB,Graph[sA][sB],distA[sB]);
		if(maxA<=maxB)
		output[0]=0, output[1]= maxA;
		else if(maxB< maxA)
		output[0]=Graph[sA][sB], output[1]=maxB;

		}*/
	delete(distA);
	delete(distB);
	delete(visitedA);
	delete(visitedB);    
}

int main(){

	freopen("input_savita.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){

		int N,M,K,i,j,sA,sB,A=0,B=0,C=0;
		scanf(" %d %d %d",&N,&M,&K);
		int **Graph=new int*[N];

		for(i=0;i<N;i++){
			Graph[i]=new int[N];
			memset(Graph[i], 0, sizeof(int)*N);
		}
		for(i=0;i<M;i++){
			scanf(" %d %d %d",&A,&B,&C);
			Graph[B-1][A-1]=C;
			Graph[A-1][B-1]=C;
			if(i+1==K){
				sA=A-1,sB=B-1;
			}          
		}
		float *output= new float[2];        
		DijkstraAlgo(Graph, sA, sB,output, N);
		printf("%0.5f %0.5f\n",output[0],output[1]);

		for(int i = 0; i < N; ++i) {
			delete [] Graph[i];
		}
		delete [] Graph;
	}
	return 0;
}






