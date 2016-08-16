#include <iostream>
#include <stdio.h>

using namespace std;
int Y,X,R;

void print(int mat[][300])
{
	// cout<<endl;
	for(int i=0; i<Y; i++)
	{
		for(int j=0;j<X; j++)	
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	// cout<<endl;
}

void arrange(int mat[][300], int val)
{
	int temp[1200];
	int counter = 0;
	for(int i=0; i<Y-(2*val);i++)
		temp[counter++] = mat[val+i][val];
	counter--;
	for(int i=0;i<X-(2*val);i++)
		temp[counter++] = mat[Y-1-val][val+i];
	counter--;
	for(int i=Y-(2*val)-1; i>=0;i--)
		temp[counter++] = mat[val+i][X-1-val];
	counter--;
	for(int i=X-(2*val)-1;i>=0;i--)
		temp[counter++] = mat[val][val+i];
	
	int count = counter-1;
	counter = 0;
	for(int i=0; i<Y-(2*val);i++)
		mat[val+i][val] = temp[(counter++ + count-R%count)%count];
	counter--;
	for(int i=0;i<X-(2*val);i++)
		mat[Y-1-val][val+i] = temp[(counter++ + count-R%count)%count];
	counter--;
	for(int i=Y-(2*val)-1; i>=0;i--)
		mat[val+i][X-1-val] = temp[(counter++ + count-R%count)%count];
	counter--;
	for(int i=X-(2*val)-1;i>=0;i--)
		mat[val][val+i] = temp[(counter++ + count-R%count)%count];
	
	/* cout<<endl;
	for(int i=0; i<counter;i++)
		cout<<temp[i]<<" "; */
}

int main()
{
	int mat[300][300];
	freopen("input_matRot.txt","r",stdin);
	cin>>Y>>X>>R;
	for(int i=0; i<Y; i++)
		for(int j=0;j<X; j++)	
			cin>>mat[i][j];
	// print(mat);
	for(int i=0; i<min(X,Y)/2; i++)
		arrange(mat, i);
	print(mat);
	// cout<<endl;
	return 0;
}