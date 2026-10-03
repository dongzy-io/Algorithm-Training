#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sum=0;
    cin>>n;
    vector<int> nums(n);
    for(auto &x: nums){
        cin>>x;
        sum+=x;
    }
    /*vector<bool> dp(sum+1);
    dp[0]=true;
    for(auto x: nums){
        for(int i=sum+1;i>=x;i--){ 
            if(dp[i-x])
                dp[i]=true;
        }
    }
    for(int i=sum/2;i>=1;i--){
        if(dp[i]){
            cout<<sum-2*i;
            break;
        }
    }*/
    bitset<2000001> dp;
    dp[0]=1;
    for(auto x: nums)
        dp|=(dp<<x);
    for(int i=sum/2;i>=1;i--){
        if(dp[i]){
            cout<<sum-i-i;
            break;
        }
    }
    return 0;
}