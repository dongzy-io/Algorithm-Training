#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ans=0;
    cin>>n;
    string source,pattern;
    cin>>source>>pattern;
    for(int i=0;i<n;i++){
        int curr=0;
        for(int j=0;j<n&&(i+j)<n;j++){
            if(source[i+j]==pattern[j])
                curr++;
        }
        ans=max(ans,curr);
    }
    cout<<ans;
    return 0;
}