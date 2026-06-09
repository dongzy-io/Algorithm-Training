#include<bits/stdc++.h>
using namespace std;

int level;
vector<vector<int>> tower;
vector<vector<int>> dp;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>level;
    tower.assign(level,vector<int>());
    dp.assign(level,vector<int>());
    for(int i=0;i<level;i++){
        for(int j=0;j<i+1;j++){
            int x;
            cin>>x;
            tower[i].emplace_back(x);
        }
    }
    for(int j=0;j<level;j++){
        dp[level-1].emplace_back(tower[level-1][j]);
    }
    for(int i=level-2;i>=0;i--){
        for(int j=0;j<i+1;j++){
            dp[i].emplace_back(tower[i][j]+max(dp[i+1][j],dp[i+1][j+1]));
        }
    }
    cout<<dp[0][0];
    return 0;
}