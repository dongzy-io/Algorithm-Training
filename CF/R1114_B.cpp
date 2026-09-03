#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        bool has_found=false;
        int n,cnt=1;
        int diff=0;
        cin>>n;
        string s;
        cin>>s;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                cnt++;
            }
            if(!has_found&&i>0&&i<n-1&&s[i]!=s[i+1]&&s[i]!=s[i-1]){
                diff=1;
                if(s[i-1]==s[i+1]){
                    diff=2;
                    has_found=true;
                }
            }
        }
        cout<<cnt-diff<<'\n';
    }
    return 0;
}