#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,B,sum=0;
    cin>>n>>B;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        sum+=x;
    }
    if(sum>B)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}