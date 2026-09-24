#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    multiset<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.emplace(x);
    }
    while(k--){
        int s,alternate;
        bool check;
        cin>>s>>alternate>>check;
        if(check)
            continue;
        if(s==1){
            auto it=prev(nums.end());
            nums.erase(it);
            nums.emplace(alternate);
        }else{
            auto it=nums.begin();
            auto node=nums.extract(it);
            node.value()=alternate;
            nums.insert(move(node));
        }
    }
    ll ans=0;
    for(auto x: nums){
        ans+=(ll)x;
    }
    cout<<ans;
    return 0;
}