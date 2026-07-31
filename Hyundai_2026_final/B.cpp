#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    int n,k;
    cin>>n>>k;
    vector<ll> nums(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    k=min(k,n-1);
    vector<vector<ll>> dp(k+1,vector<ll>(2,0));
    for(int j=0;j<=k;j++){
        dp[j][0]=0;
        dp[j][1]=nums[1];
    }
    for(int i=2;i<=n;i++){
        vector<vector<ll>> next(k+1,vector<ll>(2,0));
        for(int j=0;j<=k;j++){
            next[j][0]=max(dp[j][0],dp[j][1]);
            ll choice1=dp[j][0]+nums[i];
            ll choice2=(j>0)? dp[j-1][1]+nums[i]: 0;
            next[j][1]=max(choice1,choice2);
        }
        dp=move(next);
    }
    for(int j=0;j<=k;j++){
        ans=max({ans,dp[j][0],dp[j][1]});
    }
    cout<<ans;
    return 0;
} 