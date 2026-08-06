#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,x;
        cin>>n>>x;
        double mid=(double)x/2.0;
        if(x>n+n-1||x<3){
            cout<<n<<'\n';
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
        }else{
            int r=mid+1;
            int l=mid-0.5;
            int ans=n-min(n-r+1,l);
            cout<<ans<<'\n';
            if(r-l==1){
                if((n-r+1)>l){
                    for(int i=r;i<=n;i++){
                        cout<<i<<" ";
                    }
                }else{
                    for(int i=1;i<=l;i++){
                        cout<<i<<" ";
                    }
                }
            }else{
                cout<<(int)mid<<" ";
                if((n-r+1)>l){
                    for(int i=r;i<=n;i++){
                        cout<<i<<" ";
                    }
                }else{
                    for(int i=1;i<=l;i++){
                        cout<<i<<" ";
                    }
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}