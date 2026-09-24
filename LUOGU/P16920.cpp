#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,ans=0;
        cin>>n;
        vector<int> nums(n);
        for(auto &x: nums){
            cin>>x;
            for(auto y: nums){
                if(x<y)
                    ans++;
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(n));//r l
        for(int i=0;i<n;i++){
            int gain=0;
            for(){
                
            }
        }
    }
}