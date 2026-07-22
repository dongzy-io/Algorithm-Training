#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1e9+7; 
vector<int> primes;
vector<bool> isComposite;
vector<int> mu;

void sieve(int n)
{
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!isComposite[i]){
            primes.emplace_back(i);
            mu[i]=-1;
        }
        for(auto p: primes){
            if(1LL*p*i>n)
                break;
            isComposite[p*i]=true;
            if(i%p==0){
                mu[i*p]=0;
                break;
            }else{
                mu[i*p]=-mu[i];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> nums(n);
    int GCD;
    bool isFirst=true;
    for(auto &x: nums){
        cin>>x;
        if(isFirst){
            GCD=x;
            isFirst=false;
        }else
            GCD=__gcd(x,GCD);
    }    
    int max_num=0;
    for(auto &x: nums){
        x/=GCD;
        max_num=max(max_num,x);
    }
    isComposite.resize(max_num+1);
    mu.resize(max_num+1);
    sieve(max_num);
    vector<int> cnt(max_num+1,0);
    vector<int> c(max_num+1,0);
    for(auto x: nums){
        cnt[x]++;
    }
    for(int i=1;i<=max_num;i++){
        for(int num=i;num<=max_num;num+=i){
            c[i]+=cnt[num];
        }
    }
    vector<ll> pw2(n+1,0);
    pw2[0]=1;
    for(int i=1;i<=n;i++)
        pw2[i]=pw2[i-1]*2%MOD;
    ll ans=0;
    for(int i=1;i<=max_num;i++){
        if(!mu[i]||!c[i])
            continue;
        ll num=(pw2[c[i]]-1)%MOD;
        ans=(ans+num*mu[i]%MOD+MOD)%MOD;
    }
    cout<<ans;
    return 0;
}