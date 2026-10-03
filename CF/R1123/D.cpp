#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        bool available=true;
        int n;
        cin>>n;
        int even=1,odd=0;
        vector<int> pos(n+1);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            pos[x]=i;
        }            
        if(n&1)
            even++;
        else
            odd++;
        for(int i=1;i<=n;i++){
            if(pos[i]&1){
                if(odd){
                    odd--;
                    even++;
                }else{
                    available=false;
                    break;
                }
            }else{
                if(even){
                    even--;
                    odd++;
                }else{
                    available=false;
                    break;
                }
            }   
        }
        if(available)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }
    return 0;
}