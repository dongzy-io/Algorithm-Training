#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        ll n,m,min_sum=0,ans=-1000000000000000000;
        priority_queue<ll> min_m;
        cin>>n>>m;
        vector<ll> nums(n);
        int i=0;
        for(auto &x: nums){
            cin>>x;
            if(i<m-1){
                i++;
                min_sum+=x;
                min_m.emplace(x);
            }else{
                ans=max(ans,m*x-min_sum);
                min_m.emplace(x);
                min_sum+=x;
                min_sum-=min_m.top();
                min_m.pop();
            }       
        }
        cout<<ans<<'\n';
    }   
    return 0;
}