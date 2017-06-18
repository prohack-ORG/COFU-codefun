/*
*	@uthor : raman jaiswal <vipram91@gmail.com>
*	Date : Jun 4th, 2017
*       Problem : Running Median of Integers
*       Source : Hackerrank>DS>Heap
*/

#include <iostream>
#include <vector>

using namespace std;

void swap(float &a, float &b){   float t = b; b = a; a = t; }
vector<float> minHeap, maxHeap;
int len1, len2;

void insertMinHeap(float val){
    minHeap.push_back(val);
    len2 = minHeap.size();
    int p = len2/2 -1, curr = len2-1;
    while(p>=0 && minHeap[curr] < minHeap[p]){
            swap(minHeap[curr], minHeap[p]);
            curr = p;
            p = p%2 ? p/2 : p/2-1;
        }
}
void insertMaxHeap(float val){
    maxHeap.push_back(val);
    len1 = maxHeap.size();
    int p = len1/2 -1, curr = len1-1;
    while(p>=0 && maxHeap[curr] > maxHeap[p]){
            swap(maxHeap[curr], maxHeap[p]);
            curr = p;
            p = p%2 ? p/2 : p/2-1;
        }
}
void maxHeapify(int idx){
    int large = idx, l = 2*idx+1, r = 2*idx+2;
    if(l < len1 && maxHeap[large] < maxHeap[l] )
            large = l;
    if(r < len1 &&  maxHeap[large] < maxHeap[r] )
            large = r;
    if(large != idx){
       swap(maxHeap[large], maxHeap[idx]);
       maxHeapify(large); 
    }
}
void minHeapify(int idx){
    int small = idx, l = 2*idx+1, r = 2*idx+2;
    if(l < len2 && minHeap[small] > minHeap[l] )
        small = l;
    if(r < len2 && minHeap[small] > minHeap[r] )
        small = r;
    if(small != idx ){
        swap(minHeap[small], minHeap[idx]);
        minHeapify(small);
    }             
}
float runningMedian(float val){
    if(len1 > 0 && val < maxHeap[0])
         insertMaxHeap(val);
    else 
         insertMinHeap(val);
    if(abs(len1-len2)>1){
        if(len1 > len2){
            insertMinHeap(maxHeap[0]);
            maxHeap[0] = maxHeap[len1-1];
            maxHeap.resize(len1-1);
            len1 = maxHeap.size();
            maxHeapify(0);
        }
        else if(len2>len1){
            insertMaxHeap(minHeap[0]);
            minHeap[0] = minHeap[len2-1];
            minHeap.resize(len2-1);
            len2 = minHeap.size();
            minHeapify(0);
        }
    }
    return (len1+len2)%2 ? ((len1>len2) ? maxHeap[0] : minHeap[0]) : (maxHeap[0] + minHeap[0])/2.0;
}
int main()
{
    int n; float temp;
    cin>>n;
    len1 = 0; len2 = 0;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        cout<<runningMedian(temp)<<endl;
    }
    minHeap.resize(0);
    maxHeap.resize(0);
    return 0;
}
