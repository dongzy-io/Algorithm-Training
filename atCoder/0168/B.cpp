#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,sum=0,ans;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        sum+=x;
    }
    //cout<<ceil((long double)(sum)/m*1.0);
    ans=sum/m;
    if(sum==ans*m)
        cout<<ans;
    else
        cout<<ans+1;
    return 0;
}