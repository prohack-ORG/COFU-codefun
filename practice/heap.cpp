/**
 * Author : Siddheshwar P Sharma
 * Date   : 8th July 2018
 * Status : Working and tested on hackerrank.
 * 
 * MAX HEAP Implementation, can be easily converted to MIN HEAP.
 */

#include <iostream>
#include <stdio.h>

using namespace std;

// #define DEBUG
#ifdef DEBUG
#define PRINTLOG(a) cout<<__LINE__<<" "<<__FUNCTION__<<" "<<a<<endl;
#else
#define PRINTLOG(a)
#endif
#define MAX_SIZE 200
#define parent(a) (a/2)
#define left(a) (a*2)
#define right(a) (a*2+1)

int init_arr[10] = {2, 4, 1, 6, 3, 8, 5, 7, 9, 0};

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

class Heap{
    int data[MAX_SIZE];
    int len;
    static const int root = 1;
    public:
    void reset();

    void add(int val);
    int top(){  return data[root]; }
    void pop();
    void heapify(int index);
};

void Heap::reset(){

    PRINTLOG("");
    for(int i=root; i<MAX_SIZE; i++){
        data[i] = -1;
    }
    len = 0;
}

void Heap::add(int val){

    PRINTLOG(val);
    data[++len] = val;
    int index = parent(len);
    while(index){
        heapify(index);
        index = parent(index);
    }
}

void Heap::pop(){

    PRINTLOG("");
    data[root] = data[len];
    data[len--] = -1;
    heapify(root);
}

//MAX heapify
void Heap::heapify(int index){

    PRINTLOG(index);
    int pos = index;
    int l = left(index);
    int r = right(index);
    if(l<=len && data[pos] < data[l])
        pos = l;
    if(r<=len && data[pos] < data[r])
        pos = r;
    if(pos!=index){
        swap(data[pos], data[index]);
        heapify(pos);
    }
}

int main(){

    PRINTLOG("");
    Heap max_heap;
    max_heap.reset();
    for(int i : init_arr)
    {
        max_heap.add(i);
    }
    for(int i=0; i<10; i++){
        cout<<max_heap.top()<<" ";
        max_heap.pop();
    }
    cout<<endl;
    return 0;
}