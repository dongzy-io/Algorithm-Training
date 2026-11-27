#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=1000000;
    int n,m;
    cin>>n>>m;
    vector<bool> isVisited(n);
    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());// to color 
    unordered_set<int> colorsOccurred; 
    for(int i=0;i<m;i++){
        int x,y,c;
        x--; y--;
        cin>>x>>y>>c;
        adj[x].emplace_back(y,c);
        adj[y].emplace_back(x,c);
    }
    queue<tuple<int,int,int>> q;
    while(!q.empty()){
        auto [curr,prevColor,dist]=q.front();
        q.pop();
        if(curr==n-1){
            ans=min(ans,dist);
            continue;
        }
        for(auto [next,color]: adj[curr]){
            if(!isVisited[next]&&color!=prevColor){
                isVisited[]
                q.emplace(next,color,dist+1);
            }
        }
    }
    if(ans==1000000)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}