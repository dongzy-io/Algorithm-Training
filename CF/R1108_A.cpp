#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            if(i&1)
                cout<<i+1<<" ";
            else
                cout<<i-1<<" ";
        }
        cout<<'\n';
    }
    return 0;
}