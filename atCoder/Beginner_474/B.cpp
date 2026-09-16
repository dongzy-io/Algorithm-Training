#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool isValid=true;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>(i/10+1)*10)
            isValid=false;
    }
    if(isValid)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}