#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<bool> isPrime(1e6);

void sieve()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=0;i<1e6;i++){
        if(isPrime[i])
            primes.emplace_back(i);
        for(auto x: primes){
            if(i*x>=1e6)
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
    string s;
    cin>>s;
    int len=s.length();
    vector<bool> isVisited(len,false);
    vector<set<int>> conditions;
    int id=0;
    for(int i=0;i<len;i++){
        if(isVisited[i])
            continue;
        conditions.emplace_back(set<int>());
        conditions[id].emplace(i);
        for(int j=i+1;j<len;j++){
            if(s[j]==s[i]){
                conditions[id].emplace(j);
            }
        }
        id++;
    }
    for(auto x: primes){
        string num=to_string(x);
        if(num.size()==len){
            for(int i=0;i<conditions.size();i++){
                int id=*conditions[i].first();
                for(int j=id+1;j<len;j++){
                    if(num[id]==)
                }
            }
        }
    }
    return 0;
}