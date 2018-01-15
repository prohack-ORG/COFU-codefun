/*

    Goldman Sachs Round 2 on Codepad
    Problem Statement : Shrink given string by replacing adjacent repeatition of characters by their repeatition count
                        Example :
                            i/p     |     o/p
                        ____________|___________ 
                                    |
                        aaa         |    a3
                        aaabbaaa    |    a3b2a3
                        aba         |    a1b1a1
                        a           |    a1    
                        ________________________
    Date   : 15th January 2018
    Status : code is working as expected

*/

#include <iostream>
#include <string.h>

using namespace std;

string shorten(string s)
{
    string out = "";
    int count = 1;
    int len = s.length();
    if(len==0)
        return ("");
    int i=1;
    out+=s[0];
    while(i < len)
    {
        if(s[i] == s[i-1]){
            count++;
        }
        else{
            out.append(to_string(count));
            out+=s[i];   
            count = 1;
        }
        cout<<"iteration : "<<i<<" : "<<out<<endl;
        i++;
    }
    out.append(to_string(count));
    return out;
}

int main()
{
    int T;
    freopen("input_compress.txt", "r",  stdin);
    cin>>T;
    for(int i=0; i<T; i++){
        string s;
        cin>>s;
        cout<<"input : "<<s<<endl;
        string out = shorten(s);
        cout<<out<<endl;
    }
    return 0;
}
