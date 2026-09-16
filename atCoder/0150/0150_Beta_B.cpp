#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll ans=1;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        ans*=x;
    }
    cout<<ans;
    return 0;
}