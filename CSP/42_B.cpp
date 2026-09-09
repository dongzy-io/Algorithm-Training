#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll total,rate,days;
    cin>>total>>rate>>days;
    int lower=0,upper=1e9,mid;
    while(lower<=upper){
        bool isUpper=true;
        mid=(lower+upper)/2;
        ll left=total;
        for(int i=0;i<days;i++){
            left-=(ceil)(left*rate/100.0)+mid;
            if(left<0){
                isUpper=false;
                break;
            }
        }
        if(!left){
            cout<<mid;
            return 0;
        }
        if(isUpper){
            lower=mid+1;
        }else{
            upper=mid-1;
        }
    }
    cout<<upper;
    return 0;
}