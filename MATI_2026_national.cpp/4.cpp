#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        ll ans;
        ans=((n-1)/2)*n;
        if(n%3==0)
            ans-=(n/3)*2;
        cout<<ans<<'\n';
    }
    return 0;
}