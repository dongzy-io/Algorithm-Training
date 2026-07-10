#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> nums(n);
    for(auto &x: nums){
        cin>>x;
    }
    while(q--){
        int opt,id,diff;
        cin>>opt>>id>>diff;
        if(opt==1){
            nums[id-1]+=diff;
        }else{
            nums[id-1]-=diff;
        }
    }
    for(auto x: nums){
        cout<<x<<" ";
    }
    return 0;
}