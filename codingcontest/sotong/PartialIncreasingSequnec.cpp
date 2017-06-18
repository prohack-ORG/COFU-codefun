#include<iostream>
#include<stdio.h>

using namespace std;

int N;
int MATRIX[257][257];
int MAP[257][257];

void print( int arr[][257])
{
    for(int i=0;i<=N;i++)
    {
        cout<<endl;
        for(int j=0;j<=N;j++)
            cout<<" "<<arr[i][j];
    }
    cout<<endl;

}
int main()
{
    int T;
    freopen("input_PIS.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                MATRIX[i][j]=0, MAP[i][j];
        
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                cin>>MATRIX[i][j];
        
        print(MATRIX);
//        print(MAP);

        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            {
                int max=-1;
                for(int k=0;k<i;k++)
                    if(max<MAP[k][j-1] && MATRIX[k][j-1]<=MATRIX[i][j])
                        {
                            max=MAP[k][j-1];
                        }
                 for(int k=0;k<j;k++)
                    if(max<MAP[i-1][k] && MATRIX[i-1][k]<=MATRIX[i][j])
                        {
                            max=MAP[i-1][k];
                        }
                 MAP[i][j]=1+max;

            }
        print(MAP);
        cout<<MAP[N][N]<<endl;
    }
return 0;
}

