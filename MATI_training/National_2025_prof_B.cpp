#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> nums(n);
    int ans=0;
    int max_num=0,min_num=100000;
    for(auto &x: nums){
        cin>>x;
        max_num=max(max_num,x);
        min_num=min(min_num,x);
        ans+=max_num+min_num;
    }
    cout<<ans;
    return 0;
}