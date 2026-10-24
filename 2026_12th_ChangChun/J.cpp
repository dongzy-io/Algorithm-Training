#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll expo)
{
    ll res=1;
    for(int i=0;i<expo;i++){
        res*=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        ll ans=0;
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<bool>> isOne(n,vector<bool>(k,false));
        vector<ll> bit_cnt(k);
        while(m--){
            int i,j,w;
            cin>>i>>j>>w;
            i--;
            j--;
            for(int k=0;w>0;k++){
                if(w&1){
                    if(!isOne[i][k]){
                        bit_cnt[k]++;
                        isOne[i][k]=true;
                    }
                    if(!isOne[j][k]){
                        bit_cnt[k]++;
                        isOne[j][k]=true;
                    }
                }
                w/=2;
            }
        }
        for(int i=0;i<k;i++){
            ans+=bit_cnt[i]*power(i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}