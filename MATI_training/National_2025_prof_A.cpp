#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &x: nums){
        cin>>x;
    }
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]<nums[j])
                cnt++;
        }
    }
    cout<<cnt;
    return 0;
}