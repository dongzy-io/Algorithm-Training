#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    int cnt=0;
    while(a!=b){
        if(a>b){
            cnt+=a-b;
            break;
        }else{
            if(a==b/2){
                cnt++;
                break;
            }else if(a>b/2){
                cnt+=min(b-a,a-(b+1)/2+2);
                break;
            }else{
                if(b&1){
                    b=(b-1)/2;
                    cnt+=2;
                }else{
                    b/=2;
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}