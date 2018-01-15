/*

    Goldman Sachs Round 2 CoderPad unsigned interview question
    Problem Statement:
        Given networking logs of a server in below format as a vector<string>
        10.0.0.12 <blah blah blah .. >
        10.0.0.42 <blah blah blah .. >
        10.0.0.63 <blah blah blah .. >
        10.0.0.12 <blah blah blah .. >

    find out which IP address connected most number of times to the server
    Example :
        in above case output will be :
        10.0.0.12

    input_file : input_ip_hash.txt

*/

#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#define ALOGD() prunsigned intf("%d\n", __LINE__)

using namespace std;

vector< string > separateString(string s, char ch)
{
    vector <string > vec;
    string out="";
    unsigned int len = s.length();
    for(unsigned int i=0; i<len; i++)
    {
        if(s[i] == ch){
            vec.push_back(out);    
            out="";
        }
        else
        {
            out += s[i];
        }
    }
    vec.push_back(out);
    return vec;
}

unsigned int todec(string s, unsigned int st_pow)
{
    unsigned int num=0;
    for(unsigned int i=0; i<s.length(); i++)
        num = num*10 + (s[i]-'0');
    //cout<<num<<endl;
    return num * int(pow(2, st_pow));
}

string findMaxConnection_IP(vector < string > vec)
{
    string out="";
    unsigned int num = vec.size();
    unsigned int maxpos = -1;
    long *ip_hash = new long [4294967295];
   
    for(unsigned int i=0; i<num; i++)
    {
        string s = vec[i];
        vector<string> ip_add;
        ip_add = separateString(s, ' ');
        
        vector<string > ip;
        ip = separateString(ip_add[0],'.');

        //cout<<ip[0]<<" "<<ip[1]<<" "<<ip[2]<<" "<<ip[3]<<endl;
        unsigned int ipval = todec(ip[3], 0) + todec(ip[1], 8) + todec(ip[1], 16) + todec(ip[0], 24);        

        //cout<<ipval<<endl;

        ip_hash[ipval]++;
        if(maxpos == -1 || ip_hash[ipval] > ip_hash[maxpos])
        {
            maxpos = ipval;
        }
    }
    
    unsigned int temp[4];
    for(unsigned int i=0; i<4; i++)
    {
        temp[i] = maxpos%256;
        maxpos = maxpos/256;
    }
    
    out.append(to_string(temp[3]));
    out += '.';
    out.append(to_string(temp[2]));
    out += '.';
    out.append(to_string(temp[1]));
    out += '.';
    out.append(to_string(temp[0]));

    delete[] ip_hash;
    return out;
}

int main()
{
    vector<string > vec;
    vec.push_back("10.0.0.12 skajbkd sdkjbk kljdshf");
    vec.push_back("10.0.0.13 khbksa asguyv dyuev");
    vec.push_back("10.0.0.12 khvfc ewdvuvs fuyevwff");
    vec.push_back("0.0.0.0 khvfc ewdvuvs fuyevwff");
    vec.push_back("255.255.255.255 khvfc ewdvuvs fuyevwff");
    vec.push_back("255.255.255.255 khvfc ewdvuvs fuyevwff");
    vec.push_back("255.255.255.255 khvfc ewdvuvs fuyevwff");
    vec.push_back("255.255.255.255 khvfc ewdvuvs fuyevwff");
    vec.push_back("0.0.0.0 khvfc ewdvuvs fuyevwff");
    vec.push_back("0.0.0.0 khvfc ewdvuvs fuyevwff");
    vec.push_back("0.0.0.0 khvfc ewdvuvs fuyevwff");
    vec.push_back("0.0.0.0 khvfc ewdvuvs fuyevwff");
    string out = findMaxConnection_IP(vec);
    cout<<out<<endl;
    cout<<endl;
    return 0;
}
