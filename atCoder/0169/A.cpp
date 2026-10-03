#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,s,curr=0,ans=0;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(curr<s)
            curr+=x;
        else{
            ans++;
            curr=x;
        }
    }
    cout<<ans+(curr>=s);
    return 0;
}