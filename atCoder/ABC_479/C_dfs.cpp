#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,w,ans;
vector<ll> d;
vector<ll> m;

void dfs(ll curr,ll money,int id)
{
    if(id>=n)
        return ;
    if(money+m[id]<=w){
        ans=max(ans,curr+d[id]);
        dfs(curr+d[id],money+m[id],id+1);
    }
    dfs(curr,money,id+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);    
    cin>>n>>w;
    d.resize(n);
    m.resize(n);
    for(int i=0;i<n;i++)
        cin>>d[i]>>m[i];
    dfs(0,0,0);
    cout<<ans;
    return 0;
}