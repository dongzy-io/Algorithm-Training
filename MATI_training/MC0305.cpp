#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &x :nums){
        cin>>x;
    }
    sort(nums.begin(),nums.end(),greater<int>());
    int m;
    cin>>m;
    cout<<lower_bound(nums.begin(),nums.end(),m,greater<int>())-nums.begin()+1;
    return 0;
}