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
        ll ans=0;
        int n;
        cin>>n;
        vector<int> nums(n);
        vector<pair<int,bool>> loves(n-4);//val isCounted
        for(auto &x: nums)
            cin>>x;
        unordered_map<int,ll> record;
        for(int i=0;i<n-4;i++)
            loves[i].first=nums[i]+nums[i+2]-nums[i+4];
        for(int i=0;i<n-4;i++){
            if(!loves[i].second){
                record[loves[i].first]++;
                if(i+2<n-4&&loves[i].first==loves[i+2].first)
                    loves[i+2].second=true;
                if(i+4<n-4&&loves[i].first==loves[i+4].first)
                    loves[i+4].second=true;
            }
        } 
        for(auto [val,cnt]: record)
            ans+=(cnt-1)*cnt/2;
        cout<<ans<<'\n';
    }
    return 0;
}