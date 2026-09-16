#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll one=0,ten=0,hundred=0;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x%1000==0)
            continue;
        x=1000-x%1000;
        hundred+=x/100;
        x%=100;
        ten+=x/10;
        x%=10;
        one+=x;
    }
    cout<<one<<" "<<ten<<" "<<hundred;
    return 0;
}