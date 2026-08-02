#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        ll sum=(n+1)*n/2;
        string s;
        cin>>s;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])
                sum-=i+1;
        }
        cout<<sum<<'\n';
    }
    return 0;
}