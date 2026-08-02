#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin,s);
    int cnt=0;
    for(auto c: s){
        if(isupper(c))
            cnt++;
    }
    cout<<cnt;
    return 0;
}