#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &x : nums){
        cin>>x;
    }
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap; i<n; i++){
            int pivot=nums[i];
            int j=i;
            while(j>=gap&&nums[j-gap]>pivot){
                nums[j]=nums[j-gap];
                j-=gap;
            }
            nums[j]=pivot;
        }
    }
}