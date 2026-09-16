#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin>>x;
    if(x==2)
        cout<<1;
    else
        cout<<(x+1)%3;
    return 0;
}