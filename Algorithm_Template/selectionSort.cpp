#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> nums(N);
    for(auto &x : nums){
        cin>>x;
    }
    for(int i=0;i<N-1;i++){
        int minIndex=i;
        for(int j=i+1;j<N;j++){
            if(nums[j]<nums[minIndex])
                minIndex=j;
        }
        swap(nums[i],nums[minIndex]);
    }
    for(auto x: nums)
        cout<<x<<" ";
    return 0;
}