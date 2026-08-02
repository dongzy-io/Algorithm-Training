#include<bits/stdc++.h>
using namespace std;

int n,m;
bool isReachahble;
vector<bool> isVisited;
vector<vector<int>> adj;

void dfs(int id)
{
    for(auto u: adj[id]){
        if(!isVisited[u]){
            isVisited[u]=true;
            if(u==n-1){
                isReachahble=true;
                return ;
            }
            dfs(u);
            if(isReachahble)
                return ;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    isVisited.resize(n);
    adj.assign(n,vector<int>());
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--; y--;
        adj[x].emplace_back(y);
    }
    dfs(0);
    if(isReachahble)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}