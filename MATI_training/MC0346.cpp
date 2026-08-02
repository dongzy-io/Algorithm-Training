#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ld a,b,k,sum=500;
    cin>>a>>b>>k; 
    sum+=7*a;
    sum+=0.9*b*1.2+2*1.44*b*1.2;
    sum+=5*b*(1.2*1.2*1.2*1.2+1.2*1.2*1.2*1.2*1.2+1.2*1.2*1.2*1.2*1.2*1.2+1.2*1.2*1.2*1.2*1.2*1.2*1.2);
    if(sum>=k)
        cout<<"You have slain an enemy";
    else
        cout<<"You have been slain";
}