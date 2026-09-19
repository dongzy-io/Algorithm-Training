#include<bits/stdc++.h>
using namespace std;

int n,m,k,ans;
bool has_found;
vector<bool> isLit;
vector<vector<int>> opt;

void dfs(int light, int curr, int id, bool has_found)
{
    if(light==k){
        ans=min(ans,id);
        has_found=true;
        return ;
    }
    int diff=0;
    for(auto i: opt[id]){
        i--;
        if(isLit[i])
            diff--;
        else
            diff++;
        isLit[i]=isLit[i]^1;
    }
    dfs(light+diff,++curr,has_);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    isLit.assign(n,false);
    opt.assign(m,vector<int>());
    for(auto &r: opt){
        int p;
        cin>>p;
        r.resize(p);
        for(auto &x: r){
            cin >>x;
        }
    }
    dfs(0,0,0,false);
    cout<<ans;
    return 0;
}