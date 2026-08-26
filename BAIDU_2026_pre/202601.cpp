#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n,k,s;
        cin>>n>>k>>s;
        vector<pair<ll,ll>> a(n);
        for(auto &p: a){
            cin>>p.first>>p.second;
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(s>=a[i].first){
                s+=a[i].second;
                continue;
            }
            while(s<a[i].first&&k>0){
                s*=2;
                k--;
            }
            if(s>=a[i].first){
                s+=a[i].second;
                continue;
            }else{
                break;
            }
        }
        if(k>0){
            for(int i=0;i<k;i++){
                s*=2;
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}