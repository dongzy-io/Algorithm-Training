//online TLE
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<bool> isVisited(n);
    vector<int> thresholds(n);
    vector<vector<int>> adj(n,vector<int>());
    for(auto &x: thresholds){
        cin>>x;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[--x].emplace_back(--y);
        adj[y].emplace_back(x);
    }
    int T;
    cin>>T;
    while(T--){
        fill(isVisited.begin(), isVisited.end(),false);
        int start, wealth;
        cin>>start>>wealth;
        start--;
        int ans=1;
        queue<int> path;
        path.emplace(start);
        isVisited[start]=true;
        while(!path.empty()){
            int id=path.front();
            path.pop();
            for(auto i: adj[id]){
                if(!isVisited[i]&&wealth>=thresholds[i]){
                    ans++;
                    isVisited[i]=true;
                    path.push(i);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}