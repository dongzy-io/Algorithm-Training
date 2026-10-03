#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,ans=0;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i]){
                ans++;
                if(s[i]!=c&&s[n-1-i]!=c)
                    ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}