#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    vector<ll> nums(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    int i=1;
    ll sum=0;
    while(k*i<=n){
        sum+=nums[k*i];
        i++;
    }
    cout<<sum;
    return 0;
}