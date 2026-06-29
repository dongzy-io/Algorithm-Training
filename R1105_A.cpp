#include<bits/stdc++.h>
using namespace std;

int fastpow(int a,int b)
{
    int ans=1;
    while(b>0){
        if(b&1){
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        int cnt=0,sum=0;
        for(int i=0;i<20;i++){
            if(sum+k*fastpow(2,i)<=n){
                cnt+=k;
                sum+=k*fastpow(2,i);
            }else{
                cnt+=(n-sum)/fastpow(2,i);
                break;
            }
        }
        cout<<cnt<<'\n';
    }   
    return 0;
}