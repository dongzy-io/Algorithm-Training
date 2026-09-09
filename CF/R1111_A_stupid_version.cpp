#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int positive=0,negative=0,last=0;
        int consecutive_positive=0,consecutive_negative=0;
        for(int i=0;i<n;i++){
            int x;;
            cin>>x;
            if(x==1){
                positive++;
                if(last==1){
                    last=0;
                    consecutive_positive++;
                }else
                    last=1;
            }else{
                negative++;
                if(last==-1){
                    last=0;
                    consecutive_negative++;
                }else
                    last=-1;
            }
        }
        if(n&1){
            cout<<"NO";
        }else{
            int diff=abs(positive-negative);
            if(diff%4!=0)
                cout<<"NO";
            else{
                if(positive>negative){
                    if(diff/4<consecutive_positive)
                        cout<<"YES";
                    else
                        cout<<"NO";
                }else if(negative>positive){
                    if(diff/4<consecutive_negative){
                        cout<<"YES";
                    }else{
                        cout<<"NO";
                    }
                }else
                    cout<<"YES";
            }
        }
        cout<<'\n';
    }
    return 0;
}