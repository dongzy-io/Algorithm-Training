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
        int n,m;
        cin>>n>>m;
        vector<ll> d2(n+5,0);
        for(int i=0;i<m;i++){
            int l,r;
            cin>>l>>r;
            int len=r-l+1;
            if(len%2==1){
                int mid_next=l+len/2+1;
                d2[l]+=1;
                d2[mid_next]-=2;
                d2[r+2]+=1;
            }else{
                int mid2=l+len/2;
                d2[l]+=1;
                d2[mid2]-=1;
                d2[mid2+1]-=1;
                d2[r+2]+=1;
            }
        }
        vector<ll> d1(n+5,0);
        vector<ll> A(n+5,0);
        for(int i=1;i<=n;i++){
            d1[i]=d1[i-1]+d2[i];
        }
        for(int i=1;i<=n;i++){
            A[i]=A[i-1]+d1[i];
            cout<<A[i]<<(i==n?"": " ");
        }
        cout<<'\n';
    }
    return 0;
}