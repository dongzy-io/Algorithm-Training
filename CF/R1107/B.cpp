#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> goodNums;
unordered_map<int,int> digits;

bool isGood(ll num)
{
    int mask=0;
    while(num>0){
        mask|=(1<<(num%10));
        if(__builtin_popcount(mask)>2)
            return false;
        num/=10;
    }
    return true;
}

void dfs(ll curr)
{
    for(int i=0;i<10;i++){
        if(!curr&&!i){
            continue;
        }
        ll num=curr*10+i;
        if(num>1&&num<1e9&&(digits.size()<2||digits[i])){
            goodNums.emplace_back(num);
            digits[i]++;
            dfs(num);
            digits[i]--;
            if(!digits[i])
                digits.erase(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    dfs(0);
    sort(goodNums.begin(),goodNums.end());
    goodNums.erase(unique(goodNums.begin(),goodNums.end()),goodNums.end());
    while(T--){
        ll x;
        cin>>x;    
        for(auto y: goodNums){
            if(isGood(y*x)){
                cout<<y;
                break;
            }
        }
        cout<<'\n';
    }
    return 0;
}