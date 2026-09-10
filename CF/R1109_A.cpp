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
        string s;
        cin>>s;
        char last='*';
        int curr=0,max_len=0;
        for(auto c: s){
            if(c=='*')
                curr=0;
            else{
                curr++;
                max_len=max(curr,max_len);
            }
        }
        cout<<(max_len+1)/2<<'\n';
    }
    return 0;
}