//note that the edges are seperated by comon
#include<bits/stdc++.h>
#define LOG 14

using namespace std;

int N,root;
vector<vector<int>> adj;
vector<int> inDegree;
vector<int> depth;
vector<vector<int>> up;

void dfs(int curr, int parent, int d)
{
    depth[curr]=d;
    up[curr][0]=parent;
    for(int i=1;i<LOG;i++){
        if(up[curr][i-1]!=0){
            up[curr][i]=up[up[curr][i-1]][i-1];
        }else{
            up[curr][i]=0;
        }
    }
    for(auto v: adj[curr]){
        dfs(v,curr,d+1);
    }
}

int get_LCA(int u,int v)
{
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    int diff=depth[u]-depth[v];
    for(int i=0;i<LOG;i++){
        if((diff>>i)&1){
            u=up[u][i];
        }
    }
    if(u==v)
        return u;
    for(int i=LOG-1;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    adj.assign(N+1,vector<int>());
    inDegree.resize(N+1);
    depth.resize(N+1);
    up.assign(N+1,vector<int> (LOG));
    cin.ignore();
    string origin;
    getline(cin,origin);
    for(auto &c: origin){
        if(c>'0'&&c<='9'){
            continue;
        }
        c=' ';
    }
    stringstream ss(origin);
    int temp=N-1;
    while(temp--){
        int u,v;
        ss>>u>>v;
        adj[u].emplace_back(v);
        inDegree[v]++;
    }
    for(int i=1;i<=N;i++){
        if(inDegree[i]==0){
            root=i;
            break;
        }
    }
    dfs(root,0,1);
    int a,b;
    cin>>a>>b;
    cout<<get_LCA(a,b);
    return 0;
}