#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> nums(n);
    for(auto &x: nums){
        cin>>x;
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=nums[x-1]+nums[y-1];
        if(ans&1)
            cout<<"odd";
        else
            cout<<"even";
        cout<<'\n';
    }
    return 0;
}