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
        ll n,MOD,len;
        cin>>n>>len>>MOD;
        if(MOD<len||MOD==1&&len>1){
            cout<<"NO"<<'\n';
            continue;
        }
        cout<<"YES"<<'\n';
        for(int i=0;i<n-1;i++){
            cout<<1<<" ";
        }
        cout<<MOD-len+1<<" ";
        cout<<'\n';
    }
    return 0; 
}