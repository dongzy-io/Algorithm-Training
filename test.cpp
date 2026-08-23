#include<bits/stdc++.h>
#define MAX 200002
using namespace std;

vector<bool> isPrime(MAX,true);
vector<int> primes;

void sieve()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=MAX;i++){
        if(isPrime[i])
            primes.emplace_back(i);
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
    int T;
    cin>>T;
    sieve();
    while(T--){
        int n;
        cin>>n;
        if(n&1)
            cout<<"no";
        else{
            if(isPrime[n+1])
                cout<<"yes";
            else
                cout<<"no";
        }
        cout<<'\n';
    }
    return 0;
}