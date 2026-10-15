#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,min_num=1e9,ans;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<min_num){
            ans=i+1;
            min_num=x;
        }
    }
    cout<<ans;
    return 0;
}