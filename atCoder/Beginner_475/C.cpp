#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,s,L,ans=0;
    cin>>n>>s>>L;
    vector<ll> pre(n+1,0);
    vector<ll> len(n-1);
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        pre[i]=pre[i-1]+x;
    }
    auto dist=[&] (int id1, int id2){
        return abs(pre[id1-1]-pre[id2-1]);
    };
    for(int i=1;i<=s;i++){
        for(int j=s;j<=n;j++){
            ll sl=dist(i,s);
            ll sr=dist(s,j);
            ll lr=dist(i,j);
            ll dst=lr+min(sl,sr);
            if(dst<=L){
                ans=max(ans,(ll)(j-i+1));
            }
        }
    }
    cout<<ans;
    return 0;
}