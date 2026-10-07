#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool isAvailable=true;
    int n,q,max_cnt=0;
    cin>>n>>q;
    vector<int> nums(n,0);
    vector<pair<int,int>> cnt(n);//cnt id
    for(int i=0;i<n;i++){
        cnt[i].second=i;
    }
    vector<vector<pair<int,bool>>> next(n,vector<pair<int,bool>>());  //id isStrictlyLess
    while(q--){
        int t,u,v;
        cin>>t>>u>>v;
        u--;
        v--;
        if(t){
            cnt[u].first++;
            max_cnt=max(max_cnt,cnt[u].first+1);
            next[u].emplace_back(v,true);
        }else{
            next[u].emplace_back(v,false);
        }
    }
    if(max_cnt>n)
    sort(cnt.begin(),cnt.end());
    for(auto [m,i]: cnt){
        if(!nums[i])   
            nums[i]=1;
        for(auto [id, isLess]: next[i]){
            if(isLess)
                nums[id]=nums[i]+1;
            else
                nums[id]=nums[i];
        }
    }
    for(auto x: nums)
        cout<<x<<" ";
    return 0;
}