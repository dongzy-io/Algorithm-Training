#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long ll;
unordered_map<int,int> primes;

ll power(ll a,ll b)
{
    ll ans=1;
    while(b>0){
        if(b&1)
            ans=ans*a%MOD;
        a=a*a%MOD;
        b/=2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        for(int i=2;i*i<=num;i++){
            int cnt=0;
            while(num%i==0){
                cnt++;
                num/=i;
            }
            if(cnt>0)
                primes[i]=max(primes[i],cnt);
        }
        //if(num>1&&!primes.count(num))
        //    primes[num]=1;
        if(num>1)
            primes[num]=max(primes[num],1);
    }
    ll ans=1;
    for(auto p: primes){    
        ans=ans*power(p.first,p.second)%MOD;
    }
    cout<<ans;
    return 0;
}