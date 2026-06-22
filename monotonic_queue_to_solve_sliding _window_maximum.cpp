#include<bits/stdc++.h>
using namespace std;

int n,k;
deque<int> dq;
vector<int> ans;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &x: nums){
        cin>>x;
    }
    for(int i=0;i<n;i++){
        if(!dq.empty()&&i-k==dq.front()){
            dq.pop_front();
        }
        while(!dq.empty()&&nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.emplace_back(i);
        if(i>=k-1){
            ans.emplace_back(dq.front());
        }
    }
    for(auto &x : ans){
        cout<<nums[x]<<" ";
    }
    return 0;
}