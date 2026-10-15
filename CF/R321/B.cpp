#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d;
    ll ans=0,curr=0;
    cin>>n>>d;
    vector<pair<int,ll>> friends(n);
    for(auto &[money,factor]: friends)
        cin>>money>>factor;
    sort(friends.begin(),friends.end());
    int i=0,j=0;
    while(i<n){
        curr+=friends[i].second;
        while(friends[i].first-friends[j].first>=d)
            curr-=friends[j++].second;
        ans=max(ans,curr);
        i++;
    }
    cout<<ans;
    return 0;
}