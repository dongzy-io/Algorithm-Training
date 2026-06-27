#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> nums(N);
    for(auto &x: nums){
        cin>>x;
    }
    for(int i=0;i<N-1;i++){
        bool isswapped=false;
        for(int j=0;j<N-i-1;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                isswapped=true;
            }                
        }
        if(!isswapped)
            break;
    }
    for(auto x: nums){
        cout<<x<<" ";
    }
    return 0;
}