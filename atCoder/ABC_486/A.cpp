#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin>>n>>s;
    for(auto c: s){
        if(c=='A')
            cout<<"Alpha"<<" ";
        if(c=='B')
            cout<<"Bravo"<<" ";
        if(c=='C')
            cout<<"Charlie"<<" ";
    }
    return 0;
}