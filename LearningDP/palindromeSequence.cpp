/*

	Author : Siddheshwar P Sharma
	Date   : 3rd June 2016
	input  : input_palindromeSequence.txt
	link   : file:///home/hackmonster/Downloads/zco2015-morning.pdf

*/

#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int T, N;
int data[300];
int counter;
int minC;
int check_Palindrome(int start, int end)
{
	while(start<end)
		if(data[start++]!=data[end--])
			return 0;
	return 1;
}
int tempVal;
void calculate_C(int start, int end, int C)
{
	if(counter >=minC )
		return ;
	cout<<"\n"<<start<<" "<<end;
	if(start>end)
		return;
	int temp = check_Palindrome(start,end);

	if(temp)
	{
		cout<<"\t palindrome";
		counter++;
		cout<<"\t palindrome count :"<<counter;
		if(end == N-1){
			minC = minC > counter ? counter : minC;
			counter--;
		}
		return;
	}
	cout<<"\tNot palindrome";
	for(int i = start; i < end; i++)
	{
		calculate_C(start,i,C+1);
		calculate_C(i+1,end,C+1);	
	}
}

int main()
{
	freopen("input_palindromeSequence.txt","r",stdin);
	cin>>T;
	for(int test = 1; test<=T; test++)\
	{
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>data[i];
		int C=0;
		counter = 0;
		minC = INT_MAX;
		//for(int i = 0; i < N-1; i++)
		{
			//cout<<"\n0 "<<i<<" \n"<<i+1<<"to "<<N-1<<" \n-------------------------------------------\n";
			calculate_C(0,N-1,C);
			//calculate_C(i+1,N-1,C);	
			//minC = minC > counter ? counter : minC;
			//counter = 0;
		}
		cout<<"# "<<test<<" "<<minC<<endl;
	}
	return 0;
}