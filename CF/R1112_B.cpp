#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        if(n-2<k)
            cout<<-1;
        else{
            string ans="";
            if(n&1){
                if(k&1){
                    int m=(k+1)/2;
                    ans+=string(m+1,'1')+string(m,'0');
                    for(int i=0;i<(n-2*m-1)/2;i++){
                        ans+="10";
                    }
                }else{
                    int m=(k+2)/2;
                    ans+=string(m,'1')+string(m,'0');
                    for(int i=0;i<(n-2*m-1)/2;i++){
                        ans+="10";
                    }
                    ans+='1';
                }
            }else{
                if(k&1){
                    int m=(k+1)/2;
                    ans+='0';
                    for(int i=0;i<(n-2*m-2)/2;i++){
                        ans+="10";
                    }
                    ans+=string(m+1,'1')+string(m,'0');
                }else{
                    int m=(k+2)/2;
                    ans+=string(m,'1')+string(m,'0');
                    for(int i=0;i<(n-2*m)/2;i++){
                        ans+="10";
                    }
                }
            }
            cout<<ans;
        }
        cout<<'\n';
    }
    return 0;
}