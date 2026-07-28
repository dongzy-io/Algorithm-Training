#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    unordered_map<int,int> mp;
    vector<int> nums(n);
    for(auto &x:nums) {
        cin>>x;
        mp[x]++;
    }
    for(auto x:nums) {
        cout<<mp[x]-1<<" ";
    }
    return 0;
}