#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,ans=0;
    cin>>n>>m;
    ll curr=0;
    vector<ll> blood(m);
    vector<vector<pair<ll,bool>>> node(m+1,vector<pair<ll,bool>>());
    for(auto &x: blood)
        cin>>x;
    for(int i=0;i<n;i++){
        ll l,r;
        ll damage;
        cin>>l>>r>>damage;
        l--;
        r--;
        node[l].emplace_back(damage,true);
        node[r+1].emplace_back(damage,false);
    }
    for(int i=0;i<m;i++){
        for(auto [damage,isLeft]: node[i]){
            if(isLeft)
                curr+=damage;
            else
                curr-=damage;
        }
        if(blood[i]<=curr)
            ans++;
    }
    cout<<ans;
    return 0;
}