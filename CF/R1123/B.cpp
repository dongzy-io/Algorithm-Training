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
        map<int,int,greater<int>> nums;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            nums[x]++;
        }
        while(!nums.empty()){
            int max_cnt=nums.begin()->second;
            for(auto it=nums.begin();it!=nums.end();){
                for(int i=0;i<min(it->second,max_cnt);i++)
                    cout<<it->first<<" ";
                it->second-=min(it->second,max_cnt);
                if(it->second==0)
                    it=nums.erase(it);
                else
                    it++;
            }
        }
        cout<<'\n';
    }
    return 0;
}