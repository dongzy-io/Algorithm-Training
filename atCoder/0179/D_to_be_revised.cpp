#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long ll;

/*ll fastpow(ll a,ll b)
{
    int ans=1;
    while(b>0){
        if(b&1)
            ans=ans*a%MOD;
        a=a*a%MOD;
        b/=2;
    }
    return ans;
}*/

ll sum(ll cnt)
{
    ll res=1;
    for(int i=0;i<cnt;i++)
        res=res*2%MOD;
    ll substract=((cnt-1)*cnt/2)%MOD;
    res=(res-substract+MOD)%MOD;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool isValid=true;
    bool has_C=false;
    ll n,ans=1,curr=0;
    char prev='B';
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(prev=='B'){  
            if(s[i]=='C'){
                curr++;
                has_C=true;
            }
        }else if(prev=='A'){
            if(s[i]=='C'){
                prev='B';
                has_C=true;
                continue;
            }
            if(s[i]=='A'){
                isValid=false;
                break;
            }
        }else{
            if(s[i]=='B'){
                ans=(ans*sum(curr))%MOD;
                curr=0;
            }else if(s[i]=='A'){
                curr--;
                ans=(ans*sum(curr))%MOD;
                curr=0;
            }else{
                curr++;
            }
        }
        prev=s[i];
    }
    ans=(ans*sum(curr))%MOD;
    if(isValid&&has_C)
        cout<<ans;
    else
        cout<<0;
    return 0;
}