#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    int len=to_string(a).size();
    int base=1;
    for(int i=1;i<len;i++){
        base*=10;
    }
    bool isFetch=false;
    for(int i=0;i<len;i++){
        if(gcd(a,b)==1){
            cout<<i;
            isFetch=true;
            break;
        }
        string A=to_string(a), B=to_string(b);
        A=A.substr(1)+A[0];
        B=B.substr(1)+B[0];
        a=stoi(A);
        b=stoi(B);
    }
    if(!isFetch)
        cout<<-1;
    return 0;
}