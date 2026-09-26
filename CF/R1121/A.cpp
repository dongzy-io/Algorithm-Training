#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        bool isAvailable=true;
        int n;
        cin>>n;
        vector<int> nums(n);
        for(auto &x: nums)
            cin>>x;
        int bound=n;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                if(nums[nums[i]-1]!=(i+1)){
                    isAvailable=false;
                    break;
                }
                if(nums[i]-1<bound){
                    bound=nums[i]-1;
                }else{
                    isAvailable=false;
                    break;
                }
            }
        }
        if(isAvailable)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }
    return 0;
}