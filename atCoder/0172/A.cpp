#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    while(N--){
        int a,n;
        cin>>a>>n;
        cout<<((a+n)%24)<<'\n';
    }
    return 0;
}