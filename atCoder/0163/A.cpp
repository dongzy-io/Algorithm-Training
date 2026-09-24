#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,k,cnt=0;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        cnt+=ceil(double(x)/k*1.0);
    }
    if(cnt<m)
        cout<<0;
    else
        cout<<cnt-m;
    return 0;
}