#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<pair<ll,ll>> stk;//pos  value

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll Q,D;
    ll n=0,t=0;
    cin>>Q>>D;
    while(Q--){
        char opt;
        cin>>opt;
        if(opt=='A'){
            ll num;
            cin>>num;
            ll value=((num+t)%D+D)%D;
            int i=stk.size()-1;
            while(i>=0&&value>=stk[i].second){
                stk.pop_back();
                i--;
            }
            stk.emplace_back(n,value);
            n++;
        }else{
            ll L;
            cin>>L;
            ll threshold=n-L;
            auto it=upper_bound(stk.begin(),stk.end(),make_pair(threshold,-LLONG_MAX));
            t=it->second;
            cout<<t<<'\n';
        }
    }
}