#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ans=0;
    cin>>n;
    vector<vector<int>> record(n+1);
    queue<int> q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        record[x].emplace_back(i);
        if(!x){
            q.emplace(i);
            ans^=i;
        }
    }
    while(!q.empty()){
        int id=q.front();
        q.pop();
        for(auto x: record[id]){
            ans^=x;
            q.emplace(x);
        }
    }
    cout<<ans;
    return 0;
}