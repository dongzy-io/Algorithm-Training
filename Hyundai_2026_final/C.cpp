#include<bits/stdc++.h>
#define MAX 1e6
using namespace std;

typedef long long ll;
vector<bool> isPrime(MAX+1,true);
vector<int> primes;
vector<ll> cubes;

void sieve()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=MAX;i++){
        if(isPrime[i]){
            primes.emplace_back(i);
            cubes.emplace_back(1LL*i*i*i);
        }
        for(auto p: primes){
            if(i*p>MAX)
                break;
            isPrime[i*p]=false;
            if(i%p==0)
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
        ll l,r;
        cin>>l>>r;
        cout<<upper_bound(cubes.begin(),cubes.end(),r)-lower_bound(cubes.begin(),cubes.end(),l)<<'\n';
    }
    return 0;
}