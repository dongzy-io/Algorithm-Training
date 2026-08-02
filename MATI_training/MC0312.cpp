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
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int id;
        cin>>id;
        id--;
        for(int j=id;j<n-1-i;j++){
            nums[j]=nums[j+1];
        }
    }
    for(int i=0;i<n-m;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}