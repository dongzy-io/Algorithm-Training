#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,ans=0,origin=0;
        cin>>n;
        vector<int> nums(n);
        for(auto &x: nums){
            cin>>x;
            for(auto y: nums){
                if(x<y)
                    origin++;
            }
        }
        ans=origin;
        vector<vector<int>> dp(n+1,vector<int>(n+1));//r l
        for(int r=1;r<n;r++){
            int gain=0;
            for(int l=r-1;l>=0;l--){
                gain+=(nums[r]>nums[l]? 1: -1);
                dp[l][r]=dp[l][r-1]+gain;
                ans=max(origin+dp[l][r],ans);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}