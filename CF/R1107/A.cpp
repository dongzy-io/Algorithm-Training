#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        if(x%y==0)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }
    return 0;
}