#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    set<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.emplace(x);
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        nums.erase(x);
        nums.emplace(y);
    }
    for(auto x: nums)
        cout<<x<<" ";
    return 0;
}