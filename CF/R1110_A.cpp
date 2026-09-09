#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,k,ans=0;
        cin>>n>>k;
        string s;
        cin>>s;
        if(2*k>n){
            cout<<-1<<'\n';
            continue;
        }
        for(int i=0;i<k;i++){
            if(s[i]=='L')
                ans++;
            if(s[n-1-i]=='R')
                ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}