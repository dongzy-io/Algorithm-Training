#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        bool has_1=false,has_both_0=false;
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &x: a){
            cin>>x;
            if(x)
                has_1=true;
        }
        for(auto &x: b){
            cin>>x;
        }
        int sum=0;
        bool isDifferent=false;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                sum+=a[i];
                isDifferent=true;
            }
            if(a[i]==0&&b[i]==0)
                has_both_0=true;
        }
        if(!isDifferent)
            cout<<0;
        else if(!sum){
            if(has_1&&has_both_0)
                cout<<2;
            else
                cout<<-1;
        }else if(sum&1)
            cout<<1;
        else
            cout<<2;
        cout<<'\n';
    }
    return 0;
}