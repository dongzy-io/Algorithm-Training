#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int cnt=0;
    for(auto c:s)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') 
            cnt++;
    }
    cout<<cnt;
    return 0;
}