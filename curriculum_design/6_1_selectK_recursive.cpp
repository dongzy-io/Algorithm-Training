#include<bits/stdc++.h>
using namespace std;

int n;
int K;
int sum;
vector<int> nums;

int partition(vector<int>& a , int left, int right)
{   
    int i=left;
    int pivot=a[right];
    for(int j=left;j<right;j++){
        if(a[j]<=pivot){
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[i],a[right]);
    return i;
}

int randomizedPartition(vector<int> &a, int left, int right)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis (left,right);
    int id=dis(gen);
    swap(a[id],a[right]);
    return partition(a,left,right);
}

int quickselect(vector<int> &a, int left ,int right, int k)
{   
    int id=randomizedPartition(a,left,right);
    if(id==k){
        return a[id];
    }else{
        if(k<id){
            return quickselect(a,left,id-1,k);
        }else{
            return quickselect(a,id+1,right,k);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>K;
    nums.resize(n);
    for(auto &x: nums){
        cin>>x;
    }
    cout<<quickselect(nums,0,n-1,K-1)<<'\n';
    for(auto x: nums){
        cout<<x<<" ";
    }
    for(int i=0;i<K;i++){
        sum+=nums[i];
    }
    cout<<'\n'<<sum;
    return 0;
}