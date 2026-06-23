//sum top max k
//JUST KIDDING 
//
#include<bits/stdc++.h>
using namespace std;

int n;
int k;
int sum;
vector<int> nums;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    nums.resize(n);
    for(auto &x: nums){
        cin>>x;
    }
    nth_element(nums.begin(),nums.begin()+k,nums.end(),greater<int>());
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    cout<<sum;
    return 0;
}