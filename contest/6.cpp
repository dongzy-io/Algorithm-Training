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
        int n;
        ll ans=-100000000000,sum=0;
        cin>>n;
        vector<pair<ll,int>> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i].first;
            nums[i].second=i;
            sum+=nums[i].first;
        }
        if(n==5){
            cout<<sum<<'\n';
            continue;
        }
        ll curr=nums[0].first+nums[1].first+nums[2].first+nums[3].first+nums[4].first;
        ans=max(curr,ans);
        for(int i=5;i<n;i++){
            curr+=nums[i].first-nums[i-5].first;
            ans=max(curr,ans);
        }
        curr=nums[0].first+nums[1].first+nums[2].first+nums[3].first;
        vector<pair<ll,int>> sorted(nums);
        sort(sorted.begin(),sorted.end(),greater<pair<ll,int>>());
        vector<pair<int,ll>> top5(5);
        for(int i=0;i<5;i++){
            top5[i].first=sorted[i].second;
            top5[i].second=sorted[i].first;
        }
        curr=nums[0].first+nums[1].first+nums[2].first+nums[3].first; 
        for(int i=0;i<5;i++){
            if(top5[i].first>4){
                curr+=top5[i].second;
                ans=max(curr,ans);
            }
        }
        curr=nums[0].first+nums[1].first+nums[2].first+nums[3].first; 
        for(int i=4;i<n;i++){
            curr+=nums[i].first-nums[i-4].first;
            ll temp=curr;
            for(int j=0;j<5;j++){
                if(top5[j].first>i||top5[j].first<i-3){
                    temp+=top5[j].second;
                    ans=max(temp,ans);
                }
            }
        }
        curr=nums[0].first+nums[1].first+nums[2].first+nums[4].first+nums[5].first;
        ans=max(ans,curr);
        for(int i=6;i<n;i++){
            curr+=nums[i].first-nums[i-2].second+nums[i-3].first-nums[i-6].first;
            ans=max(ans,curr);
        }
        curr=nums[n-1].first+nums[n-2].first+nums[n-3].first+nums[n-5].first+nums[n-6].first;
        ans=max(ans,curr);
        for(int i=n-7;i>=0;i--){
            curr+=nums[i].first-nums[i+2].second+nums[i+3].first-nums[i+6].first;
            ans=max(ans,curr);
        }
        cout<<ans<<'\n';
    }
    return 0;
}