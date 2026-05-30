#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<ll> nums(n);
        for(auto &x: nums){
            cin>>x;
        }
        ll sum=0;
        ll curr=numeric_limits<ll>::max();
        for(int i=0; i<n;i++){
            sum+=nums[i];
            ll temp=sum/(i+1);
            if(temp>=curr){
                cout<<curr<<" ";
            }else{
                curr=temp;
                cout<<temp<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}