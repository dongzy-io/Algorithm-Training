#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        bool isAvailable=false;
        int n,m,c;
        cin>>n>>m>>c;
        for(int i=0;i<=n;i++){
            for(int j=0;j<m;j++){
                int x=i*m+j*n-2*i*j;
                if(x==c)
                    isAvailable=true;
            }
        }
        if(isAvailable)
            cout<<"Yes";
        else    
            cout<<"No";
        cout<<'\n';
    }
    return 0;
}