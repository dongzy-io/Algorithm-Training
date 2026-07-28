#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ans=1;
    cin>>n;
    ll cnt2=0,cnt5=0;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        while(x>0&&x%5==0){
            x/=5;
            cnt5++;
        }
        while(x>0&&x%2==0){
            x/=2;
            cnt2++;
        }
        ans=ans*(x%10)%10;
    }
    cnt2=cnt2-min(cnt2,cnt5);
    cnt5=cnt5-min(cnt2,cnt5);
    if(cnt2>0){
        int pow2[4]={2,4,8,6};
        ans=ans*pow2[(cnt2%4+3)%4]%10;
    }
    if(cnt5>0){
        ans=ans*5%10;
    }
    cout<<ans;
    return 0;
}