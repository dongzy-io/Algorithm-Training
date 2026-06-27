#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> nums(N);
    for(auto &x :nums){
        cin>>x;
    }
    for(int i=1;i<N;i++){
        int pivot=nums[i];
        int j=i-1;
        while(j>=0&&nums[j]>pivot){
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=pivot;
    }
    for(auto x: nums){
        cout<<x<<" ";
    }
    return 0;
}