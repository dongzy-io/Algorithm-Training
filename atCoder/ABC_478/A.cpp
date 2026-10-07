#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m%n;i++){
        cout<<m/n+1<<'\n';
    }
    for(int i=0;i<n-m%n;i++){
        cout<<m/n<<'\n';
    }
    return 0;
}