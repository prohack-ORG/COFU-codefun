#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N,M;

void print(int **a,int l,int r)
    {
    cout<<"VALUE :\t";
    for(int i=l;i<=r;i++) cout<<a[i][0]<<" ";cout<<endl;
    cout<<"INDEX :\t";
    for(int i=l;i<=r;i++) cout<<a[i][1]<<" ";cout<<endl<<endl; 
    
}
void swapping(int **a,int x,int y)
    {
        int t1=a[x][0];
        a[x][0]=a[y][0];
        a[y][0]=t1;
        int t2=a[x][1];
        a[x][1]=a[y][1];
        a[y][1]=t2;
   // print(a,0,N-1);
}

int partition(int **a,int l,int r)
    {
        int p=r;//l+rand()%(r-l+1);
        int i=l-1;
        for(int j=l;j<r;j++)
            {
            if(a[j][0]<=a[p][0])
                {
                i++;
                swapping(a,i,j);
                }
            }
        if(a[i+1][0]!=a[p][0]) swapping(a,i+1,p);
    //print(a,0,N-1);
        return i+1;
}

void qSort(int **a,int l,int r)
    {
    if(l<r)
        {
        int p=partition(a,l,r);
        qSort(a,l,p-1);
        qSort(a,p+1,r);
    }
}

int funcBinary(int **a,int l,int r){
    
    //int index=-1;
   // cout<<l<<" "<<r<<endl;
    int findVal=M-a[l-1][0];
    int mid;
    while(l<=r){
        mid=(l+r)/2;
       // cout<<"\t"<<l<<" "<<r<<endl;
    
        if(a[mid][0]==findVal) return mid;
        if(a[mid][0]<findVal) l=mid;
        else if(a[mid][0]>findVal) r=mid;
    }
    
    return -1;
}
int main() {
    int T;
    cin>>T;
   // cout<<T<<" = T\n";
    while(T--)
    {
        //int M,N;
        cin>>M>>N;
        int **a=new int*[N];
        for(int i=0;i<N;i++) {
            a[i]=new int[2];
            cin>>a[i][0];
            a[i][1]=i+1;
        }
        //print(a,0,N-1);
        qSort(a,0,N-1);
       // print(a,0,N-1);
        int index=-1;
        for(int i=0;i<N;i++)
            {
            
                index=funcBinary(a,i+1,N-1); 
                if(index!=-1){
                    int max=a[index][1]<a[i][1]?a[i][1]:a[index][1];
                    int min=a[index][1]<a[i][1]?a[index][1]:a[i][1];
                    cout<<min<<" "<<max<<endl;
                    break;
                }
        }
       for(int i=0;i<N;i++ ) delete [] a[i];
        delete [] a;
     }
    return 0;
}