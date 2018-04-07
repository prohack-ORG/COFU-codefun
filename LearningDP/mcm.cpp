#include <iostream>
#include <stdio.h>
#include <string.h>
#define INT_MAX 1<<30
using namespace std;

int mcm(int *a, int num, int i, int j){
	if(i==j-1){
		int val =  a[i]*a[i+1]*a[i+2];
		cout<<i<<" "<<j<<" = "<<val<<endl;
		return val;
	}
	int val = INT_MAX;
	for(int k=i+1; k<j; k++){
		cout<<i<<" "<<j;
		printf(" = [%d, %d] + [%d, %d]", i, k, k, j);
		int val1 = mcm(a, num, i, k); 
		int val2 = mcm(a, num, k, j);
		cout<<" = "<<val1<<" +  "<<val2<<" + "<<a[i]*a[k+1]*a[j+1]<<endl;
		val = min(val, val1 + val2 + a[i]*a[k+1]*a[j+1]);
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
	cout<<mcm(a, n, 0, n);
	cout<<endl;
	return 0;
}
