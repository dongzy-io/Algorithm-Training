#include<bits/stdc++.h>
using namespace std;

vector<int> dist;
vector<vector<int>> adj;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,m,ans;
        cin>>n>>m;
        queue<int> vertices;
        dist.assign(n,-1); 
        dist[n-1]=0;
        adj.assign(n,vector<int>());
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        vertices.emplace(n-1);
        while(!vertices.empty()){
            int curr=vertices.front();
            vertices.pop();
            if(!curr)
                continue;
            for(auto i: adj[curr]){
                if(dist[i]==-1){
                    dist[i]=dist[curr]+1;
                    vertices.emplace(i);
                }
            }
        }
        ans=dist[0];
        while(m--){
            int i;
            cin>>i;
            i--;
            ans=max(ans,dist[i]+1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}