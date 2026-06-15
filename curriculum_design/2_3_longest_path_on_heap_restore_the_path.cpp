#include<bits/stdc++.h>
using namespace std;

int level;
vector<vector<int>> tower;
vector<vector<int>> dp;
vector<vector<bool>> record; // left 0, right 1

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>level;
    tower.assign(level,vector<int> ());
    dp.assign(level,vector<int> ());
    record.assign(level,vector<bool> ());
    for(int i=0; i<level; i++){
        for(int j=0; j<i+1; j++){
            int x;
            cin>>x;
            tower[i].emplace_back(x);
            if(i==level-1)
                dp[i].emplace_back(x);
        }
    }
    for(int i=level-2;i>=0;i--){
        for(int j=0;j<i+1;j++){
            int upper=max(dp[i+1][j],dp[i+1][j+1]);
            dp[i].emplace_back(upper+tower[i][j]);
            if(upper==dp[i+1][j]){
                record[i].emplace_back(false);
            }else{
                record[i].emplace_back(true);
            }
        }
    }
    cout<<dp[0][0]<<'\n';
    int index=0;
    cout<<tower[0][0]<<" ";
    for(int i=0;i<level-1;i++){
        if(record[i][index]){
            index=index+1;
        }
        cout<<tower[i+1][index]<<" ";
    }
    cout<<'\n';
    return 0;
}