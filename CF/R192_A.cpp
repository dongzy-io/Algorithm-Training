#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int k;
        cin>>k;
        bool isAvailable=false;
        int cnt=0;
        for(int i=0;i<k;i++){
            int x;
            cin>>x;
            if(x==2)
                cnt++;
            if(cnt>1||x>2){
                isAvailable=true;
            }
        }
        if(isAvailable)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }
    return 0;
}