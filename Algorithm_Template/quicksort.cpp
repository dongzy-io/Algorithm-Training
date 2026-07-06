//can be implemented only by recursion
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int left ,int right)
{
    if(left>=right)
        return ;
    int i=left, j=right;
    int pivot=a[left]; 
    while(i<j){
        while(i<j&&a[j]>=pivot) j--;
        while(i<j&&a[i]<=pivot) i++;
        swap(a[i],a[j]); 
    }
    swap(a[i],a[left]);
    solve(a,left,i-1);
    solve(a,i+1,right);
}

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
    solve(nums,0,N-1);
    for(auto x: nums){
        cout<<x<<" ";
    }
}