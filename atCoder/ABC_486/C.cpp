#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,ans=0;
    string s;
    cin>>n>>k>>s;
    for(int i=0;i<k;i++){
        bool isStarted=false;
        for(int j=i;j<n;j+=k){
            if(s[j]=='.'){
                if(isStarted){
                    isStarted=false;
                    ans++;
                }
            }else{
                isStarted=true;
            }
        }
        if(isStarted)
            ans++;
    }
    cout<<ans;
    return 0;
}