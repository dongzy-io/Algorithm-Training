#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll l,w;
    int cnt=0;
    cin>>l>>w;
    while(l>w){
        if(l&1)
            l=(l+1)/2;
        else
            l/=2;
        cnt++;
    }
    cout<<cnt;
    return 0;
}