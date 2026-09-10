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
        int r,c,opt_r,opt_c;
        cin>>r>>c>>opt_r>>opt_c;    
        vector<pair<int,int>> nums;
        for(int i=0;i<opt_r;i++){
            int x;
            cin>>x;
            nums.emplace_back(x,1);
        }
        for(int i=0;i<opt_c;i++){
            int x;
            cin>>x;
            nums.emplace_back(x,2);
        }
        sort(nums.begin(),nums.end(),greater<pair<int,int>>());
        int cnt_r=0,cnt_c=0,cnt=0;
        ll ans=0;
        for(int i=0;i<opt_c+opt_r;i++){
            if()
        }
    }
}