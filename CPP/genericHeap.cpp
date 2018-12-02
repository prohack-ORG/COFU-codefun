/**
 * 
 *  Author : Siddheshwar P Sharma
 *  Date   : 01 Dec 2018
 *  HEAP implementation with templatized sorting
 *  Status : simple implementation done, templatized comparision function, elements to be templatized
 * 
 */

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_ELE 10
//T is the comparison function to be passed as template parameter
template <int (*cmpFunc)(int, int)>
class heap{
    vector<int > vec;
    int mSize;
    //F cmpFunc;
    public:
        heap():mSize(0)         {    vec.clear();   }
        int getSize()           {    return mSize;  }
        int getParent(int pos)  {    return (pos-1)/2;  }
        int getLeft(int pos)     {    return (pos*2+1); }
        int getRight(int pos)    {    return (pos*2+2); }
        void insert(int val);
        int popTop();
        void heapify(int pos);
        void swap(int, int);
        void printHeap()    {   for(auto ele : vec) cout<<ele<<" ";    cout<<endl;}
};

template <int (*cmpFunc)(int, int)>
void heap<cmpFunc>::swap(int pos1, int pos2){
    int temp = vec[pos1];
    vec[pos1] = vec[pos2];
    vec[pos2] = temp;
}
template <int (*cmpFunc)(int, int)>
void heap<cmpFunc>::heapify(int index){

    int size = getSize();
    int left = getLeft(index);
    int right = getRight(index);
    int mark = index;
    //if(left < size && vec[left] < vec[index])
    if(left < size && cmpFunc(vec[left], vec[index]))
        mark = left;
    //if(right < size && vec[right] < vec[mark])
    if(right < size && cmpFunc(vec[right],  vec[mark]))
        mark = right;
    if(mark != index){
        swap(mark, index);
        heapify(mark);
    }
}
template <int (*cmpFunc)(int, int)>
void heap<cmpFunc>::insert(int val){

    vec.push_back(val);
    mSize++;
    for(int i=mSize-1; i!=0; i=getParent(i)){
        int parent = getParent(i);
        //if(vec[i]<vec[parent]){
        if(cmpFunc(vec[i], vec[parent])){
            swap(i, parent);
        }
    }
}
template <int (*cmpFunc)(int, int)>
int heap<cmpFunc>::popTop(){

    int temp = vec[0];
    vec[0] = vec[--mSize];
    vec.erase(vec.end()-1, vec.end());
    heapify(0);
    return temp;
}

int cmp(int a, int b){
    return a<b;
}

int main(){
    //int (*func)() = cmp;
    heap<cmp> h;
    int arr[] = {4, 3, 5, 2, 1, 8, 7, 9, 6};
    for(auto i: arr)
        h.insert(i);
    for(auto i: arr){
        //h.printHeap();
        cout<<h.popTop()<<endl;
    }
    cout<<endl;
    
    return 0;
}

/**
 *  TODO : 
 *          make elements generic and pass type through templates
 * 
 * 
 */