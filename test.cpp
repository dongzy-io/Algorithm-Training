#include<bits/stdc++.h>
using namespace std;

void quicksort(vector<int> &a, int l ,int r)
{
    if(l>=r)
        return ;
    int i=l,j=r;
    int pivot=a[l];
    while(i<j){
        while(i<j&&a[j]>=pivot) j--;
        while(i<j&&a[i]<=pivot) i++;
        swap(a[i],a[j]);
    }
    swap(a[i],a[l]);
    quicksort(a,l,i-1);
    quicksort(a,i+1,r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> nums(N);
    for(auto &x : nums){
        cin>>x;
    }

    return 0;
}