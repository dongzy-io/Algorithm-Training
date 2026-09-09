#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,ans=0,last=0;
    cin>>n>>m;
    while(n--){
        int curr=0;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            curr+=x;
        }
        if(curr<last)
            ans++;
        last=curr;
    }
    cout<<ans;
    return 0;
}