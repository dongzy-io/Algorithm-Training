#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n,k,ans=1e9;
        cin>>n>>k;
        vector<int> demand(k,n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x>k)
                continue;
            demand[(x-i%k-1+k)%k]--;
        }
        for(auto x: demand){
            ans=min(ans,x);
        }
        cout<<ans<<'\n';
    }
    return 0;
}