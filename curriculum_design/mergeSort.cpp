#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a,int left ,int right, int mid)
{   
    vector<int> temp(right-left+1);
    int i=left,j=mid+1,k=0;
    while(i<=mid&&j<=right){
        temp[k++]=(a[i]<a[j])? a[i++]: a[j++]; 
    }
    while(i<=mid) temp[k++]=a[i++];
    while(j<=right) temp[k++]=a[j++];
    for(int p=0;p<k;p++){
        a[left+p]=temp[p];
    }
}

void mergeSort(vector<int> &a, int left, int right)
{
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,right,mid);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> nums(N);
    for(auto &x: nums)
        cin>>x;
    mergeSort(nums,0,N-1);
    for(auto x: nums){
        cout<<x<<" ";
    }
    return 0;
}