#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,schrehold;
    cin>>n>>schrehold;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>schrehold)
            cout<<'x';
        else
            cout<<'o';
    }
    return 0;
}