#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    bool has_a=false;
    vector<ll> a(n);
    vector<ll> b(n); 
    for(auto &x: a){
        cin>>x;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(a[i]>b[i])
            has_a=true;
    }
    if(!has_a)
        cout<<"No";
    else{
        cout<<"Yes"<<'\n';
        for(int i=0;i<n;i++){
            if(a[i]>b[i])
                cout<<(ll)1e18<<" ";
            else
                cout<<1<<" ";
        }
    }
}