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
        int n,min_num=1e9;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            min_num=min(min_num,x);
        }
        if(min_num<n){
            cout<<n;
        }else{
            cout<<0;
        }
        cout<<'\n';
    }
    return 0;
}