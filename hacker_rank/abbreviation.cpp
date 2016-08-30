#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <String.h>
using namespace std;
int T;
char arr[1000];

class str
{
	string st;
	int len;
	public :
		int hash[53];
		str(){
			st = "";
			len = 0;
			for(int i=0; i<52; i++)
				hash[i] = 0;
		}
		str(char *arr){
			st = arr;
			len = st.length();
			for(int i=0; i<52; i++)
				hash[i] = 0;
		}
		void update(){
			len = st.length();
		}
		void makehash(){
			for(int i=0; i<len; i++){
					hash[st.at(i) - 'A']++;			//for upperCase [0-25]
					hash[st.at(i) - 'A' + 26]++;	//for lowerCase [26-51]
			}
		}
		void print(){
			cout<<st<<endl;
		}
		int getLen(){
			return len;
		}
		char loc(int i){
			return st.at(i);
		}
		bool inmap(char ch){
			if(isupper(ch) && hash[ch - 'A'] )
				return true;
			else if(islower(ch) && hash[ch - 'a' + 26] )
				return true;
			return false;
		}
		void push(char ch){
			st.push_back(ch);
		}
		bool matchhash(int hash2[])
		{
			for(int i = 0; i<26; i++)
				if(hash2[i] > hash[i])
					return false;
			return true;
		}
};

bool search(str a, str b)
{
	int j = 0;
	int loc = 0;
	for(int i=0; i<a.getLen() && j< b.getLen(); i++)
	{
			if(toupper(a.loc(i)) == b.loc(j))
				j++;
	}
	if(j == b.getLen())
		return true;
	else
		return false;
}

int main()
{
	freopen("input_abbreviation.txt","r",stdin);
	cin>>T;
	for(int test=0; test<T; test++)
	{
		bool flag  = true;
		cin>>arr;
		str a(arr);
		
		cin>>arr;
		str b(arr);
		b.makehash();
		str temp;
		// cout<<a.getLen()<<" "<<b.getLen();
		for(int i=0;i<a.getLen();i++){
			// cout<<"\nChecking for "<<a.loc(i);
			if(b.inmap(a.loc(i)))
				temp.push(a.loc(i));//, cout<<"\nError "<<error<<" Pushed "<<a.loc(i);
			else if(isupper(a.loc(i))){
				// cout<<"\nMaking flag false for "<<a.loc(i);
				flag = false;
				break;
			}
		}
		if(flag){
			temp.update();
			temp.print();
			temp.makehash();
			b.print();
			if(false == b.matchhash(temp.hash))
			{
				flag = false;
			}
			else
				flag = search(temp, b);
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}