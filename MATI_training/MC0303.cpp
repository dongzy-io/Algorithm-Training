#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n; 
    vector<bool> isPrime(n+1,true);
    vector<int> primes;
    for(int i=2;i<=n;i++){
        if(isPrime[i])
            primes.emplace_back(i);
        for(auto x: primes){
            if(i*x>n)
                break;
            isPrime[i*x]=false;
            if(i%x==0)
                break; 
        }
    }
    cout<<primes.size();
    return 0;
}