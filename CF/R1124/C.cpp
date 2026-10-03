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
        int n,k;
        cin>>n>>k;
        int bound=min(k-1,n-k+1);
        ll mid_sum=0,ans=0;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            if(i>=bound&&i<n-bound)
                mid_sum+=nums[i];
        }
        for(int i=0;i<bound;i++){
            ans+=max(nums[i],nums[n-i-1]);
        }
        if(k-1<=n/2)
            cout<<ans+mid_sum;
        else
            cout<<ans;
        cout<<'\n';
    }
    return 0;
}