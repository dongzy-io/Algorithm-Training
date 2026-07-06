#include<bits/stdc++.h>
using namespace std;
    
int n,m,k;
int cnt,days;
int previous,next_level;
vector<bool> isVisited;
vector<vector<int>> adj;
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    cnt=k;
    previous=k;
    adj.assign(n+1,vector<int> ());
    isVisited.assign(n+1,false);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    for(int i=0;i<k;i++){
        int id;
        cin>>id;
        isVisited[id]=true;
        q.emplace(id);
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        if(previous>0){
            previous--;
        }else{
            previous=next_level-1;
            next_level=0;
            days++;
            //cout<<days<<'\n';
        }
        for(auto v: adj[curr]){
            if(!isVisited[v]){
                q.emplace(v);
                isVisited[v]=true;
                cnt++;
                next_level++;
            }
        }
    }
    if(cnt==n)
        cout<<days;
    else
        cout<<-1;
    return 0;
}