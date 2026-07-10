#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> primes;
    vector<bool> isPrime(n+1,true);
    vector<int> phi(n+1);
    isPrime[0]=isPrime[1]=false;
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primes.emplace_back(i);
            phi[i]=i-1;
        }            
        for(auto x: primes){
            if(x*i>n)
                break;
            isPrime[x*i]=false;
            if(i%x==0){
                phi[x*i]=phi[i]*x;
                break;
            }else
                phi[i*x]=phi[i]*(x-1);
        }
    }
    for(auto x: primes)
        cout<<x<<'\n';
    //phi unprinted
    return 0;
}