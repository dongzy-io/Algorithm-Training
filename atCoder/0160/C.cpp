#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,k,curr;
    cin>>n>>m>>k;
    curr=k;
    vector<ll> H(n);
    for(auto &x : H){
        cin>>x;
        x*=-1;
    }
    for(int i=0;i<m;i++){
        ll id,x;
        cin>>id>>x;
        id--;
        H[id]+=x;        
    }
    curr+=H[0];
    if(curr<0){
        cout<<-1;
        return 0;
    }else{
        int i=1;
        while(i<n){
            if(i<n-1){
                if(H[i]>=0){
                    curr+=H[i++];
                }else if(H[i+1]>=0){
                    curr+=H[i+1];
                    i+=2;
                }else{
                    if(H[i]>H[i+1]){
                        curr+=H[i++];
                    }else{
                        curr+=H[i+1];
                        i+=2;
                    }
                    if(curr<0){
                        cout<<-1;
                        return 0;
                    }
                }
            }else{
                curr+=H[n-1];
                if(curr<0){
                    cout<<-1;
                    return 0;
                }else{
                    cout<<curr;
                    return 0;
                }
            }
        }
        cout<<curr;
    }
    return 0;
}