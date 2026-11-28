#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,currLevel=1;
    cin>>n;
    vector<pair<ll,ll>> monsters(n);
    for(auto &[x,y]: monsters){
        cin>>x>>y;
        if(currLevel>=x)
            currLevel++;
    }
    if(currLevel<monsters[n-1].first){
        cout<<-1;
        return 0;
    }
    int m=monsters[n-1].first;
    vector<ll> dp(m+1,1e18);
    dp[0]=dp[1]=0;
    currLevel=1;
    for(int i=0;i<n-1;i++){
        ll l=monsters[i].first;
        ll s=monsters[i].second;
        if(currLevel>=l){
            currLevel++;
            for(int j=min(currLevel,m);j>l;j--){
                dp[j]=min(dp[j-1]+s,dp[j]);
            }
        }else{
            continue;
        }
    }
    cout<<dp[2]<<'\n';
    cout<<dp[m]+monsters[n-1].second;
    return 0;
}