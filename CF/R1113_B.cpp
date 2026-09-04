#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        vector<int> b(m);
        for(auto &x: a){
            cin>>x;
        }
        for(auto &x: b){
            cin>>x;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int j=0,lower=0,upper=0;
        for(int i=0;i<n;i++){
            if(lower!=m){
                if(a[i]<b[j]){
                    j++;
                    lower++;
                }
            }else if(upper!=m){
                if(a[i]>b[j]){
                    j++;
                    upper++;
                }
            }else{
                break;
            }
        }
        if(upper==m&&lower==m){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<'\n';
    }
    return 0;
}