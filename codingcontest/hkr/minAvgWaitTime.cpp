/*
*	@uthor : raman jaiswal <vipram91@gmail.com>
*	Date : Jun 10th, 2017
*       Problem : Min Average waiting time
*       Source : Hackerrank>DS>Heap
*/
#include <iostream>
#include <vector>
#include <list>

using namespace std;
vector<pair<int,int>> minHeap;
list<pair<int ,int>> waitQueue;
long long len, avgWT, nextServeTime, countDone;
void swap(int x ,int y){
    int t1 = minHeap[x].first ,t2 = minHeap[x].second; 
    minHeap[x].first = minHeap[y].first;
    minHeap[x].second = minHeap[y].second; 
    minHeap[y].first = t1; 
    minHeap[y].second = t2;
}
void minHeapify(int idx){
    int small = idx, l = 2*idx+1, r = 2*idx+2;
    if(l < len && minHeap[small].second > minHeap[l].second )
        small = l;
    if(r < len && minHeap[small].second > minHeap[r].second )
        small = r;
    if(small != idx ){
        swap(small, idx);
        minHeapify(small);
    }     
}
void insert(int aTime, int procTime){
    minHeap.push_back(make_pair(aTime,procTime));
    len = minHeap.size();
    int p = len/2 -1, curr = len-1;
    while(p>=0 && minHeap[curr].second < minHeap[p].second)
    {
        swap(curr, p);
        curr = p;
        p = p%2 ? p/2 : p/2-1;
    }
}
void calWaitTime(){
    countDone++;
    if(len > 0)
    {   
        nextServeTime += minHeap[0].second;
        avgWT += nextServeTime - minHeap[0].first;
        minHeap[0].first = minHeap[len-1].first;        
        minHeap[0].second = minHeap[len-1].second;
        minHeap.resize(len-1);
        len = minHeap.size();
        minHeapify(0);
        while(waitQueue.size() > 0 && nextServeTime >= waitQueue.front().first)
        {
            insert(waitQueue.front().first, waitQueue.front().second);
            waitQueue.pop_front();
        }    
    }
    if(len == 0 && waitQueue.size() > 0)
    {
        nextServeTime = waitQueue.front().second + waitQueue.front().first;
        avgWT += nextServeTime - waitQueue.front().first;
        countDone++;
        waitQueue.pop_front();
    }
}
void addOrder(int aTime, int procTime)
{
    if(nextServeTime >= aTime){
        insert(aTime,procTime);
        waitQueue.pop_front();
    }else
        calWaitTime();
}
int main()
{
    int n,aTime,procTime,flag=0;
    cin>>n;  
    len = 0, avgWT = 0, nextServeTime = 0;
    for(int i=0; i<n; i++)
    {
        cin>>aTime>>procTime;
        waitQueue.push_back(make_pair(aTime,procTime));
    }
    waitQueue.sort();
    while(waitQueue.size() > 0)
    {
        if(flag==0){
            nextServeTime = waitQueue.front().first + waitQueue.front().second;
            avgWT += nextServeTime - waitQueue.front().first;
            countDone++; flag=1;
            waitQueue.pop_front();
        }
        else 
            addOrder(waitQueue.front().first,waitQueue.front().second);
    }
    while(countDone < n)
    {
        calWaitTime();
    }
    cout<<avgWT/n<<endl;
    return 0;
}
/*10
0 3
1 9
2 6
5 5
30 5
32 7
42 5
50 8 
54 12
55 6


5
961148050 385599125
951133776 376367013
283280121 782916802
317664929 898415172
980913391 847912645
*/
