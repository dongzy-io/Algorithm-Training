#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> dist(n,103);
    vector<vector<int>> adj(n,vector<int>());
    dist[0]=0;
    for(int i=0;i<n;i++){
        int id,k;
        cin>>id>>k;
        id--;
        nums[id]=k;
        for(int i=0;i<k;i++){
            int x;
            cin>>x;
            x--;
            adj[id].emplace_back(x);
        }
    }
    int floor=1;
    queue<pair<int,int>> q;
    q.emplace(0,0);
    while(!q.empty()){
        auto [id,d]=q.front();
        q.pop();
        for(auto u: adj[id]){
            if(d+1<dist[u]){
                dist[u]=d+1;
                q.emplace(u,d+1);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<((dist[i]==103)? -1: dist[i])<<'\n';
    }
    return 0;
}