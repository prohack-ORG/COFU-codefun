/*
    Matrix chain multiplication
    Siddheshwar P Sharma
    7th April - 8th April 2018
    Status : working perfectly
    recursive + dynamic Programming both approches
*/


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void printdp(int a[][100], int num){
    cout<<"\nDP :"<<endl; 
    for(int i=0; i<num; i++){
        cout<<endl;
        for(int j=0; j<num; j++)
            cout<<a[i][j]<<"\t";
    }
    cout<<endl;
}

int mcm_dp(int *a, int num){
    int dp[100][100];
    for(int i=0; i<num; i++)
        for(int j=0; j<=num; j++){
            dp[i][j] = INT_MAX;
            dp[i][i] = 0;
        }
    for(int i=0; i<num-1; i++)
        dp[i][i+1] = a[i]*a[i+1]*a[i+2];
    
    for(int len = 2; len<num; len++)
    for(int i=0; i+len<num; i++){
        int j=i+len;
        for(int k=i; k<j; k++){
            printf("dp[%d][%d] = min(dp[%d][%d], dp[%d][%d] + dp[%d][%d] + a[%d]*a[%d]*a[%d])\n", i, j, i, j, i, k, k+1, j, i, k+1, j+1);
            printf("\t = min(%d, %d+%d+%d)\n", dp[i][j], dp[i][k], dp[k+1][j], a[i]*a[k+1]*a[j+1]);
            printf("\t = %d\n", min(dp[i][j], dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]));
            dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
        }
    }   
    printdp(dp, num);
    return dp[0][num-1];
}

int mcm(int *a, int num, int i, int j, int depth){
    if(i>=j)
        return 0;
	if(i==j-1){
		int val =  a[i]*a[i+1]*a[i+2];
		cout<<i<<" "<<j<<" = "<<val<<endl;
		return val;
	}
	int val = INT_MAX;
    cout<<"-------"<<depth<<"--------"<<endl;
    cout<<i<<" "<<j<<endl;
    cout<<"*******************"<<endl;
	for(int k=i; k<j; k++){
		printf("[%d, %d] = [%d, %d] + [%d, %d]\n", i, j, i, k, k+1, j);
        
		int val1 = mcm(a, num, i, k, depth+1); 
		int val2 = mcm(a, num, k+1, j, depth+1);
		printf("[%d, %d] + [%d, %d]", i, k, k+1, j);
		cout<<" = "<<val1<<" +  "<<val2<<" + "<<a[i]*a[k+1]*a[j+1];
        int temp =  val1 + val2 + a[i]*a[k+1]*a[j+1];
		val = min(val, temp);
        cout<<" = "<<temp<<endl;
	}
	return val;
}

int main(){
	int n, *a;
	freopen("input_mcm.txt", "r", stdin);
	cin>>n;
	a = new int[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n-1; i++)
        cout<<a[i]<<"x"<<a[i+1]<<"\t";
    cout<<endl;
    cout<<"\nUsing normal recursion:"<<endl;
	cout<<mcm(a, n-1, 0, n-2, 0);
	cout<<endl;
	cout<<endl;
	cout<<"\nUsing DP:"<<endl;
	cout<<mcm_dp(a, n-1);
	cout<<endl;
    printf("\n3x2 2x4 4x5 5x3\n");
	return 0;
}
