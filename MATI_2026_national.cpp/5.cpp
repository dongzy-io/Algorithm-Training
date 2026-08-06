#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vector<ll> nums(n+1,0);
        vector<ll> presum(n+1,0);
        vector<ll> diff(n+1,0);
        for(ll i=1;i<=n;i++){
            cin>>nums[i];
            presum[i]=presum[i-1]+nums[i];
        }        
        stack<ll> a_id;
        ll sum=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='a')
                a_id.emplace(i);
            if(s[i]=='b'||s[i]=='c'){
                if(!a_id.empty()){
                    ll id=a_id.top();
                    a_id.pop();
                    /*if(presum[i+1]-presum[id]<0){
                        diff[id]--;
                        diff[i+1]++;
                    }*/
                   sum+=nums[id+1]+nums[i+1];
                   if()
                }
                if(a_id.empty()){
                    sum=0;
                }
            }
        }
        ll ans=0;
        ll state=0;
        for(ll i=0;i<n;i++){
            state+=diff[i];
            if(state>=0){
                ans+=nums[i+1];
            }
        }
        /*for(auto x: nums){
            cout<<x<<" ";
        }
        cout<<'\n';
        for(auto x:presum){
            cout<<x<<" ";
        }
        cout<<'\n';
        for(auto x:diff){
            cout<<x<<" ";
        }
        cout<<'\n';*/
        cout<<ans<<'\n';
    }
    return 0;
}