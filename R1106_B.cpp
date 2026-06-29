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
        ll n,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            if(n/i>1)
                cnt+=(n/i)*(n/i);
            else{
                cnt+=n-i+1;
                break;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}