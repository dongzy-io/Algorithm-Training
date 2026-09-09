#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> next(n+1);
    for(int i=1;i<=n;i++){
        cin>>next[i];
    } 
    vector<int> ans(n+1,0);
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(ans[i])
            continue;
        int step=1;
        int curr=i;
        vector<int> path;
        while(vis[curr]==0){
            path.emplace_back(curr);
            vis[curr]=step++;
            curr=next[curr];
        }
        int size=path.size();
        if(vis[curr]==-1){
            int base=ans[curr];
            for(int i=0;i<size;i++){
                ans[path[i]]=size-i+base;
                vis[path[i]]=-1;
            }
        }else{
            int circle_perimeter=size-vis[curr]+1;
            int circle_start_id=vis[curr]-1;
            for(int i=0;i<circle_start_id;i++){
                ans[path[i]]=size-i;
                vis[path[i]]=-1;
            } 
            for(int i=circle_start_id;i<size;i++){
                ans[path[i]]=circle_perimeter;
                vis[path[i]]=-1;
            }
        }
    }
    while(q--){
        int id;
        cin>>id;
        cout<<ans[id]<<'\n';
    }
    return 0;
}