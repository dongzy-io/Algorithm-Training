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
        ll n,s;
        cin>>n>>s;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            if(x>s)
                s=(s+x+1)/2;
        }
        cout<<s<<'\n';
    }
    return 0;
}