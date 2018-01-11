/*

    Author : Siddheshwar P Sharma
    Date   : 12th Jan 2018

    QUICK SORT using last element as pivot
    status : complete
*/


#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void print(int *a, int st, int en, string s)
{
    cout<<endl<<s<<endl;
    for(int i=st; i<=en; i++)
        cout<<a[i]<<" ";
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//assumption : no repeating elements
void q_sort(int *a, int st, int en)
{
    if(st>=en)
        return;
    //print(a, st, en, "entry");
    int j = st;
    int k = j - 1;
    int i = en;
    int p = j;
    while(j<i){
        //cout<<"\nk, j, i\t"<<k<<" "<<j<<" "<<i;
        if(a[j] < a[i]){
            k++;
            //cout<<"\nswapping "<<a[j]<<" "<<a[k];
            swap(&a[j], &a[k]);
            p = j;
            j++;
        }
        else{
            j++;
        }
    }
    j = p;
    if(a[j]>a[i]){
        //cout<<"\nk, j, i\t"<<k<<" "<<j<<" "<<i;
        //printf("\nswapping %d %d", a[j], a[i]);
        swap(&a[j], &a[i]);
    }
    //print(a, st, en, "over for this level");
    q_sort(a, st, j);
    q_sort(a, j+1, en);
}

int main()
{
    int T;
    int N;
    freopen("input_quick_sort.txt", "r", stdin);
    //cout<<"\nEnter number of elements in array : "<<endl;"
    cin>>T;
    while(T--){
    cin>>N;
    int *a = new int[N];
    for(int i=0; i<N; i++)
        cin>>a[i];
    q_sort(a, 0, N-1);
    //cout<<"\nfinal sorted output is :"<<endl;
    print(a, 0, N-1, "output");
    delete[] a;
    }
    cout<<endl;
    return 0;
}
