#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &x:nums) {
        cin>>x;
    }
    vector<int> sorted(nums);
    sort(sorted.begin(),sorted.end());
    for(auto x:nums){
        cout<<lower_bound(sorted.begin(),sorted.end(),x)-sorted.begin()+1<<" ";
    }
    return 0;
}