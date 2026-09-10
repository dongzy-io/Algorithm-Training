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
        ll n,c;
        ll base=0;
        cin>>n>>c;
        vector<ll> nums(n);
        vector<ll> extra;
        for(auto &x: nums){
            cin>>x;
            base+=x-c;
            if(x-c<0)
                extra.emplace_back(c-x);
        } 
        sort(extra.rbegin(),extra.rend());
        int available=min(extra.size(),(size_t)n/2);
        ll extra_benefit=0;
        for(int i=0;i<available;i++){
            extra_benefit+=extra[i];            
        }
        cout<<base+extra_benefit<<'\n';
    }
    return 0;
}