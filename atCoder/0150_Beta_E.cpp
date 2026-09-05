#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    ll wealth;
    cin>>n>>q>>wealth;
    vector<ll> preSum(n+1,0);
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        preSum[i+1]=preSum[i]+x;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        ll sum=preSum[r]-preSum[l-1];
        if(sum>wealth)
            cout<<"Yes";
        else
            cout<<"No";
        cout<<'\n';
    }
    return 0;
}