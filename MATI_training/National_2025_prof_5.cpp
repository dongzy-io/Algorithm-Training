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
        unordered_set<int> nums;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            nums.emplace(x);
        }
        int ans=0;
        while(nums.count(ans)){
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}