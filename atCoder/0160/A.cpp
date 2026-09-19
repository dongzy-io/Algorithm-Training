#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<ll> sum(n);
    vector<vector<ll>> scores(n,vector<ll>(m));
    for(int i=0;i<n;i++){
        ll total=0,min_num=1e9,max_num=0;
        for(auto &x: scores[i]){
            cin>>x;
            total+=x;
            min_num=min(min_num,x);
            max_num=max(max_num,x);
        }
        sum[i]=total-min_num-max_num;
    }
    ll id=0,max_sum=0;
    for(int i=0;i<n;i++){
        if(sum[i]>max_sum){
            id=i+1;
            max_sum=sum[i];
        }
    }
    cout<<id;
    return 0;
}