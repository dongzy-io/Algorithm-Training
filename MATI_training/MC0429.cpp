#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long ll;
int dp[5000][5000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if(s[i]==s[j])
                dp[i][j]=(dp[i][j-1]+dp[i+1][j]+1)%MOD;
            else
                dp[i][j]=((dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1])%MOD+MOD)%MOD;
        }
    }
    cout<<dp[0][n-1];
    return 0;
}