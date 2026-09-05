#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,even_min=numeric_limits<int>::max(),odd_max=-1;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(i&1)
                odd_max=max(odd_max,x);
            else
                even_min=min(even_min,x);
        }
        if(n&1){
            cout<<"NO"<<"\n";
            continue;
        }
        if(odd_max<even_min-1)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }
    return 0;
}