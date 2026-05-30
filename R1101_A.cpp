#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(auto &x:nums){
            cin>>x;
        }
        sort(nums.begin(),nums.end());
        int l,r;
        int cnt=0;
        if(n&1){
            l=r=(n-1)/2;
            l--;r++;
            cnt++;
        }else{
            l=(n-1)/2;
            r=n/2;
        }
        while(l>=0&&r<n){
            if(nums[l]==nums[r])
                cnt+=2;
            else
                break;
            l--;
            r++;
        }
        int ans=(n-cnt)/2;
        cout<<ans<<'\n';
    }
    return 0;
}