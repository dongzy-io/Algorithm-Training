#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,ans=0;
    ll k;
    cin>>n>>k;
    unordered_map<ll,int> nums;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        nums[x]++;
        ans+=nums[x+k];
        if(x-k>0)
            ans+=nums[x-k];
    }
    cout<<ans;
    return 0;
}