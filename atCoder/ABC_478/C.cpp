#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool isAscending=true;
    int n,k,max_range;
    cin>>n>>k;
    max_range=n;
    vector<int> nums(n);
    for(auto &x: nums){
        cin>>x;
    }
    vector<int> sorted(nums);
    sort(sorted.begin(),sorted.end());
    for(int i=0;i<n;i++){
        if(nums[i]!=sorted[i]){
            max_range-=i;
            isAscending=false;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(nums[i]!=sorted[i]){
            max_range-=n-i-1;
            break;
        }
    }
    if(!isAscending&&max_range>k)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}