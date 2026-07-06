#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int x=1;
    for(auto c: s){
        if(c=='1')
            x++;
    }
    int curr=0;
    for(auto c: s){
        curr=(2*curr%x+c-'0')%x;
    }
    cout<<curr;
    return 0;
}
