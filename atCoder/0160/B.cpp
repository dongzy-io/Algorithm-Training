#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>> n;
    vector<ll> nums(n);
    for(auto &x: nums){
        cin>>x;
        x--;
    }
    ll ans=-10000000000,curr=0;
    for(int i=0;i<n;i++){
        curr+=nums[i];
        ans=max(ans,curr);
        if(curr<0)
            curr=0;
    }
    cout<<ans;
    return 0;
}