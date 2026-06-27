#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n<3){
            int x,y;
            cin>>x>>y;
            cout<<max(x,y)<<" "<<min(x,y)<<'\n';
            continue;
        }
        vector<int> nums(n);
        for(auto &x:nums){
            cin>>x;
        }
        bool isSuccessful=true;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=2;i<n;i++){
            if(nums[i]!=nums[i-2]%nums[i-1]){
                isSuccessful=false;
            }
        }
        if(isSuccessful){
            cout<<nums[0]<<" "<<nums[1];
        }else{
            cout<<-1;
        }
        cout<<'\n';
    }
    return 0;
}