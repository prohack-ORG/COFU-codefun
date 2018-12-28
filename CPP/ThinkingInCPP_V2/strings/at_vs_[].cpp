/**
*   Author : Siddheshwar P Sharma
*   Date   : 28 Dec 2018
*   Check the exception handling of std::string at() vs []
*   Reference : Thinking in C++ V2
**/

#include <string>
#include <exception>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::exception;
int main(){

    string s = "at() throws exception but [] does not.";
    cout<<"string : "<<s<<endl;
    cout<<"string length is : "<<s.length()<<endl;
    try{
        cout<<s[50]<<endl;
    }
    catch(exception &e){
        cout<<__LINE__<<" "<<e.what()<<endl;
    }
    try{
        cout<<s.at(50)<<endl;
    }
    catch(exception &e){
        cout<<__LINE__<<" "<<e.what()<<endl;
    }
    return 0;
}
