#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int n, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&a[left]>a[largest]){
        largest=left;
    }
    if(right<n&&a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}

void heapSort(vector<int> &a)
{
    int n=a.size();
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for(int i=n-1;i>0;i--){
        swap(a[i],a[0]);
        heapify(a,i,0);
    }
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
    heapSort(nums);
    for(auto x: nums){
        cout<<x<<" ";
    }
    return 0;
}