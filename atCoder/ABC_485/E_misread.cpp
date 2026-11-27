#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<bool> isVisited;
vector<vector<pair<int,int>>> adj;// to color 
unordered_set<int> colorsOccurred; 
int ans=1000000;

void dfs(int curr, int color, int dist)
{
    if(curr==n-1){
        ans=min(ans,dist);
        return ;
    }
    for(auto [i,c]: adj[curr]){
        if(!colorsOccurred.count(c)&&!isVisited[c]){
            isVisited[i]=true;
            colorsOccurred.emplace(c);
            dfs(i,c,dist+1);
            isVisited[i]=false;
            colorsOccurred.erase(c);
        }
    }
    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    isVisited.assign(n,false);
    adj.assign(n,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        int x,y,c;
        x--; y--;
        cin>>x>>y>>c;
        adj[x].emplace_back(y,c);
        adj[y].emplace_back(x,c);
    }
    dfs(0,0,0);
    if(ans==1000000)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}