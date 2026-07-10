#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &x: nums){
        cin>>x;
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    if(k>nums.size()){
        cout<<-1;
    }else{
        cout<<nums[k-1];
    }
    return 0;
} 
