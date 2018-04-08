#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int leftVal(vector<int> &nums, int *v, int n, int st){
    for(int i=n-1; i>=st; i--)
        if(!v[i])
            return nums[i];
    return 1;
}
int rightVal(vector<int> &nums, int *v, int n, int en){
    for(int i=n+1; i<en; i++)
        if(!v[i])
            return nums[i];
    return 1;
}
long burst(vector<int> &nums, int *v, int st, int en){
    //cout<<"\nfunction : "<<__func__<<endl;
//    if(st == -1 || en == nums.size()+1){
  //      return 1;
    //}
    int temp = 0;
    int val = 0;
    for(int i=0; i<nums.size(); i++){
        if(!v[i]){
            cout<<"Burst "<<i<<" th balloon of score "<<nums[i]<<endl;
            v[i] = 1;
            //temp = (burst(nums, v, st, i) + burst(nums, v, i+1, nums.size()) + leftVal(nums, v, i)*nums[i]*rightVal(nums, v, i));
            temp = burst(nums, v, st, en) + leftVal(nums, v, i, st)*nums[i]*rightVal(nums, v, i, en);
            val = max(val, temp);
            cout<<"score is curr : "<<temp<<" global max "<<val<<endl;
            v[i] = 0;
        }
    }
    return val;
}

int maxCoins(vector<int>& nums) {
    cout<<"\nin function "<<__func__<<" total num ele : "<<nums.size()<<endl;
    int len = nums.size();
    int *visited = new int[len];
    //memset(visited, 0, nums.size()*sizeof(int));
    for(int i=0; i<len; i++)
        visited[i] = 0;
    int temp = burst(nums, visited, 0, len);
    delete[] visited;
    return temp;
}

int main(){
    freopen("input_balloons.txt", "r", stdin);
    int n;
    cin>>n;
    vector<int> v;
    int val;
    for(int i=0; i<n; i++){
        cin>>val;
        v.push_back(val);
    }
    cout<<"\nsolution is : "<<maxCoins(v)<<endl;
    return 0;
}
