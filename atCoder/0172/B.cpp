#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,max_num=0;
    cin>>n>>m;
    while(n--){
        string s;
        cin>>s;
        max_num=max(max_num,(int)count(s.begin(),s.end(),'x'));
    }
    cout<<max_num;
    return 0;
}