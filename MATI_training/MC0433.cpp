#include<bits/stdc++.h>
#define MOD 998244353 
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll sum1=0,ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')
            sum1+=i+1;
        else
            ans=(ans+sum1*(n-i)%MOD)%MOD;
    }
    cout<<ans;
    return 0;
}