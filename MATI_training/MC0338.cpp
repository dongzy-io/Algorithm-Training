#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    bool isFirst=true;
    bool isZero=true;
    for(int i=n;i>=0;i--){
        int coef;
        cin>>coef;
        if(!coef)
            continue;
        isZero=false;
        if(i==0){
            if(isFirst){
                cout<<coef;
                isFirst=false;
            }
            else
                cout<<((coef>0)? "+": "")<<coef;
        }else if(i==1){
            if(isFirst){
                cout<<((coef<0)? "-": "")<<((labs(coef)==1)? "": to_string(labs(coef)))<<"x";
                isFirst=false;
            }else{
                cout<<((coef>0)? "+": "-")<<((labs(coef)==1)? "": to_string(labs(coef)))<<"x";
            }
        }else{
            if(isFirst){
                cout<<((coef<0)? "-": "")<<((labs(coef)==1)? "": to_string(labs(coef)))<<"x^"<<i;
                isFirst=false;
            }else{
                cout<<((coef>0)? "+": "-")<<((labs(coef)==1)? "": to_string(labs(coef)))<<"x^"<<i;
            }
        }
    }
    if(isZero)
        cout<<0;
    return 0;
}