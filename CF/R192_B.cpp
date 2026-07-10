#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        bool isAvailable=false;
        int n,level=1,A=0,B=0;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(isAvailable)
                continue;
            if(level==1){
                if(A-B==1){
                    level++;
                    if(x==3){
                        A=B=0;
                        continue;
                    }else{
                        A=1;
                        B=0;
                    }
                }
                if(x==1)
                    A++;
                else
                    B++;
            }else if(level==2){
                if(x<3)
                    A++;
                else
                    B++;
            }else{
                A++;
            }
            if(level>1&&A>=B){
                level++;
                A=B=0;
            }
            if(level==1&&A==B){
                level++;
                A=B=0;
            }
            if(level==4)
                isAvailable=true;
        }
        if(isAvailable)
            cout<<"YES";
        else    
            cout<<"NO";
        cout<<'\n';
    }
    return 0;
}