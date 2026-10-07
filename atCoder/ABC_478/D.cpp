#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    unordered_map<int,int> curr_nums;
    vector<vector<pair<int,int>>> num_set(n+1,vector<pair<int,int>>());
    for(int i=0;i<q;i++){
        int l,r,x;
        cin>>l>>r>>x;
        l--;
        num_set[l].emplace_back(x,1);
        num_set[r].emplace_back(x,0);
    }
    for(int i=0;i<n;i++){
        for(auto [x,sign]: num_set[i]){
            if(sign)
                curr_nums[x]++;
            else{
                curr_nums[x]--;
                if(!curr_nums[x])
                    curr_nums.erase(x);
            }
        }
        cout<<curr_nums.size()<<" ";
    }
    return 0;
}