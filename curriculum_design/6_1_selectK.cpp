#include<bits/stdc++.h>
using namespace std;

int n;
int k;
vector<int> nums;

int partition(vector<int>& a , int left, int right)
{   
    int i=0;
    int pivot=a[right];
    for(int j=left;j<right;j++){
        if(a[j]<=pivot){
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[i],pivot);
    return i;
}

int randomizedPartition(vector<int> &a, int left, int right)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis (0,n);
    int id=left+dis(gen)%n;
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
            return quickselect(a,left,id,k);
        }else{
            return quickselect(a,id,right,k);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    nums.resize(n);
    for(auto &x: nums){
        cin>>x;
    }
    cout<<quickselect(nums,0,n-1,k-1)<<'\n';
    return 0;
}