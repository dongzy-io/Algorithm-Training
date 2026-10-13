#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sum=0;;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(!(i&1))
            sum+=x;
    }
    cout<<sum;
    return 0;
}