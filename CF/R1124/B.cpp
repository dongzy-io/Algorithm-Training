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
        unordered_map<int,int> nums;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            for(int i=0;i<1000;i++){
                int num=0;
                while(x>0){
                    num+=(x%10)*(x%10);
                    x/=10;
                }
                x=num;
            }
            nums[x]++;
        }
        for(auto [num,cnt]: nums){
            if(cnt>1){
                ans+=cnt*(cnt-1)/2;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}