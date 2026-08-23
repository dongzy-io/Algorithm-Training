#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n&1){
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
    }else{
        for(int i=1;i<=n;i++){
            if(i&1)
                cout<<i+1<<" ";
            else
                cout<<i-1<<" ";
        }
    }
    return 0;
}