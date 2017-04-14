/* 

	Author : Siddheshwar P Sharma
	Date    : 26th Oct 2016
	input   : input_juice.txt

	
	o/p     : 
		
		106811
		238626
		17629

*/

#include <iostream>
#include <stdio.h>

using namespace std;

int T;	// Number of test cases
int F;   // Weight of filled cup
int E;   // Weight of empty cup
int N;   // Number of juices
int W;  // Weight for which minCost is to be found
int *DP; // array to store DP of weights
int *price; // array to store price of weights
int *weight; // array to store weight of juices
int cost = 1<<30;

int find_min(int a, int b){
	return a<b ? a: b;
}

int dp_calc(int w, int pos){
	if(w<=0)
		return 0;
	// cout<<"\n1 For W: "<<w;
	if(DP[w] != 1<<30){
		return DP[w] ;
	}
	for(int i=pos;i<=N;i++){
		DP[w] = find_min(DP[w], (dp_calc(w-weight[i], i) + price[weight[i]]));
	}		
	return DP[w];
}


void calc(int w, int p, int pos){
	if(w<0)
		return ;
	// cout<<"\n2 For W: "<<w<<" "<<pos;
	if(w == 0)	{
		cost = find_min(cost, p);
		return ;
	}
	if(p > cost)
		return ;
	for(int i=pos; i<=N; i++){
		if(weight[i] > w)
			continue;
		calc(w-weight[i], p+ price[weight[i]],i);
		calc(w, p,i+1);
	}		
}
int main(){
	freopen("input_juice.txt","r",stdin);
	cin>>T;
	for(int test=0; test<T; test++){
		cin>>E>>F;
		cin>>N;
		W = F - E;
		cost = 1<<30;
		int temp;
		DP  = new int[W+1];
		price  = new int[W+1];
		weight = new int[N+1];
		for(int i=1 ; i<=W; i++){
			DP[i] = 1<<30;
			price[i]=1<<30;
		}
		DP[0] = 0;
		price[0] = 0;
		weight[0] = 0;
		for(int i=1; i<=N; i++){
			cin>>temp>>weight[i];
			// DP[weight[i]]  = temp;
			price[weight[i]]  = temp;
		}
		/* cout<<endl;
		for(int i=1; i<=N; i++)
			cout<<weight[i]<<" ";
		cout<<endl;
		for(int i=1; i<=N; i++)
			cout<<DP[weight[i]]<<" ";
		  */
		dp_calc(W, 1);
		cout<<"\ntest_case "<<test+1<<" ans : "<<DP[W]<<endl;
		// for(int i=1; i<=W; i++)
			// cout<<endl<<i<<" "<<DP[i];
		// cout<<DP[W]; 
		
		calc(W, 0, 1);
		cout<<"\ntest_case "<<test+1<<" ans : "<<cost<<endl;
		delete[] weight;
		delete[] DP;
	}
	cout<<endl;
	return 0;
}

