#include<bits/stdc++.h>
using namespace std;

vector<int> tail;
vector<int> tail2;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums;
    int x;
    while(cin>>x){
        nums.emplace_back(x);
        auto it=upper_bound(tail.begin(),tail.end(),x,greater<int>());
        if(it==tail.end()){
            tail.emplace_back(x);
        }else{
            *it=x;
        }
    }
    cout<<tail.size()<<'\n';
    for(int x: nums){
        auto it=lower_bound(tail2.begin(),tail2.end(),x);
        if(it==tail2.end()){
            tail2.emplace_back(x);
        }else{
            *it=x;
        }
    }
    cout<<tail2.size();
    return 0;
}