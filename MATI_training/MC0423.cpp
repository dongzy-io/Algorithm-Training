#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        if(!(a&1)&&!(b&1))
            cout<<"YES";
        else if((a+b)&1)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }
    return 0;
}