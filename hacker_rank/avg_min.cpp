#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;
#define parent(x) x/2
#define left(x) x*2
#define right(x) x*2+1

struct data
{
    long order_time;
    long process_time;
};

long maxim(long a, long b)
  {
  return a>b ? a:b;
}

void print(data *a, int n)
    {
    cout<<endl;
    for(int i=1; i<=n; i++)
        cout<<a[i].order_time<<", "<<a[i].process_time<<endl;
}

void swap(data *a, data *b)
{
    data temp = *a;
    *a = *b;
    *b = temp;
}

void process_time_min_heapify(data *a, int pos, int n)
{
    int l = left(pos);
    int r = right(pos);
    int small = pos;
    if(l<=n && a[l].process_time < a[pos].process_time)
        small = l;
    if(r<=n && a[r].process_time < a[small].process_time)
        small = r;
    if(pos!=small)
    {
        swap(&a[small], &a[pos]);
        process_time_min_heapify(a, small, n);
    }
}
void order_time_min_heapify(data *a, int pos, int n)
{
    int l = left(pos);
    int r = right(pos);
    int small = pos;
    if(l<=n && a[l].order_time < a[pos].order_time)
        small = l;
    if(r<=n && a[r].order_time < a[small].order_time)
        small = r;
    if(pos!=small)
    {
        swap(&a[small], &a[pos]);
        order_time_min_heapify(a, small, n);
    }
}

int main() {
    int n;
    freopen("input_avg_min.txt", "r", stdin);
    cin>>n;
    data *d = new data[n+1];
    for(int i=1; i<=n; i++)
        cin>>d[i].order_time>>d[i].process_time;

    long curr_time = 0;
    long wait_time = 0;
    data *min_heap = new data[n+1];

    for(int i=1; i<=n; i++)
    {
        for(int x=parent(i); x>=1; x = parent(x))
           order_time_min_heapify(d, x, i);
    }
    //cout<<"time_heap\n";
    //print(d, n);
    int index1 = n;    
    int index2 = 0;
    do
    {
        ////cout<<"iteration\n";
        while(index1>0 && d[1].order_time <= curr_time || index2 == 0)
        {
            min_heap[++index2] = d[1];
            for(int x=parent(index2); x>=1; x=parent(x))
                process_time_min_heapify(min_heap, x, index2);
            d[1] = d[index1--];
            order_time_min_heapify(d, 1, index1); 
            
            //cout<<"index1 : "<<index1<<endl;
            //cout<<"index2 : "<<index2<<endl;
            //cout<<"time_heap\n";
            //print(d, index1); 
            //cout<<"min_heap\n";
            //print(min_heap, index2); 
        }
      
        if(index2 > 0)
        {
          if(min_heap[1].order_time > curr_time)
            curr_time = min_heap[1].order_time + min_heap[1].process_time;
          else  
            curr_time += min_heap[1].process_time;
        //cout<<"curr_time : "<<curr_time<<endl;
        //cout<<"wait_time : "<<curr_time - min_heap[1].order_time<<endl;
        ////cout<<"order_time : "<<min_heap[1].order_time<<endl;
        wait_time += curr_time - min_heap[1].order_time;
        min_heap[1] = min_heap[index2--];
        process_time_min_heapify(min_heap, 1, index2);     
      
        //cout<<"index1 : "<<index1<<endl;
        //cout<<"index2 : "<<index2<<endl;
        //cout<<"min_heap\n";
        //print(min_heap, index2); 
        }
    }while(index2>0 || index1>0);
  
    //cout<<"curr_time : "<<curr_time<<endl;
    //cout<<"wait_time : "<<wait_time<<endl;
    ////cout<<"order_time : "<<min_heap[1].order_time<<endl;
    cout<<wait_time/n;
    delete[] d;
    return 0;
}
