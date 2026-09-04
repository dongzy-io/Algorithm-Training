#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        bool delete_1=false,delete_0=false;
        for(auto c: s){
            if(c=='1'&&!delete_1){
                delete_1=true;
                continue;
            }else if(c=='0'&&!delete_0){
                delete_0=true;
                continue;
            }else{
                cout<<c;
            }
        }
        cout<<'\n';
    }
    return 0;
}