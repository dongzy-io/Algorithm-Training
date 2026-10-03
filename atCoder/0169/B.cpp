#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    ll sum=0,needed=0;
    cin>>n>>m>>k;
    priority_queue<int,vector<int>,greater<int>> topK;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        topK.emplace(x);
        if(topK.size()>k)
            topK.pop();
    }   
    for(int i=0;i<m;i++){
        ll x;
        cin>>x;
        needed+=x;
    }
    while(!topK.empty()){
        sum+=topK.top();
        topK.pop();
    }
    if(sum<needed)
        cout<<"No";
    else
        cout<<"Yes";
    cout<<'\n';
    return 0;    
}