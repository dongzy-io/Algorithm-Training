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
        if(n==2){
            cout<<-1<<'\n';
            continue;
        }
        if(n==1){
            cout<<1<<'\n';
            continue;
        }
        cout<<1<<" "<<2<<" "<<3<<" ";
        if(n==3){
            cout<<'\n';
            continue;
        }
        ll curr=3;
        for(int i=3;i<n;i++){
            cout<<curr*2<<" ";
            curr*=2;
        }
        cout<<'\n';
    }
    return 0;
}