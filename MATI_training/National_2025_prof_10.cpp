#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
priority_queue<ll> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        pq.emplace(x);
    }
    while(t--){
        ll curr=pq.top();
        pq.pop();
        pq.emplace(curr/2);
    }
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans;
    return 0;
}