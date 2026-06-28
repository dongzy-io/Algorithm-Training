//TLE
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        ll num;
        cin>>num;
        bool isAvailable=false;
        for(int i=0;i<1000000;i++){
            int b=i*12;
            int a=num-b;
            string s=to_string(a);
            bool isPAlindrome=true;
            for(int i=0;i<s.length()/2;i++){
                if(s[i]!=s[s.length()-1-i]){
                    isPAlindrome=false;
                    break;
                }
            }
            if(isPAlindrome){
                cout<<a<<" "<<b;
                isAvailable=true;
                break;
            }
        }
        if(!isAvailable)
            cout<<-1;
        cout<<'\n';
    }
    return 0;
}