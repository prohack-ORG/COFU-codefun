/***
*   Code showing [] vs at() for vectors
*   at() throws exception while [] doesn't and might cause serious bugs
***/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::exception;

int main(){
    vector<int > vec;
    vec.reserve(10);
    for(int i=0; i<7; i++)
        vec.push_back(i);
    try{
        cout<<vec[8]<<endl;
    }
    catch(const exception &e){
        cout<<__LINE__<<" Caught Exception "<<e.what()<<endl;
    }
    try{
        cout<<vec.at(8)<<endl;
    }
    catch(const exception &e){
        cout<<__LINE__<<" Caught Exception "<<e.what()<<endl;
    }
    return 0;
}
