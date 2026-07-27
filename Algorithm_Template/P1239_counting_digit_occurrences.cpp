#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> cnt(10);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin>>num;
    ll p=1;
    while(p<=num){
        ll high=num/(p*10);
        ll cur=num/p%10;
        ll low=num%p;
        for(int i=0;i<=9;i++){
            if(!i){
                if(!high)
                    continue;
                if(cur>0)
                    cnt[0]+=high*p;
                else
                    cnt[0]+=(high-1)*p+low+1;
            }else{
                if(cur>i)
                    cnt[i]+=(high+1)*p;
                else if(cur==i)
                    cnt[i]+=high*p+low+1;
                else
                    cnt[i]+=high*p;
            }
        }
        p*=10;
    }
    for(auto x: cnt)
        cout<<x<<'\n';
    return 0;
}