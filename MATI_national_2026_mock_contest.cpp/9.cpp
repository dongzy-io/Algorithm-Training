#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> matrix(n,vector<ll>(m));
    for(auto &r:matrix){
        for(auto &x:r){
            cin>>x;
        }
    }
    ll q;
    cin>>q;
    vector<ll> displacement(n,0);// left +, right - 
    while(q--){
        ll opt,x,k;
        cin>>opt>>x>>k;
        x--;
        if(opt==1){
            displacement[x]=(displacement[x]+k)%m;
        }else{
            displacement[x]=(displacement[x]-k+m)%m;
        }
    }
    vector<vector<ll>> ans(n,vector<ll>(m));
    for(ll i=0;i<n;i++){
        ll round=displacement[i];
        for(ll j=0;j<m;j++){
            ans[i][j]=matrix[i][(j+round+m)%m];
        }
    }
    for(auto r:ans){
        for(auto x:r){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}