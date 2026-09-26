#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        cout<<n-min({a,b,c})<<'\n';
    }
    return 0;
}