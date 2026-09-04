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
        int cnt_1=0,cnt_0=0;
        //vector<bool> isDeleted(n,false);
        //vector<int> id;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                if(s[i]=='1')
                    cnt_1++;
                else
                    cnt_0++;
                //id.emplace_back(i);
            }
        }
        //vector<bool> isDeleted(n,false);
        int i=0,j=n-1;
        int diff=abs(cnt_1-cnt_0);
        int ans=cnt_1+cnt_0;
        if(diff<2){
            cout<<ans;
        }else if(diff>3){
            cout<<-1;
        }else{
            if(cnt_1-cnt_0>1){
                int cnt=0;
                if(s[i]=='0')
                    cnt++;
                if(s[n-1]=='0')
                    cnt++;
                if(cnt>=diff-1)
                    cout<<2*cnt_1-1;
                else
                    cout<<-1;
            }else{
                int cnt=0;
                if(s[i]=='1')
                    cnt++;
                if(s[n-1]=='1')
                    cnt++;
                if(cnt>=diff-1)
                    cout<<2*cnt_0-1;
                else
                    cout<<-1;
            }
        }
        cout<<'\n';
    }
    return 0;
}