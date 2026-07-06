#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    while(q--){
        char opt;
        cin>>opt;
        int l,r,x;
        cin>>l>>r;
        if(opt=='1'){
            cin>>x;
            for(int i=l;i<=r;i++){
                nums[i]+=x;
            }
        }else if(opt=='2'){
            cin>>x;
            for(int i=l;i<=r;i++){
                if(nums[i]>x){
                    nums[i]=x;
                }
            }
        }else{
            int sum=0;
            for(int i=l;i<=r;i++){  
                sum+=nums[i];
            }
            cout<<sum<<'\n';
        }
    }
    return 0;
}