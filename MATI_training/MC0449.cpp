#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.emplace(x);
    }
    while(k--){
        int x=pq.top();
        pq.pop();
        pq.emplace(x/2);
    }
    ll ans=0;
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans;
    return 0;
}