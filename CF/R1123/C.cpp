#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> primes;
vector<bool> isPrime(300000+1,true);

void sieve()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=0;i<=300000;i++){
        if(isPrime[i])
            primes.emplace_back(i);
        for(auto x: primes){
            if(i*x>300000)
                break;
            isPrime[i*x]=false;
            if(i%x==0)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    sieve();
    while(T--){
        int n,g;
        cin>>n>>g;
        ll ans=0;
        unordered_map<int,ll> prime_sum;
        unordered_map<int,int> nums;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            nums[x]++;
        }
        if(g==1){
            cout<<0<<"\n";
            continue;
        }
        for(auto x: primes){
            if(g%x==0)
                prime_sum.emplace(x,0);
            while(g%x==0){
                g/=x;
            }
            if(g<x)
                break;
        }
        for(auto [num,cnt] : nums){
            for(auto &[divisor,sum]: prime_sum){
                if(num%divisor==0){
                    sum+=(ll)num*cnt;
                    ans=max(ans,sum);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}