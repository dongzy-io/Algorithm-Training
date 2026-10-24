#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dist;

priority_queue<pair<int,int>> pq; //distance id

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        adj.assign(n,vector<int>());
        unordered_set<int> sons_of_root;
        dist.assign(n,0);
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            if(!x)
                sons_of_root.emplace(y);
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }        
        for(int i=0;i<m;i++){
            int id;
            cin>>id;
            id--;
            if(sons_of_root.count(id))
                continue;
            adj[0].emplace_back(id);
            sons_of_root.emplace(id);
        }
        pq.emplace(0,0);
        while(!pq.empty()){
            auto [d,curr]=pq.top();
            pq.pop();
            if(d<=dist[curr]&&curr)
                continue;
            for(auto i: adj[curr]){
                if((d+1)>dist[i]){
                    dist[i]=d+1;
                    pq.emplace(dist[i],i);
                }
            }
        }
        for(auto x: dist)
            cout<<x<<" ";
        cout<<'\n';
        cout<<dist[n-1]<<'\n';
    }
    return 0;
}