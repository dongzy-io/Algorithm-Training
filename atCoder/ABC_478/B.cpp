#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,v,ans=0;
    cin>>n>>v;
    vector<vector<int>> dp(v+1,vector<int>(4,0));
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int j=v;j>i;j--){
            for(int k=1;k<=3;k++){
                dp[j][k]=max(dp[j][k],dp[j-i-1][k-1]+x);
                ans=max(ans,dp[j][k]);
            }
        }
    }
    cout<<ans;
    return 0;
}