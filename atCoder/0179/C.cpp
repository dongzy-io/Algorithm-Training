#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    int n,k;
    cin>>n>>k;
    vector<ll> max_num(k);
    for(int i=0;i<n;i++){
        ll id,x;
        cin>>id>>x;
        id--;
        max_num[id]=max(max_num[id],x);
    }
    for(auto x: max_num)
        ans+=x;
    cout<<ans;
    return 0;
}