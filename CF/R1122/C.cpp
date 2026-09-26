#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,cnt_1,cnt_0,ans=1000000000;
        cin>>n;
        string s;
        cin>>s;
        cnt_0=count(s.begin(),s.end(),'0');
        cnt_1=count(s.begin(),s.end(),'1');
        if(s[0]=='1'){
            cout<<cnt_0;
        }else{
            int curr_1=0,curr_0=0;
            for(auto c: s){
                ans=min(ans,curr_1+cnt_0-curr_0);
                if(c=='1')
                    curr_1++;
                else
                    curr_0++;
            }
            ans=min(ans,curr_1+cnt_0-curr_0);
            cout<<ans;
        }
        cout<<'\n';
    }
    return 0;
}