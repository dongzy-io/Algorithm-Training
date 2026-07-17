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
        ll n,x;
        cin>>n>>x;
        ll min_num=(ll)n*(1+n)/2;
        ll max_num=26*min_num;
        if(x<min_num||x>max_num){
            cout<<-1<<'\n';
            return 0;
        }
        string ans(n,'a');
        ll R=x-min_num;
        for(ll j=n;j>=1;j--){
            if(R==0)
                break;
            ll d=min(25LL,R/j);
            ans[j-1]='a'+d;
            R-=d*j;
        }
        cout<<ans<<'\n';
    }
    return 0;
}