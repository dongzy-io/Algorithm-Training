#include<bits/stdc++.h>
using namespace std;

int N,M,root;
vector<vector<pair<int,int>>> query;
vector<vector<int>> adj;
vector<int> fa;
vector<bool> isVisited;
vector<int> ans;

int find(int id)
{
    if(fa[id]==id)
        return id;
    return fa[id]=find(fa[id]);  
}

void tarjan(int curr)
{
    fa[curr]=curr;
    isVisited[curr]=true;
    for(auto v: adj[curr]){
        if(!isVisited[v]){
            tarjan(v);
            fa[v]=curr;
        }
    }
    for(auto p: query[curr]){
        if(isVisited[p.first]){
            ans[p.second]=find(p.first);
        }
    }    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>root;
    adj.resize(N+1);
    fa.resize(N+1);
    isVisited.assign(N+1,false);
    query.resize(N+1);
    for(int i=0;i<N-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    cin>>M;
    ans.resize(M);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        query[u].emplace_back(v,i);
        query[v].emplace_back(u,i);
    }
    tarjan(root);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}