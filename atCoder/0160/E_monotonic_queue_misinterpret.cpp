#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll ans=0;
    unordered_map<int,queue<int>> record;
    for(int i=0;i<n;i++){
        int x,c;
        cin>>c>>x;
        for(auto &[color,q] :record){
            if(color==c){
                ans+=q.size();
                while(!q.empty()&&q.back()<x){
                    q.pop();
                }
            }else{
                while(!q.empty()&&q.back()<x){
                    q.pop();
                }
            }
        }
        record[c].emplace(x);
    } 
    cout<<ans;
    return 0;
}