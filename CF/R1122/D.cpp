#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,ans=1,curr=1;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            nums[i]-=i;
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                curr++;
                ans=max(ans,curr);
            }else if(nums[i]==nums[i-1]){
                continue;
            }else{
                curr=1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}