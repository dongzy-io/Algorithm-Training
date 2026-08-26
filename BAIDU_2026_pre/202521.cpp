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
        int n,d,l;
        cin>>n>>d>>l;
        if(l<=n){
            cout<<0<<" "<<0<<'\n';
            continue;
        }
        int min_ans=(1+d>=l)? 1: (l-d);
        ll max_ans=(l-n-1)*1LL*n+1;
        cout<<min_ans<<" "<<max_ans<<'\n';        
    }
    return 0;
}