#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll first,last;
    ll min_num=30,cnt=0;
    for(int i=0;i<n;i++){
        if((s[i]-'a')<min_num){
            min_num=s[i]-'a';
            first=i+1;
            last=i+1;
            cnt=1;
        }else if(s[i]-'a'==min_num){
            cnt++;
            last=i+1;
        }
    }
    ll sum1=0,sum2=0;
    sum1=first+n-cnt-1;
    sum2=n-last+1+n-cnt;
    cout<<min(sum1,sum2);
    return 0;
}