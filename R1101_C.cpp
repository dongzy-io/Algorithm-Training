//WA on 8th test
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,table,seat;
        cin>>n>>table>>seat;
        string demands;
        cin>>demands;
        int volume=table*seat;
        int occupied=0,extr_volume=0;
        int available_A=0;
        int ans=0;
        for(auto c: demands){
            if(ans==volume){
                break;
            }
            if(c=='E'){
                if(extr_volume>0){
                    extr_volume--;
                    ans++;
                }else{
                    if(occupied<table&&available_A>0){
                        available_A--;
                        extr_volume=seat-2;
                        ans+=2;
                        occupied++;
                    }
                }
                continue;
            }
            if(c=='I'){
                if(occupied<table&&available_A+occupied*seat-extr_volume<=volume-seat){
                    ans++;
                    occupied++;
                    extr_volume+=seat-1;
                }
                continue;
            }
            if(c=='A'){
                if(extr_volume==0){
                    occupied++;
                    ans++;
                    extr_volume=seat-1;
                }else
                    available_A++;
                continue;
            }
        }
        if(ans<volume)
            ans=min(volume,ans+available_A);
        cout<<ans<<'\n';
    }
    return 0;
}