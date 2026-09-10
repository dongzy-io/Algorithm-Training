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
        for(auto &x: nums){
            cin>>x;
        }
        if(n==1){
            cout<<1<<'\n';
            continue;
        }
        int cnt=0,ans,transfer=0;
        bool hasAdj=false,allSame=true;
        for(int i=0;i<n;i++){
            if(i>0){
                if(nums[i]==nums[i-1]){
                    cnt++;
                    if(i<n-2&&nums[i]!=nums[i+2])
                        transfer++;
                    else if(i>n-3)
                        if(nums[i-1]!=nums[i-3])
                            transfer++;
                }else
                    allSame=false;
            }
            if(i>2&&nums[i]==nums[i-1]&&nums[i-2]==nums[i-3]&&nums[i]!=nums[i-2])
                hasAdj=true;
        }
        if(allSame){
            cout<<1<<"\n";
            continue;
        }
        ans=n-cnt;
        if(transfer>0)
            ans++;
        if(hasAdj&&!allSame)
            ans++;
        if(allSame)
            ans--;
        cout<<ans<<'\n';
    }
    return 0;
}