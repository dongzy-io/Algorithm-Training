#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fastpow(ll a, ll b)
{
    ll ans=1;
    while(b>0){
        if(b&1)
            ans*=a;
        a*=a;
        b/=2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,k;
        ll ans;
        cin>>n>>k;
        cout<<(ll)2*(k-1)+fastpow(2,ll(n-k+1))<<'\n';
    }
    return 0;
}