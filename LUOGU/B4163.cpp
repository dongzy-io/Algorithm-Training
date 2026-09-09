#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(auto &x: a){
        cin>>x;
    }
    for(auto &x: b){
        cin>>x;
    }
    vector<ll> dp1(n,0);
    vector<ll> dp2(n,0);
    for(int i=1;i<n;i++){
        dp1[i]=min(dp1[i-1]+(ll)abs(a[i]-a[i-1]),dp2[i-1]+(ll)abs(a[i]-b[i-1]));
        dp2[i]=min(dp1[i-1]+(ll)abs(b[i]-a[i-1]),dp2[i-1]+(ll)abs(b[i]-b[i-1]));
    }
    cout<<min(dp1[n-1],dp2[n-1]);
    return 0;
}