#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> H(n);
    vector<ll> ration(n);
    vector<ll> dp(n,-1);
    for(auto &x : H){
        cin>>x;
        x*=-1;
    }
    for(int i=0;i<m;i++){
        ll id,x;
        cin>>id>>x;
        id--;
        ration[id]=x;        
    }
    dp[0]=H[0]+k;
    if(dp[0]<0){
        cout<<-1;
        return 0;
    }else{
        dp[0]+=ration[0];
        if(dp[0]+H[1]>=0)
            dp[1]=dp[0]+H[1]+ration[1];
        for(int i=2;i<n;i++){
            if(dp[i-1]!=-1&&dp[i-1]+H[i]>=0){
                dp[i]=max(dp[i-1]+H[i]+ration[i],dp[i]);
            }
            if(dp[i-2]!=-1&&dp[i-2]+H[i]>=0){
               dp[i]=max(dp[i-2]+H[i]+ration[i],dp[i]);
            }
        }
    }
    cout<<dp[n-1];
    return 0;
}