#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dist;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    adj.assign(N+1,vector<int>());
    dist.assign(N+1,0);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }    
    for(int i=0;i<K;i++){
        int x;
        cin>>x;
        dist[x]=numeric_limits<int>::max();
    }
    queue<int> path;
    path.emplace(N);
    dist[N]=0;
    while(!path.empty()){
        int curr=path.front();
        if(curr==1){
            cout<<dist[1];
            break;
        }
        path.pop();
        for(auto x: adj[curr]){
            if(dist[x]==0){
                dist[x]=dist[curr]+1;
                path.emplace(x);
            }
        }
    }
    if(!dist[1])
        cout<<-1;
    return 0;
}