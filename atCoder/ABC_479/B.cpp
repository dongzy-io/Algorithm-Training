#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ans=0,curr=0;
    cin>>n;
    string s;
    cin>>s;
    for(auto c: s){
        if(c=='R'){
            curr++;
            ans=max(ans,curr);
        }else{
            curr=0;
        }
    }
    cout<<ans;
    return 0;
}