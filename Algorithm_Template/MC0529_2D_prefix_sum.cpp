#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        ll ans=100000;
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int>> grid(n,vector<int>(m));
        for(auto &r: grid){
            for(auto &x: r){
                cin>>x;
            }
        }
        for(int top=0;top<n;top++){
  
            vector<ll> colsum(m,0);
            for(int bottom=top;bottom<n;bottom++){
                vector<ll> prefix(m+1,0);
                ll minLen=numeric_limits<ll>::max();
                for(int i=0;i<m;i++){
                    colsum[i]=colsum[i]+grid[bottom][i];
                    prefix[i+1]=prefix[i]+colsum[i];
                }
                deque<ll> dq;
                for(int i=0;i<=m;i++){
                    while(!dq.empty()&&prefix[dq.back()]>=prefix[i])
                        dq.pop_back();
                    while(!dq.empty()&&prefix[i]-prefix[*dq.begin()]>=k){
                        minLen=min(minLen,i-*dq.begin());
                        dq.pop_front();
                    }
                    dq.push_back(i);
                }
                if(minLen!=numeric_limits<ll>::max()){
                    ans=min(ans,minLen*(bottom-top+1));
                }
            }
        }
        cout<<((ans>100000-1)? -1: ans )<<'\n';
    }
    return 0;
}