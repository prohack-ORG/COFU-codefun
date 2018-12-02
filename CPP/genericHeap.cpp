/**
 *
 *  Author : Siddheshwar P Sharma
 *  Date   : 01 Dec 2018
 *  HEAP implementation with templatized sorting
 *  Status : simple implementation done, templatized comparision function and parameters
 *  NOTE   : element swapping is happenning as bit by bit copy, may result in unexpected behaviour
 *           to resolve, = operator can be overloaded to do data copy instead of bit by bit copy.
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T, int (*cmpFunc)(T, T)>
class heap {
    vector<T > vec;
    int mSize;
    //F cmpFunc;
public:
    heap():mSize(0)         {
        vec.clear();
    }
    int getSize()           {
        return mSize;
    }
    int getParent(int pos)  {
        return (pos-1)/2;
    }
    int getLeft(int pos)     {
        return (pos*2+1);
    }
    int getRight(int pos)    {
        return (pos*2+2);
    }
    void insert(T val);
    T popTop();
    void heapify(int pos);
    void swap(int, int);
    void printHeap()    {
        for(auto ele : vec) cout<<ele<<" ";
        cout<<endl;
    }
};

template <typename T, int (*cmpFunc)(T, T)>
void heap<T, cmpFunc>::swap(int pos1, int pos2) {
    T temp;
    memcpy(&temp, &vec[pos1], sizeof(T));
    memcpy(&vec[pos1], &vec[pos2], sizeof(T));
    memcpy(&vec[pos2], &temp, sizeof(T));
}

template <typename T, int (*cmpFunc)(T, T)>
void heap<T, cmpFunc>::heapify(int index) {

    int size = getSize();
    int left = getLeft(index);
    int right = getRight(index);
    int mark = index;

    if(left < size && cmpFunc(vec[left], vec[index]))
        mark = left;
    if(right < size && cmpFunc(vec[right],  vec[mark]))
        mark = right;
    if(mark != index) {

        swap(mark, index);
        heapify(mark);
    }
}

template <typename T, int (*cmpFunc)(T, T)>
void heap<T, cmpFunc>::insert(T val) {

    vec.push_back(val);
    mSize++;
    for(int i=mSize-1; i!=0; i=getParent(i)) {
        int parent = getParent(i);

        if(cmpFunc(vec[i], vec[parent])) {
            swap(i, parent);
        }
        else
            break;
    }
}

template <typename T, int (*cmpFunc)(T, T)>
T heap<T, cmpFunc>::popTop() {

    T temp;
    memcpy(&temp, &vec[0], sizeof(T));
    memcpy(&vec[0], &vec[--mSize], sizeof(T));
    vec.erase(vec.end()-1, vec.end());
    heapify(0);
    return temp;
}

template <typename T>
int cmp(T a, T b) {
    return ((a.first)<(b.first));
}

int main() {
    //int (*func)() = cmp;
    int num_ele = 10;

    int arr[] = {4, 3, 5, 2, 1, 8, 7, 9, 6, 0};
    int pos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    heap<pair<int, int>, cmp<pair<int, int> > > h;

    for(int i=0; i<num_ele; i++)
        h.insert(make_pair(arr[i], pos[i]));
    for(auto i: arr) {
        //h.printHeap();
        cout<<h.popTop().first<<endl;
    }
    cout<<endl;

    return 0;
}