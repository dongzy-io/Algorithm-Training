#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,duration,start,sum=0,ans=0;
    cin>>n>>duration>>start;
    vector<ll> volume(n);
    for(auto &x: volume){
        cin>>x;
        sum+=x;
    }
    if(duration<n-start+1){
        for(int i=0;i<duration;i++){
            ans+=volume[i+start-1];
        }
    }else{
        duration-=n-start+1;
        for(int i=start-1;i<n;i++)
            ans+=volume[i];
        ll round=duration/n;
        ans+=sum*round;
        ll left=duration%n;
        for(int i=0;i<left;i++){
            ans+=volume[i];
        }
    }
    cout<<ans;
    return 0;
}