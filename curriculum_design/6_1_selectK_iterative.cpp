#include<bits/stdc++.h>
using namespace std;

int N,K;
int ans;
vector<int> nums;

int partition(int left,int right)
{
    int i=left;
    int pivot=nums[right];
    for(int j=left; j<=right; j++){
        if (nums[j]<pivot) {
            swap(nums[i],nums[j]);
            i++;
        }
    }
    swap(nums[i],nums[right]);
    return i;
}

int randomizedPartition(int left, int right)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(left,right);
    int id=dis(gen);
    swap(nums[right],nums[id]);
    return partition(left,right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K;
    nums.resize(N); 
    for(auto &x: nums){
        cin>>x;
    }   
    int left=0,right=N-1;
    K--;
    while(left<=right){
        /*if(left==right){
            ans=nums[left];
            break;
        }*/
        int id=randomizedPartition(left,right);
        if(id==K){
            ans=nums[id];
            break;
        }else if(id<K)
            left=id+1;
        else
            right=id-1;
    }
    cout<<ans;
    return 0;
}