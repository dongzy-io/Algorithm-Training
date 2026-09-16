#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        ll ans=0;
        int n,m;
        cin>>n>>m;
        vector<ll> nums(n);
        vector<int> posts(m);
        for(auto &x: nums){
            cin>>x;
        }
        for(auto &x: posts){
            cin>>x;
        }
        sort(posts.begin(),posts.end());
        ll benefit;
        int i=0;
        for(auto x: posts){
            benefit=0;
            while(i<x){
                benefit+=nums[i++];
            }
            ans+=abs(benefit);
        }
        while(i<n)
            ans+=nums[i++];
        cout<<ans<<"\n";
    }
    return 0;
}