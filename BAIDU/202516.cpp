#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n,x,y;
        cin>>n>>x>>y;
        int max_cnt=0;
        map<int,int> cnt;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            cnt[num]++;
            max_cnt=max(max_cnt,cnt[num]);
        }
        ll ans=(n-max_cnt)*1LL*y;
        int curr=0;
        for(auto p: cnt){
            curr+=p.second;
            ans=min(ans,p.first*1LL*x+(n-curr)*1LL*y);
        }
        cout<<ans<<'\n';
    }
    return 0;
}