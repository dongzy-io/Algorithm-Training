#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll sum=0,ans=0;
    cin>>n;
    vector<ll> nums(n);
    for(auto &x: nums){
        cin>>x;
        sum+=x;
    }
    ll lower=sum/n;
    ll upper=(sum+n-1)/n;
    ll lower_cnt=n*upper-sum;
    ll upper_cnt=n-lower_cnt;
    for(auto x: nums){
        if(x>=upper){
            if(upper_cnt>0){
                upper_cnt--;
                ans+=x-upper;
            }else{
                ans+=x-lower;
            }
        }
    }
    cout<<ans;
    return 0;
}