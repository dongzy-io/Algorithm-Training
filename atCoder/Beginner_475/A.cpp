#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        cout<<s[i];
        if(i!=s.length()-1)
            cout<<'o';
    }
    return 0;
}