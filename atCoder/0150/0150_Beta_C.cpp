#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    map<int,int,greater<int>> record;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        record[x]++;
    } 
    int last=m,left=0,ans=0;
    for(auto p: record){
        left+=last-p.first+1;
        ans+=min(left,p.second);
        last=p.first-1;
        left-=min(left,p.second);
    }
    cout<<ans;
}