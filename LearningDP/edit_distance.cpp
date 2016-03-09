/*

	Author : Siddheshwar P Sharma
	Date   : 9th March 2016
	Link   : http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
	i/p file : EDIT_DISTANCE.txt
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int maxLen;

int max(int a, int b)
{
	return a>b?a:b;
}

int min(int a, int b)
{
	return a<b?a:b;
}

int getCost(string a, string b, int pos1, int pos2)
{
	if(pos1==maxLen || pos2==maxLen)
		return 0;
	if(a[pos1]==b[pos2])
		return getCost(a,b,pos1+1,pos2+1);
	else
		return 1+min(min(getCost(a,b,pos1,pos2+1),getCost(a,b,pos1+1,pos2)),getCost(a,b,pos1+1,pos2+1));
}	


int main()
{
	cout<<"\n*******************  START  *****************\n\n";
	int num_test;
	string a,b;
	freopen("EDIT_DISTANCE.txt","r",stdin);
	cin>>num_test;

	for(int i=0; i<num_test; i++)
	{
		cin>>a>>b;
		cout<<endl<<"String 1 : "<<a<<"\nString 2 : "<<b;
		maxLen = max(a.length(),b.length());
		cout<<"\n#test_case : "<<i+1<<" numOf moves required : "<<getCost(a,b,0,0);
	}
	cout<<"\n\n******************  FINISH  *****************\n";
	cout<<endl;
	return 0;
}
