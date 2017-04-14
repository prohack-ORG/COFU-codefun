#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int T;

int permute(char w[100], int len)
{
	
	
	for(int i = len-2; i>0; i--)
		for(int j = len-1; j>i; j--)
			if(w[j]>w[i])
			{
				char temp = w[i];
				w[i] = w[j];
				w[j] = temp;
				// cout<<__func__<<" ---  "<<w<<endl;
				return i;
			}
}

void reshuffle(char w[100], int len, int pos)
{
	int hash[26];
	for(int i=0;i<26;i++)
		hash[i] = 0;
	for(int i=pos+1;i<len;i++)
		hash[w[i]-'a']++;
		
	int k = pos+1;
	for(int i=0;i<26;i++)
		while(hash[i] && i!=pos){
			w[k++] = char('a'+i);
			hash[i]--;
		}
	// cout<<__func__<<" ---  "<<w<<endl;
}

int main()
{
	freopen("input_bigger_better.txt","r",stdin);
	cin>>T;
	for(int i = 0; i<T; i++)
	{
	   char w[100];
       cin>>w;
	   string s1 = w;
	   // cout<<w<<" --- ";
		int len = s1.length();
		
	   int pos = permute(w, len);
	   reshuffle(w, len, pos);
	   string s2 = w;
	   if(s1 == s2)
		  cout<<"no answer\n";
	   else
	      cout<<w<<endl;
    }
	return 0;
}