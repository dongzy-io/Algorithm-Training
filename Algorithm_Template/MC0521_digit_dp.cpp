#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
vector<int> digs;
vector<bool> isPrime(173,true);
ll memo[20][11][173][2];//pos last sum started
bool vis[20][11][173][2];

void sieve()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=172;i++){
        if(isPrime[i]){
            for(int j=i*2;j<=172;j+=i)
                isPrime[j]=false;
        }
    }
}

ll dfs(int pos, int last,int sum, bool tight, bool started)
{
    ll res=0;
    if(pos==n)
        return (started&&isPrime[sum])? 1: 0;
    if(!tight&&vis[pos][last][sum][started])
        return memo[pos][last][sum][started];
    int limit=tight? digs[pos]:9;
    for(int i=0;i<=limit;i++){
        bool ntight=tight&&(i==limit);
        if(!started&&!i)
            res+=dfs(pos+1,10,sum,ntight,false);
        else{
            if(started&&i==last)
                continue;
            res+=dfs(pos+1,i,sum+i,ntight,true);
        }
    } 
    if(!tight){
        vis[pos][last][sum][started]=true;
        memo[pos][last][sum][started]=res;
    }   
    return res;
}

ll f(ll num)
{
    digs.clear();
    memset(vis,false,sizeof(vis));
    while(num>0){
        digs.emplace_back(num%10);
        num/=10;
    }
    reverse(digs.begin(),digs.end());
    n=digs.size();
    return dfs(0,10,0,true,false);
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
        cout<<f(r)-f(l-1)<<'\n';
    }
    return 0;
}