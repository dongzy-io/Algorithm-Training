#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> nums(n);
    vector<bool> has_appeared(n+1,false);
    vector<int> ans;
    for(auto &x: nums){
        cin>>x;
    }
    while(q--){
        int x;
        cin>>x;
        nums.emplace_back(x);
    }
    for(int i=nums.size()-1;i>=0;i--){
        if(!has_appeared[nums[i]]){
            ans.emplace_back(nums[i]);
            has_appeared[nums[i]]=true;
        }
    }
    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    return 0;
}