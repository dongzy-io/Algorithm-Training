// NlogK
#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> nums;
priority_queue<int,vector<int>,greater<int>> pq;

int sumTopK(vector<int> &a, int k)
{
    int sum=0;
    for(auto x: a){
        if(pq.size()<k){
            pq.emplace(x);
        }else{
            if(pq.top()<x){
                pq.pop();
                pq.emplace(x);
            }
        }   
    }
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    nums.resize(n);
    for(auto &x : nums){
        cin>>x;
    }
    cout<<sumTopK(nums,k);
}