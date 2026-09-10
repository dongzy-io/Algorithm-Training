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
        bool available=true;
        int n;
        cin>>n;
        vector<ll> nums(n+1,0);
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            if(!available)
                continue;
            nums[i]+=x;
            if(nums[i]<(i+1))
                available=false;
            else{
                nums[i+1]+=nums[i]-i-1;  
            }
        }
        if(available)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }
    return 0;
}